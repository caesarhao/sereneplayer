/***************************************************************************
 *            mplayerwrap.c
 *
 *  Thu July 28 22:47:09 2016
 *  Copyright  2016  HaoZhang
 *  <user@host>
 ****************************************************************************/
/*
 * mplayerwrap.c
 *
 * Copyright (C) 2016 - HaoZhang
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "mplayerwrap.h"

MplayerWrap	*mplayerwrap_new(GtkWidget *widget){
	MplayerWrap *mw_p = g_new0(MplayerWrap, 1);
	mw_p->widget = widget;
	mw_p->socket = gtk_socket_new();
	gtk_widget_show (mw_p->socket);
	gtk_container_add (GTK_CONTAINER (mw_p->widget), mw_p->socket);
	return mw_p;
}
