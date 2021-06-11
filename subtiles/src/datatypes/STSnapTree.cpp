//
// Created by rigoligo on 2021/5/7.
//

#include "STSnapTree.h"
#include "utils/convenience.h"

using std::get;
using std::prev;
using std::next;

STSnapTree::OperationResult STSnapTree::InsertTile(const STDialogCPtr& dialog)
{
  if(!m_InternalTree.count(dialog->Begin))
  {
    if(IsInsideTile(dialog->Begin) != InsideTile &&
       IsInsideTile(dialog->Begin + dialog->Duration) != InsideTile)
    {
      m_InternalTree.emplace(dialog->Begin, dialog);
      return Success;
    }
    else
      return FailOccupied;
  }
  else
    return FailOccupied;
}

STSnapTree::OperationResult STSnapTree::DeleteTile(const STTime at)
{
  if(m_InternalTree.count(at))
  {
    m_InternalTree.erase(at);
    return Success;
  }
  else
    return FailNotFound;
}

STSnapTree::SnapResult STSnapTree::Snap(const STTime at)
{
  if(m_InternalTree.empty())
  {
    return { FailEmpty, 0 };
  }

  static auto resultPoint = Find(at);

  if(m_InternalTree.size() == 1 || resultPoint == prev(m_InternalTree.end()))
  {
    return {
      Success,
      Closest(at,
              resultPoint->first + resultPoint->second->Duration,
              resultPoint->first)
    };
  }

  static auto pointAfter = next(COPY(resultPoint));

  return { Success,
           Closest(at,
                   resultPoint->first,
                   resultPoint->first + resultPoint->second->Duration,
                   pointAfter->first,
                   pointAfter->first + pointAfter->second->Duration)
         };
}

STSnapTree::SnapResult STSnapTree::SnapHead(const STTime at)
{
  if(m_InternalTree.empty())
  {
    return { FailEmpty, 0 };
  }

  auto resultPoint = Find(at);
  if(resultPoint == m_InternalTree.end())
  {
    return { FailNotFound, 0 };
  }

  auto pointBefore = prev(COPY(resultPoint)),
       pointAfter = next(COPY(resultPoint)),
       pointLast = prev(m_InternalTree.end());

  if((at >= resultPoint->first && at <= resultPoint->first + resultPoint->second->Duration) ||
     (at <= pointBefore->first + pointBefore->second->Duration))
  {
    if(resultPoint == pointLast)
      return { InsideTile, resultPoint->first };
    else
      return { InsideTile, Closest(at, resultPoint->first, pointAfter->first) };
  }
  else
    return { Success, Closest(at, resultPoint->first, pointAfter->first) };
}

STSnapTree::SnapResult STSnapTree::SnapTail(const STTime at)
{
  if(m_InternalTree.empty())
  {
    return { FailEmpty, 0 };
  }

  auto resultPoint = Find(at),
              pointBefore = prev(COPY(resultPoint)),
              pointAfter = next(COPY(resultPoint)),
              pointFirst = m_InternalTree.begin();

  if((at >= resultPoint->first && at <= resultPoint->first + resultPoint->second->Duration) ||
     (at <= pointBefore->first + pointBefore->second->Duration))
  {
    if(resultPoint == pointFirst)
      return { InsideTile, resultPoint->first + resultPoint->second->Duration };
    else
      return { InsideTile, Closest(at, resultPoint->first + resultPoint->second->Duration,
                                              pointBefore->first + pointBefore->second->Duration) };
  }
  else
    return { Success, Closest(at, resultPoint->first + resultPoint->second->Duration,
                                 pointBefore->first + pointBefore->second->Duration) };
}

STTime STSnapTree::Closest(const STTime at, const STTime a1, const STTime a2)
{
  return llabs(a1 - at) >= llabs(a2 - at) ? a2 : a1;
}

STTime STSnapTree::Closest(const STTime at, const STTime a1, const STTime a2,
                           const STTime a3, const STTime a4)
{
  STTime result = a1,
                d1 = llabs(a1 - at),
                d2 = llabs(a2 - at),
                d3 = llabs(a3 - at),
                d4 = llabs(a4 - at),
                d = d1;
  if(d >= d2) result = a2, d = d2;
  if(d >= d3) result = a3, d = d3;
  if(d >= d4) result = a4;
  return result;
}

std::map<STTime, STDialogCPtr>::iterator STSnapTree::Find(STTime at)
{
  if(m_InternalTree.empty())
    return m_InternalTree.end();
  auto result = m_InternalTree.lower_bound(at),
       before = prev(COPY(result));
  if(before == m_InternalTree.end())
    return result;
  if(result == m_InternalTree.end())
    return before;
  return llabs(result->first - at) >= llabs(before->first - at) ? before : result;
}

STSnapTree::OperationResult STSnapTree::IsInsideTile(STTime at)
{
  if(m_InternalTree.empty())
  {
    return FailEmpty;
  }

  auto resultPoint = Find(at),
    pointBefore = prev(COPY(resultPoint)),
    pointFirst = m_InternalTree.begin();

  if(pointBefore == m_InternalTree.end())
  {
    if (at > resultPoint->first && at < resultPoint->first + resultPoint->second->Duration)
      return InsideTile;
    else
      return Success;
  }

  if((at > resultPoint->first && at < resultPoint->first + resultPoint->second->Duration) ||
     (at < pointBefore->first + pointBefore->second->Duration))
    return InsideTile;
  else
    return Success;
}
