/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * sereneplayer.h
 * Copyright (C) 2016 Hao ZHANG <caesarhao@gmail.com>
 * 
 * sereneplayer is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * sereneplayer is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SERENEPLAYER_
#define _SERENEPLAYER_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define SERENEPLAYER_TYPE_APPLICATION             (sereneplayer_get_type ())
#define SERENEPLAYER_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), SERENEPLAYER_TYPE_APPLICATION, Sereneplayer))
#define SERENEPLAYER_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), SERENEPLAYER_TYPE_APPLICATION, SereneplayerClass))
#define SERENEPLAYER_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SERENEPLAYER_TYPE_APPLICATION))
#define SERENEPLAYER_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), SERENEPLAYER_TYPE_APPLICATION))
#define SERENEPLAYER_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), SERENEPLAYER_TYPE_APPLICATION, SereneplayerClass))

typedef struct _SereneplayerClass SereneplayerClass;
typedef struct _Sereneplayer Sereneplayer;
typedef struct _SereneplayerPrivate SereneplayerPrivate;

struct _SereneplayerClass
{
	GtkApplicationClass parent_class;
};

struct _Sereneplayer
{
	GtkApplication parent_instance;

	SereneplayerPrivate *priv;

};

GType sereneplayer_get_type (void) G_GNUC_CONST;
Sereneplayer *sereneplayer_new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */

