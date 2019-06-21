#include <assert.h>
#include <stdlib.h>
#include <glib.h>
#include <poppler.h>
#include <poppler-document.h>
#include <poppler-page.h>
#include <cairo.h>
#include <cairo-svg.h>
#include <stdio.h>
#include <string.h>

#include <sys/wait.h>
#include <unistd.h>

int convertPDFtoSVG(int argn, char *args[]);

int convertPage(PopplerPage *page, const char* svgFilename);

gchar *getAbsoluteFileName(const gchar *fileName);

int lol();