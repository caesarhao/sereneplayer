## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(pkgdatadir)/ui
ui_DATA = sereneplayer.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(SERENEPLAYER_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = sereneplayer

sereneplayer_SOURCES = \
	main.c \
	sereneplayer.h \
	sereneplayer.c	


sereneplayer_LDFLAGS =

sereneplayer_LDADD = $(SERENEPLAYER_LIBS)


if PLATFORM_WIN32
sereneplayer_LDFLAGS += -Wl,--export-all-symbols
else
sereneplayer_LDFLAGS += -Wl,--export-dynamic
endif

if NATIVE_WIN32
sereneplayer_LDFLAGS += -mwindows
endif


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

