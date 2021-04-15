#ifndef HOST_H
#define HOST_H

#include <QObject>
#include "STDialog.h"
#include "STTrack.h"
#include "app/commander.h"

class SubtilesHost final : public QObject
{
  Q_OBJECT
  public:
    SubtilesHost();
    ~SubtilesHost(){};

  private:
    // Internal subtitle data for this host
    QHash<uint, STDialogPtr> m_dialogs;
    std::list<STTrackPtr> m_tracks; // Tracks are ordered, use a linked list for O(1) reordering
    SubtilesCommander m_cmd;

};

#endif // HOST_H
