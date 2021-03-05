#ifndef STBASICTYPES_H
#define STBASICTYPES_H

#include <QString>

/**
 * @brief Subtiles timecode class. This class focuses on time, eveything is stored in seconds.
 */
class STTimecode final
{
  private:
    unsigned long m_second;
    double m_fraction; //< A fraction of a second in addition to m_second. Should between 0 and 1.
  public:
    QString GetASSTimecode() const;
    bool SetASSTimecode(const QString&);
    bool SetTimecode(const unsigned long s, const int fr);
    bool SetTimecode(const unsigned long s, const double fr);
    bool SetTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const int fr);
    bool SetTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const double fr);

    static bool VerifyASSTimecode(const QString&);
};

#endif // STBASICTYPES_H
