/*
 *   mooedit-private.h
 *
 *   Copyright (C) 2004-2010 by Yevgen Muntyan <emuntyan@users.sourceforge.net>
 *
 *   This file is part of medit.  medit is free software; you can
 *   redistribute it and/or modify it under the terms of the
 *   GNU Lesser General Public License as published by the
 *   Free Software Foundation; either version 2.1 of the License,
 *   or (at your option) any later version.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with medit.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MOO_EDIT_PRIVATE_H
#define MOO_EDIT_PRIVATE_H

#include "mooedit/mooedit-impl.h"
#include "mooedit/mooeditprogress.h"

G_BEGIN_DECLS

#define MOO_EDIT_IS_UNTITLED(edit) (!(edit)->priv->file)

struct MooEditPrivate {
    MooEditor *editor;

    GtkTextBuffer *buffer;
    MooEditViewArray *views;
    MooEditView *active_view;
    gboolean dead_active_view;

    gulong modified_changed_handler_id;
    guint apply_config_idle;
    gboolean in_recheck_config;

    /***********************************************************************/
    /* Document
     */
    GFile *file;
    char *filename;
    char *norm_name;
    char *display_filename;
    char *display_basename;

    char *encoding;
    MooLineEndType line_end_type;
    MooEditStatus status;

    guint file_monitor_id;
    gboolean modified_on_disk;
    gboolean deleted_from_disk;

    MooEditState state;
    MooEditProgress *progress;

    /***********************************************************************/
    /* Bookmarks
     */
    gboolean enable_bookmarks;
    GSList *bookmarks; /* sorted by line number */
    guint update_bookmarks_idle;

    /***********************************************************************/
    /* Actions
     */
    MooActionCollection *actions;
};

void    _moo_edit_remove_untitled   (MooEdit    *doc);

G_END_DECLS

#endif /* MOO_EDIT_PRIVATE_H */
