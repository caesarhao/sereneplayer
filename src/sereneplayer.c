/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * sereneplayer.c
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
#include "sereneplayer.h"

#include <glib/gi18n.h>



/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/sereneplayer.ui" */
#define UI_FILE "src/sereneplayer.ui"
#define TOP_WINDOW "window"


G_DEFINE_TYPE (Sereneplayer, sereneplayer, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro SERENEPLAYER_APPLICATION gets Sereneplayer - DO NOT REMOVE */
struct _SereneplayerPrivate
{
	/* ANJUTA: Widgets declaration for sereneplayer.ui - DO NOT REMOVE */
};

/* Create a new window loading a file */
static void
sereneplayer_new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;

	GtkBuilder *builder;
	GError* error = NULL;

	SereneplayerPrivate *priv = SERENEPLAYER_APPLICATION(app)->priv;

	/* Load UI from file */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_critical ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, app);

	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, TOP_WINDOW));
        if (!window)
        {
		g_critical ("Widget \"%s\" is missing in file %s.",
				TOP_WINDOW,
				UI_FILE);
        }

	
	/* ANJUTA: Widgets initialization for sereneplayer.ui - DO NOT REMOVE */

	g_object_unref (builder);
	
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	if (file != NULL)
	{
		/* TODO: Add code here to open the file in the new window */
	}

	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
sereneplayer_activate (GApplication *application)
{
	sereneplayer_new_window (application, NULL);
}

static void
sereneplayer_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		sereneplayer_new_window (application, files[i]);
}

static void
sereneplayer_init (Sereneplayer *object)
{
	object->priv = G_TYPE_INSTANCE_GET_PRIVATE (object, SERENEPLAYER_TYPE_APPLICATION, SereneplayerPrivate);
}

static void
sereneplayer_finalize (GObject *object)
{
	G_OBJECT_CLASS (sereneplayer_parent_class)->finalize (object);
}

static void
sereneplayer_class_init (SereneplayerClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = sereneplayer_activate;
	G_APPLICATION_CLASS (klass)->open = sereneplayer_open;

	g_type_class_add_private (klass, sizeof (SereneplayerPrivate));

	G_OBJECT_CLASS (klass)->finalize = sereneplayer_finalize;
}

Sereneplayer *
sereneplayer_new (void)
{
	return g_object_new (sereneplayer_get_type (),
	                     "application-id", "org.gnome.sereneplayer",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

