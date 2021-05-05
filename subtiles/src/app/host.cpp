#include "app/host.h"
#include "STDataReader.h"

SubtilesHost *STDataOperator::m_host = nullptr; ///< Initialize with nullptr

SubtilesHost::SubtilesHost() :
  m_dialogs(), m_tracks(), // Explicitly instantiate data structures first
  m_cmd(m_dialogs, m_tracks) // Instantiate Commander
{
  // Provide interface for unsafe data operators
  Q_ASSERT(STDataOperator::m_host == nullptr); // Ensure single instance
  STDataOperator::m_host = this;
  // Provide interface for safe data readers
  STDataReader::m_tracks = &m_tracks;
  STDataReader::m_dialogs = &m_dialogs;
}
