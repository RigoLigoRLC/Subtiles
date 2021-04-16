#include "app/command.h"
#include "app/host.h"
#include "utils/convenience.h"

STCInsertTrack::STCInsertTrack(std::list<STTrackPtr>::iterator aInsertPos,
                               STTrackPtr aTargetTrack, QUndoCommand *parent) :
  QUndoCommand(parent)
{
  GetTracks().insert(aInsertPos, aTargetTrack);
  m_targetTrack = aTargetTrack;
  m_itInsertPos = aInsertPos;
  m_itTargetTrack = COPY(aInsertPos)--;
  emit m_host->MsgNotifyRefreshTracks();
}

void STCInsertTrack::undo()
{
  GetTracks().erase(m_itTargetTrack);
  emit m_host->MsgNotifyRefreshTracks();
}

void STCInsertTrack::redo()
{
  GetTracks().insert(m_itInsertPos, m_targetTrack);
  m_itTargetTrack = COPY(m_itInsertPos)--; // Update iterator
  emit m_host->MsgNotifyRefreshTracks();
}
