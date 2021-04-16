
#include <QStringList>
#include <QtMath>

#include "STTimecode.h"

QString STData::GetAssTimecode(const STTime t)
{
  return QString("%1:%2:%3.%4")
      .arg(t / 3600000, 2, 10, QChar('0'))
      .arg(t % 3600000 / 60000, 2, 10, QChar('0'))
      .arg(t % 60000, 2, 10, QChar('0'))
      .arg(t % 1000, 4, 10, QChar('0'));
}

STTime STData::TimeFromAssTimecode(const QString &aTimecode)
{
  QStringList argList = aTimecode.split(QRegExp("[\\.:]"));
  if(argList.size() != 4)
  {
    return 0;
  }

  // Verify if is a valid timecode
  QList<unsigned long> timecodeParts;
  bool valid;
  foreach(auto &i, argList)
  {
    timecodeParts.append(i.toULong(&valid));
    if(!valid)
    {
      return 0;
    }
  }
  if(timecodeParts[3] >= 10000)
  {
    return 0;
  }

  return timecodeParts[0] * 3600000 +
         timecodeParts[1] * 60000 +
         timecodeParts[2] * 1000 +
         timecodeParts[3];
}

STTime STData::TimeFromSeconds(const double s)
{
  if(s < 0 || s > static_cast<double>(ULONG_LONG_MAX))
  {
    return 0;
  }
  return static_cast<STTime>(s * 1000);
}

STTime STData::TimeFromTime(const unsigned int h, const unsigned int m,
                            const unsigned int s, const unsigned int fr)
{
  if(fr >= 10000)
  {
    return false;
  }
  return h * 3600000 +
         m * 60000 +
         s * 1000 +
         fr;
}

bool STData::VerifyTimecode(const QString &aTimecode)
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
