#ifndef SUBTILESCOMMANDER_H
#define SUBTILESCOMMANDER_H

#include <QObject>
#include <list>
#include <QHash>
#include <QSharedPointer>
#include <QUndoStack>
#include "STTrack.h"
#include "STDialog.h"

class SubtilesCommander : public QObject
{
    Q_OBJECT

  public:
    SubtilesCommander(QHash<uint, STDialogPtr> &, std::list<STTrackPtr> &);

  private:
    // References
    QHash<uint, STDialogPtr> &m_dialogs;
    std::list<STTrackPtr> &m_tracks;
};

#endif // SUBTILESCOMMANDER_H
