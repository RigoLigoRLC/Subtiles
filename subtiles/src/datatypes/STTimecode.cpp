
#include <QStringList>
#include <QtMath>

#include "STTimecode.h"

STTimecode::STTimecode()
{
  m_second = 0;
  m_fraction = 0.0;
}

STTimecode::STTimecode(const QString &s)
{
  if(!SetTimecode(s))
    STTimecode();
}

STTimecode::STTimecode(const double s)
{
  if(!SetTimecode(s))
    STTimecode();
}

STTimecode::STTimecode(const unsigned long s, const int fr)
{
  if(!SetTimecode(s, fr))
    STTimecode();
}

STTimecode::STTimecode(const unsigned long s, const double fr)
{
  if(!SetTimecode(s, fr))
    STTimecode();
}

STTimecode::STTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const int fr)
{
  if(!SetTimecode(h, m, s, fr))
    STTimecode();
}

STTimecode::STTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const double fr)
{
  if(!SetTimecode(h, m, s, fr))
    STTimecode();
}

QString STTimecode::GetASSTimecode() const
{
  return QString("%1:%2:%3.%4")
      .arg(m_second / 3600, 2, 10, QChar('0'))
      .arg(m_second % 3600 / 60, 2, 10, QChar('0'))
      .arg(m_second % 60, 2, 10, QChar('0'))
      .arg(static_cast<long>(m_fraction * 10000), 4, 10, QChar('0'));
}

bool STTimecode::SetTimecode(const QString &aTimecode)
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

bool STTimecode::SetTimecode(const double s)
{
  if(s < 0)
  {
    return false;
  }
  m_second = s;
  m_fraction = fmod(s, 1);
  return true;
}

bool STTimecode::SetTimecode(const unsigned long s, const int fr)
{
  if(fr >= 10000 || fr < 0)
  {
    return false;
  }
  m_second = s;
  m_fraction = static_cast<double>(fr) / 10000;
  return true;
}

bool STTimecode::SetTimecode(const unsigned long s, const double fr)
{
  if(fr >= 1 || fr < 0)
  {
    return false;
  }
  m_second = s;
  m_fraction = fr;
  return true;
}

bool STTimecode::SetTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const int fr)
{
  if(fr >= 10000 || fr < 0)
  {
    return false;
  }
  m_second = h * 3600 +
             m * 60 +
             s;
  m_fraction = static_cast<double>(fr) / 10000;
  return true;
}

bool STTimecode::SetTimecode(const unsigned long h, const unsigned long m, const unsigned long s, const double fr)
{
  if(fr >= 1 || fr < 0)
  {
    return false;
  }
  m_second = h * 3600 +
             m * 60 +
             s;
  m_fraction = fr;
  return true;
}

STTimecode STTimecode::operator+(const STTimecode &op)
{
  STTimecode ret;
  double remainder = fmod(op.m_fraction + this->m_fraction, 1);
  ret.SetTimecode(op.m_second + op.m_fraction + this->m_fraction + this->m_second, remainder);
  return ret;
}

STTimecode STTimecode::operator-(const STTimecode &op)
{
  STTimecode ret;
  double excess = this->m_fraction - op.m_fraction;
  if(excess >= 0)
    ret.SetTimecode(this->m_second - op.m_second, excess);
  else
    ret.SetTimecode(this->m_second - op.m_second - 1, 1 - excess);
  return ret;
}

STTimecode STTimecode::operator*(const double op)
{
  STTimecode ret;
  if(op < 0)
  {
    return ret;
  }
  ret.SetTimecode((static_cast<double>(this->m_second) + this->m_fraction) * op);
  return ret;
}

STTimecode STTimecode::operator/(const double op)
{
  STTimecode ret;
  ret.SetTimecode((static_cast<double>(this->m_second) + this->m_fraction) / op);
  return ret;
}

bool STTimecode::operator==(const STTimecode &op)
{
  return this->m_second == op.m_second && qFuzzyCompare(this->m_fraction, op.m_fraction);
}

unsigned long STTimecode::ToFrame(const double aFps)
{
  return qRound((m_second + m_fraction) / aFps);
}


bool STTimecode::IsValidTimecode(const QString &aTimecode)
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
