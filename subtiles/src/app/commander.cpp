#include "app/commander.h"

SubtilesCommander::SubtilesCommander(QHash<uint, STDialogPtr> &aDialogs,
                                     std::list<STTrackPtr> &aTracks) :
  m_dialogs(aDialogs), m_tracks(aTracks)
{

}