#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <songlib/util.h>
#include <songlib/songlib.h>
#include "DrumSet.h"

#define base "/usr/local/share/samples/yamaha-drums/"

//The directory which has the rra samples

static int snare;
static int hitom;
//static int lotom;
static int floor;
static int crash;
static int hihat;
static int bass;
//static int hera;

void makeDrumSet(GtkWidget *widget,gpointer   data )
{
	snare = readScale(base,"snare_");
    hitom = readScale(base,"tom_");
    hihat = readScale(base,"hihat_");
    crash = readScale(base,"crash_");
    floor = readScale(base,"floor_");
    bass = readScale(base,"bass_");
}


