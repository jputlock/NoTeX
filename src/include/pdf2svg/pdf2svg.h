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

gchar *getAbsoluteFileName(const gchar *fileName);

int convertPage(PopplerPage *page, const char* svgFilename);

int pdf2svg(int argn, char *args[]);
