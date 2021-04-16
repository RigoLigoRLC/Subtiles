#ifndef HOST_H
#define HOST_H

#include <QObject>
#include "STDialog.h"
#include "STTrack.h"
#include "STDataOperator.h"
#include "app/commander.h"
#include "app/command.h"

// Host *MUST* be single instance in one application.
/**
 * @brief SubtilesHost class hosts everything in a Subtiles instance. It's
 *        designed to be a monolithic monster, contains all the data of this
 *        session and a commander that should be the only guy modifying data.
 *        Any data modification must be done by commander: you signal commander
 *        and it creates a command which does the data modification for you.
 *        See inc/app/command.h and src/app/command.cpp for implementation.
 *        One should use signals starting with MsgNotify to notify Guests about
 *        the changes of data.
 */

class SubtilesHost final : public QObject
{
    Q_OBJECT

    friend class STDataOperator;

  public:
    SubtilesHost();
    ~SubtilesHost(){};

    friend std::list<STTrackPtr> &STDataOperator::GetTracks();
    friend QHash<uint, STDialogPtr> &STDataOperator::GetDialogs();

  private:
    // Internal subtitle data for this host
    QHash<uint, STDialogPtr> m_dialogs;
    std::list<STTrackPtr> m_tracks; // Tracks are ordered, use a linked list
                                    // for O(1) reordering
    SubtilesCommander m_cmd;

  signals:
    void MsgNotifyRefreshTracks();

};

#endif // HOST_H
