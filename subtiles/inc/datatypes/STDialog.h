#ifndef STDIALOG_H
#define STDIALOG_H

#include "STTimecode.h"

struct STDialog
{
    QString text; ///< Text for this line of dialog

    STTime begin, duration; ///< Timespan for this line

};

#endif // STDIALOG_H
