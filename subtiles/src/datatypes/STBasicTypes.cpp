
#include <QStringList>

#include "STBasicTypes.h"

QString STTimecode::GetASSTimecode() const
{
  return QString("%1:%2:%3.%4")
      .arg(m_second / 3600)
      .arg(m_second % 3600 / 60)
      .arg(m_second % 60)
      .arg(static_cast<long>(m_fraction * 1000));
}

bool STTimecode::SetASSTimecode(const QString &aTimecode)
{
  QStringList argList = aTimecode.split(QRegExp("[\\.:]"));
  if(argList.size() != 4)
  {
    return false;
  }

  // Verify if is a valid timecode
  QList<unsigned long> timecodeParts;
  bool valid;
  foreach(auto &i, argList)
  {
    timecodeParts.append(i.toULong(&valid));
    if(!valid)
    {
      return false;
    }
  }
  if(timecodeParts[3] >= 10000)
  {
    return false;
  }

  m_second = timecodeParts[0] * 3600 +
             timecodeParts[1] * 60 +
             timecodeParts[2];
  m_fraction = static_cast<double>(timecodeParts[3]) / 1000;
  return true;
}

bool STTimecode::SetTimecode(const unsigned long s, const int fr)
{
  if(fr >= 10000)
  {
    return false;
  }
  m_second = s;
  m_fraction = static_cast<double>(fr) / 1000;
  return true;
}

bool STTimecode::SetTimecode(const unsigned long s, const double fr)
{
  if(fr >= 1)
  {
    return false;
  }
  m_second = s;
  m_fraction = fr;
  return true;
}

bool STTimecode::SetTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const int fr)
{
  if(fr >= 10000)
  {
    return false;
  }
  m_second = h * 3600 +
             m * 60 +
             s;
  m_fraction = static_cast<double>(fr) / 1000;
  return true;
}

bool STTimecode::SetTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const double fr)
{
  if(fr >= 1)
  {
    return false;
  }
  m_second = h * 3600 +
             m * 60 +
             s;
  m_fraction = fr;
  return true;
}

bool STTimecode::VerifyASSTimecode(const QString &aTimecode)
{
  QStringList argList = aTimecode.split(QRegExp("[\\.:]"));
  if(argList.size() != 4)
  {
    return false;
  }

  // Verify if is a valid timecode
  bool valid;
  for(int i = 0; i < 3; i++)
  {
    argList[i].toULong(&valid);
    if(!valid)
    {
      return false;
    }
  }
  if(argList[3].toULong(&valid) >= 10000 || !valid)
  {
    return false;
  }
  return true;
}
