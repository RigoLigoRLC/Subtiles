#ifndef STDIALOG_H
#define STDIALOG_H

#include <QSharedPointer>
#include "STTimecode.h"

struct STDialog
{
    QString text; ///< Text for this line of dialog

    STTime begin, duration; ///< Timespan for this line

};

using STDialogPtr = QSharedPointer<STDialog>;

#endif // STDIALOG_H
