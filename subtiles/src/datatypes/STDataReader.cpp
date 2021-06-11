#include <QHash>
#include "STDialog.h"
#include "STDataReader.h"

QHash<uint, STDialogPtr> *STDataReader::m_dialogs = nullptr;
std::list<STTrackPtr> *STDataReader::m_tracks = nullptr;

STDataReader::STDataReader()
{
    Q_ASSERT(m_host != nullptr);
}

STDialogCPtr STDataReader::GetReadDialog(uint aDlgId)
{
  return (*m_dialogs)[aDlgId];
}

size_t STDataReader::GetDialogCount()
{
  return m_dialogs->size();
}

std::list<STTrackPtr>::const_iterator STDataReader::GetReadTrackCBegin()
{
  return (*m_tracks).cbegin();
}

std::list<STTrackPtr>::const_iterator STDataReader::GetReadTrackCEnd()
{
  return (*m_tracks).cend();
}
