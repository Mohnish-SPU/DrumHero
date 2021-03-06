#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <songlib/util.h>
#include <songlib/songlib.h>

char *PROGRAM_NAME = "DrumHero";
char *PROGRAM_VERSION = "0.02";

GtkWidget *window = NULL;
int RecFlag = 0;
int SetFlag = 0;
char* SongName;

static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
    gtk_main_quit ();
    return FALSE;
}

GdkPixbuf *load_pixbuf_from_file (const char *filename)
{
    GError *error = NULL;
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file (filename, &error);

    if (pixbuf == NULL)
    {
        g_print ("Error loading file: %d : %s\n", error->code, error->message);
        g_error_free (error);
        exit (1);
    }
    return pixbuf;
}

void setWindow(GtkWidget *widget,gpointer   data )
{
	GdkPixbuf *LoadImage = NULL;
	GtkStyle *StyleNew = NULL;
	GdkPixmap *LoadPixmap = NULL;

	LoadImage = load_pixbuf_from_file ((gchar*)data);
	gdk_pixbuf_render_pixmap_and_mask (LoadImage, &LoadPixmap, NULL, 0);
    StyleNew = gtk_style_new ();
    StyleNew->bg_pixmap [0] = LoadPixmap;
    gtk_widget_set_style (GTK_WIDGET(window), GTK_STYLE (StyleNew));


}

void startSet()
{
	if(SetFlag == 0)
	{	
		//songInit();
		
		setWindow(window,"drumkitSettings.png");
		SetFlag = 1;
	}
	else
	{
		//closeOutput();
		
		setWindow(window,"drumkitStart.png");
		SetFlag = 0;
	}	
}
void startRec()
{
	if(RecFlag == 0)
	{	
		songInit();
		setWindow(window,"drumkitRecPress.png");
		RecFlag = 1;
	}
	else
	{
		//closeOutput();
		setWindow(window,"drumkitStart.png");
		RecFlag = 0;
	}	
}

void pageOne()
{
    setWindow(window,"drumkitStart.png");
}
void se()
{
	
}
void playSnare()
{
	system("rplay osd_36.rra");
}
void playHihat()
{
	system("rplay osd-closed_48.rra");
}
void playBass()
{
	system("rplay bass_10.rra");	
}
void playHi()
{
	system("rplay osd-hi_36.rra");	
}
void playLow()
{
	system("rplay osd-lo_36.rra");	

}
void playFloor()
{
	system("rplay floor_6.rra");	

}
void playCrash()
{
	system("rplay quartertone_12.rra");	
	
}

void playRide()
{
	system("rplay quartertone_0.rra");	
	
}

void sense(int x, int y)
{
	if( (x > 545 && x < 600) && (y > 26 && y < 57) )//Record Button
		startRec();
	else if( (x > 882 && x < 921) && (y > 22 && y < 63) )//Settings
		startSet();
	else if( (x > 50 && x < 325) && (y > 534 && y < 711) )//Snare
		playSnare();
	else if( (x > 0 && x < 270) && (y > 340 && y < 480) )//Hihat
		playHihat();
	else if( (x > 365 && x < 665) && (y > 550 && y < 715) )//Bass
		playBass();
	else if( (x > 288 && x < 468) && (y > 255 && y < 387) )//Hi tom
		playHi();
	else if( (x > 547 && x < 741) && (y > 241 && y < 381) )//Low tom
		playLow();
	else if( (x > 718 && x < 1024) && (y > 502 && y < 692) )//Floor tom
		playFloor();
	else if( (x > 773 && x < 1024) && (y > 100 && y < 390) )//Crash
		playCrash();
	else if( (x > 0 && x < 325) && (y > 100 && y < 275) )//Ride
		playRide();
}

static gboolean
button_press_event( GtkWidget *widget, GdkEventButton *event )
{
	if (event->button == 1)
	{
		sense( (int)event->x, (int)event->y);
	}   
	printf( "%d %d \n",(int)event->x, (int)event->y);

	return TRUE;
}

int main( int   argc,
          char *argv[] )
{
	gtk_init (&argc, &argv);
	
	//Window here
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	
	gtk_widget_set_events(window,GDK_BUTTON_PRESS_MASK);
	
	gtk_signal_connect (GTK_OBJECT (window), "button_press_event",
		      (GtkSignalFunc) button_press_event, NULL);
	
	
	gtk_window_set_title (GTK_WINDOW (window), "Drum Studio");
	gtk_widget_set_size_request(window,1024,768);
	g_signal_connect (window, "delete-event",
                      G_CALLBACK (delete_event), NULL);
	
	pageOne();
    gtk_widget_show (window);
    gtk_main();
    return 0;
}
