#ifndef STDATAOPERATOR_H
#define STDATAOPERATOR_H

#include <QtGlobal>
#include "STTrack.h"
#include "STDialog.h"

class SubtilesHost;
class SubtilesMainFrame;

/**
 * @brief STDataOperator is NOT meant to be constructed; only meant to be
 *        inherited by other classes. If a class is an STDataOperator, it will
 *        gain access to the Host and MainFrame instance, and Tracks, Dialogs
 *        getters, thus being enabled to manipulate data.
 */
class STDataOperator
{

    friend class SubtilesHost;
    friend class SubtilesMainFrame;

  protected:
    static SubtilesHost *m_host;
    static SubtilesMainFrame *m_frame;
    std::list<STTrackPtr> &GetTracks();
    QHash<uint, STDialogPtr> &GetDialogs();


  public:
    //STDataOperator() = delete;
};

#endif // STDATAOPERATOR_H
