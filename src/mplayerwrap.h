/***************************************************************************
 *            mplayerwrap.h
 *
 *  Thu July 28 22:47:09 2016
 *  Copyright  2016  HaoZhang
 *  <user@host>
 ****************************************************************************/
/*
 * mplayerwrap.h
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
#ifndef __MPLAYERWRAP_H__
#define __MPLAYERWRAP_H__
#include <stdlib.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _MplayerWrap MplayerWrap;

typedef struct _MplayerWrap {
	GtkWidget	*widget;
	GtkWidget	*socket;
	int		 width;
	int		 height;
	int		 pid;	/* mplayer pid */
} MplayerWrap;

/* create MplayerWrap */
MplayerWrap	*mplayerwrap_new(GtkWidget *widget);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
