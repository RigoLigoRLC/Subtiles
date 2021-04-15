#include "app/host.h"

SubtilesHost::SubtilesHost() :
  m_dialogs(), m_tracks(), // Explicitly instantiate data structures first, IDK if it's needed
  m_cmd(m_dialogs, m_tracks) // Instantiate Commander
{

}
