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
  // TODO: figure out what to do with living MainWindows and Guests
  delete m_host;
}

