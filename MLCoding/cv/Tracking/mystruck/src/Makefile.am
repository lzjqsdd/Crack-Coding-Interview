## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(MYSTRUCK_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = mystruck

mystruck_SOURCES = \
	main.cc \
	Config.cpp \
	Config.h \
	sampler.cc \
	sampler.h \
	track.cc \
	track.h \
	haarfeature.cc \
	haarfeature.h \
	floatrect.cc \
	floatrect.h \
	haarfeatures.cc \
	haarfeatures.h \
	larank.cc \
	larank.h \
	guassiankernel.h

mystruck_LDFLAGS = 

mystruck_LDADD = $(MYSTRUCK_LIBS)



SUBDIRS = \
	Eigen
