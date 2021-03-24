#include "app/mainframe.h"
#include "guests/uistyleshow.h"

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
  int firstWindowID = CreateMainWindow(); // First main window for the app
  auto window = m_windows[firstWindowID];

  // Populate dock widgets (guests)
  {
    m_guests.push_back(new STGuestUiStyleShow("UI Style Show", window));
  }
  
  foreach(auto &i, m_guests)
    window->AddDockWidget(ads::TopDockWidgetArea, i);

}

SubtilesMainFrame::~SubtilesMainFrame()
{
  // When mainframe is destroyed, the application is effectively quitting.
  // No need to worry about data safety while painting; just delete them all.
  for(auto i : m_windows)
    i->deleteLater(); // Guests will be destoryed along with the window
  m_host->deleteLater();
}
