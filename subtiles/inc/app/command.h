#ifndef COMMAND_H
#define COMMAND_H

#include <QUndoCommand>
#include <list>
#include "STDataOperator.h"
#include "STTrack.h"

class STCInsertTrack : public QUndoCommand, public STDataOperator
{
    std::list<STTrackPtr>::iterator m_itTargetTrack, m_itInsertPos;
    STTrackPtr m_targetTrack;
  public:
    STCInsertTrack(std::list<STTrackPtr>::iterator aInsertPos,
                   STTrackPtr aTargetTrack = nullptr,
                   QUndoCommand *parent = nullptr);
    virtual void undo() override;
    virtual void redo() override;
};

#endif // COMMAND_H
