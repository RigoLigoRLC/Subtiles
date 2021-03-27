#ifndef STTIMECODE_H
#define STTIMECODE_H

#include <QString>

using STTime = unsigned long long; ///< Time in milliseconds

namespace STData
{
  QString GetAssTimecode(const STTime);
  STTime TimeFromAssTimecode(const QString &);
  STTime TimeFromSeconds(const double);
  STTime TimeFromTime(const unsigned int, const unsigned int, const unsigned int, const unsigned int);
  bool VerifyTimecode(const QString &);
}

#endif // STTIMECODE_H
