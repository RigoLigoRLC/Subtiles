#include "app/subtilesmainframe.h"

uint SubtilesMainFrame::CreateMainWindow()
{
  Q_ASSERT(m_mwidTop < UINT32_MAX); // This would not happen to a normal user :p
  SubtilesMainWindow *window = new SubtilesMainWindow(m_mwidTop, nullptr);
  m_windows[m_mwidTop] = window;
  connect(window, &SubtilesMainWindow::sigWindowClosed, this, &SubtilesMainFrame::evtMainWindowDestroyed);
  window->show();
  return m_mwidTop++;
}

void SubtilesMainFrame::evtMainWindowDestroyed(uint aWho)
{
  m_windows[aWho]->deleteLater();
  m_windows[aWho] = nullptr;
}

SubtilesMainFrame::SubtilesMainFrame()
{
  // Initialize internals
  m_mwidTop = 0;

  // Initialize application
  CreateMainWindow(); // First main window for the app
}

SubtilesMainFrame::~SubtilesMainFrame()
{
  // When mainframe is destroyed, the application is effectively quitting.
  // No need to worry about data safety while painting; just delete them all.
  for(auto i : m_windows)
    delete i;
  for(auto i : m_guests)
    delete i;
  delete m_host;
}

