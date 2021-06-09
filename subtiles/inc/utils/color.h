#ifndef COLOR_H
#define COLOR_H

#include <QColor>

namespace STUtil
{
  // From 78th trick of https://gitee.com/feiyangqingyun/qtkaifajingyan/
  /**
   * @brief BWBackground returns black or white for objects based on the background it is above
   * @param color Background color
   * @return black or white
   */
  QColor BWBackground(QColor color)
  {
    return ((0.299 * color.red() + 0.587 * color.green() + 0.114 * color.blue()) / 255 )> 0.5 ?
          Qt::black : Qt::white;
  }


}


#endif // COLOR_H
