//
// Created by rigoligo on 2021/5/7.
//

#ifndef _STSNAPTREE_H_
#define _STSNAPTREE_H_

#include <map>
#include <tuple>
#include "STTimecode.h"
#include "STDialog.h"

/**
 * @brief STSnapTree is a tree structure used to provide tile snapping functions.
 *        For example when you're moving or dragging one end of a tile clip, you may want to snap
 *        one end onto another tile's end. This is what snap tree provides you.
 *
 *        When talking about the snap tree's internal functions, you must be aware that it can
 *        return error codes, which provides you with simple error checking functions. That error
 *        check will prevent you from creating a tile begins inside another tile, deleting a
 *        non-existant tile from the tree, and nothing more. If you'd create a tile beginning in an
 *        empty area but its end collides with other tiles, then the tree is unaware of it.
 */
class STSnapTree
{
  public:
    enum OperationResult
    {
      Success = 0,
      InsideTile,
      OnTileEdge,
      Fail = 128,
      FailEmpty,
      FailOccupied,
      FailNotFound
    };
    typedef std::tuple<OperationResult, STTime> SnapResult;

    OperationResult InsertTile(const STDialogCPtr& dialog);
    OperationResult DeleteTile(STTime at);
    SnapResult Snap(STTime at);
    SnapResult SnapHead(STTime at);
    SnapResult SnapTail(STTime at);
    STSnapTree::OperationResult IsInsideTile(STTime at);

    std::map<STTime, STDialogCPtr>::iterator Find(STTime at);

  private:
    std::map<STTime, STDialogCPtr> m_InternalTree;
    static STTime Closest (STTime at, STTime a1, STTime a2);
    static STTime Closest (STTime at, STTime a1, STTime a2, STTime a3, STTime a4);
};

#endif //_STSNAPTREE_H_
