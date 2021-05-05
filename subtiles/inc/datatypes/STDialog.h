#ifndef STDIALOG_H
#define STDIALOG_H

#include <memory>
#include "STTrack.h"
#include "STTimecode.h"
#include "STStyle.h"

/**
 * @brief STDialog class is an ASS "event". May be expanded in future.
 *        Subtiles uses the term "dialog" for "events" in ASS. Whether it is a
 *        "Dialogue" or not, an "event" is always STDialog instance. Different
 *        "event" types specified by Type member. See ASS Specifications.
 *        When being used, program should respect the track types, and only
 *        put corresponding dialogs into correct tracks.
 */
struct STDialog
{
    enum DialogType : char
    {
      Dialog, Comment, Picture, Sound, Movie, Command
    } Type;

    QString Text; ///< Text for this line of dialog; or others specified by ASS
    STTime Begin, Duration; ///< Timespan for this line
    STStyle Style;
    int Layer; ///< Collision detect group; Stack ordering (Highest on top).

    QString Name; ///< Speaker of this dialog
    double MarginL, MarginR, MarginV;
    // TODO: STTransitionFx TransitionEffect;

    STTrackPtr Track; ///< The track this dialog belongs to
};

using STDialogPtr = std::shared_ptr<STDialog>;
using STDialogCPtr = std::shared_ptr<const STDialog>;

#endif // STDIALOG_H
