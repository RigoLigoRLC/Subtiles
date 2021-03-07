#ifndef STTIMECODE_H
#define STTIMECODE_H

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
    STTimecode();
    STTimecode(const QString&);
    STTimecode(const double s);
    STTimecode(const unsigned long s, const int fr);
    STTimecode(const unsigned long s, const double fr);
    STTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const int fr);
    STTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const double fr);

    QString GetASSTimecode() const;
    bool SetTimecode(const QString&);
    bool SetTimecode(const double s);
    bool SetTimecode(const unsigned long s, const int fr);
    bool SetTimecode(const unsigned long s, const double fr);
    bool SetTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const int fr);
    bool SetTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const double fr);

    STTimecode operator+(const STTimecode &op);
    STTimecode operator-(const STTimecode &op);
    STTimecode operator*(const double op);
    STTimecode operator/(const double op);
    bool operator==(const STTimecode &op);

    unsigned long ToFrame(const double aFps);

    static bool IsValidTimecode(const QString&);
};

#endif // STTIMECODE_H
