#ifndef STSTYLE_H
#define STSTYLE_H

#include <QString>
#include <QColor>

struct STStyle
{
    enum FontStyleFlag : char
    {
      bBold = 1,
      bItalic = 1 << 1,
      bUnderline = 1 << 2,
      bStrikethrough = 1 << 3
    };

    enum TextAlignmentFlag : char
    {
      Left = 1,
      Center = 2,
      Right = 3,
      bTop = 4,
      bMiddle = 8
    };

    enum BorderStyleFlag : char
    {
      OutlineShadow = 1,
      OpaqueBox = 3
    };

    QString FontFamily;
    double FontSize;
    QColor PrimaryColor, SecondaryColor, OutlineColor, BackColor;
    char FontStyle, TextAlignment, BorderStyle;

    char Outline, Shadow;
    double ScaleX, ScaleY, Spacing, Angle;
    double MarginL, MarginR, MarginV, Alpha;
};

#endif // STSTYLE_H
