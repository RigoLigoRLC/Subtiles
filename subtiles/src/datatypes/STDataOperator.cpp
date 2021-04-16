#include "STDataOperator.h"
#include "app/host.h"
#include "app/mainframe.h"

std::list<STTrackPtr> &STDataOperator::GetTracks()
{
  return m_host->m_tracks;
}

QHash<uint, STDialogPtr> &STDataOperator::GetDialogs()
{
  return m_host->m_dialogs;
}
