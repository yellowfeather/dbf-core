## Process this file with automake to produce Makefile.in

INCLUDES = $(DBFLIB_INCLUDEDIR) -DPACKAGE_LOCALE_DIR=\""$(datadir)/locale"\"

bin_PROGRAMS = dbf

dbf_SOURCES = dbf.c odbf.c csv.c sql.c codepages.c statistic.c congraph.c md5.c hash.c index.c import.c

dbf_LDADD = $(DBFLIB_LIBDIR) $(DBFLIB_LIBS)

noinst_HEADERS = dbf.h odbf.h csv.h sql.h codepages.h statistic.h congraph.h md5.h hash.h index.h import.h
