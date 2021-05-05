#ifndef STTRACK_H
#define STTRACK_H

#include <memory>
#include "STStyle.h"

class STTrack
{
  public:
    STTrack();
  private:
    //STRBTree<STTime, STDialogPtr> m_snapTree;
    STStyle m_trackStyle;

};

using STTrackPtr = std::shared_ptr<STTrack>;
using STTrackCPtr = std::shared_ptr<const STTrack>;

#endif // STTRACK_H
