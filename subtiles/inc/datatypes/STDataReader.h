#ifndef STDATAREADER_H
#define STDATAREADER_H

#include "STDataOperator.h"

class SubtilesHost;

class STDataReader : public STDataOperator
{
    friend class SubtilesHost;

  public:
    STDataReader();

    STDialogCPtr GetReadDialog(uint aDlgId);
    std::list<STTrackPtr>::const_iterator GetReadTrackCBegin();
    std::list<STTrackPtr>::const_iterator GetReadTrackCEnd();
    size_t GetDialogCount();
  private:
    static QHash<uint, STDialogPtr> *m_dialogs;
    static std::list<STTrackPtr> *m_tracks;
};


#endif // STDATAREADER_H
