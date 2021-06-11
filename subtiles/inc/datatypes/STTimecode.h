#ifndef STTIMECODE_H
#define STTIMECODE_H

#include <QString>

using STTime = long long; ///< Time in milliseconds

namespace STData
{
  QString GetAssTimecode(STTime);
  STTime TimeFromAssTimecode(const QString &);
  STTime TimeFromSeconds(double);
  STTime TimeFromTime(unsigned int, unsigned int, unsigned int, unsigned int);
  bool VerifyTimecode(const QString &);
}

#endif // STTIMECODE_H
