#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <songlib/util.h>
#include <songlib/songlib.h>
#include <pthread.h>
#include <string.h>


char *PROGRAM_NAME;
char *PROGRAM_VERSION;


GtkWidget *window;
GtkWidget *MainTable;
GtkWidget *RightTable;
GtkWidget *TempoEntry;
GtkWidget *NameEntry;
GtkAdjustment *adjustment;
GtkWidget *radio4, *radio8, *radio2, *radio1;
GtkWidget *hbox;
GtkWidget *LeftTable;
char* target;

gchar *SongName;
char *PlaySong;

int Tempo;

int page;
int RecFlag;
int PlayFlag;

int hihat, snare, hitom, crash, lotom, floortom, bass, ride;

double duration;

void pageOne();
void showPageOne();
void hidePageOne();
void showPageTwo();
void hidePageTwo();
void pageOne();


void setDur(GtkWidget *widget,gpointer   data)
{
	if(strcmp((char*)data,"1") == 0)
		duration = W;
	else if(strcmp((char*)data,"2") == 0)
		duration = H;
	else if(strcmp((char*)data,"4") == 0)
		duration = Q;
	else if(strcmp((char*)data,"8") == 0)
		duration = I;
}

void makeDrumKit()
{
	snare = readScale("samples/drums-snare/","osd_");
    hitom = readScale("samples/drums-tom/","osd-hi_");
    
    hihat = readScale("samples/drums-hihat/","osd-closed_");
    
    crash = readScale("samples/drums-crash/","osd_");
    
    lotom = readScale("samples/drums-tom/","osd-lo_");
    
    floortom = readScale("samples/drums-tom/","boom_");
    
    bass = readScale("samples/yamaha-drums/","bass_");
    
    ride = readScale("samples/drums-ride/","quartertone_");
}


static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
	system(target);
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

void showPageTwo()
{
	setWindow(window,"mohnish/gb-drum-kit changed1.jpg");
	gtk_widget_show(radio1);
	gtk_widget_show(radio2);
	gtk_widget_show(radio4);
	gtk_widget_show(radio8);
	gtk_widget_show(hbox);
	gtk_widget_show(LeftTable);
	gtk_widget_show(MainTable);
}

void hidePageTwo()
{
	gtk_widget_hide(radio1);
	gtk_widget_hide(radio2);
	gtk_widget_hide(radio4);
	gtk_widget_hide(radio8);
	gtk_widget_hide(hbox);
	gtk_widget_hide(LeftTable);
	gtk_widget_hide(MainTable);
}

void pageTwo()
{
	

	songInit();
	makeDrumKit();
	gtk_window_set_title (GTK_WINDOW (window), "Drum Studio");
	

	
	hbox = gtk_hbox_new( 0, 0);
	radio1 = gtk_radio_button_new(NULL);
	gtk_box_pack_start (GTK_BOX(hbox),radio1,0,0,0);
	radio2 = gtk_radio_button_new( gtk_radio_button_group(GTK_RADIO_BUTTON(radio1)));
	
	gtk_box_pack_start (GTK_BOX(hbox),radio2,0,0,0);
	
	radio4 = gtk_radio_button_new( gtk_radio_button_group(GTK_RADIO_BUTTON(radio2)));
	gtk_box_pack_start (GTK_BOX(hbox),radio4,0,0,0);
	
	radio8 = gtk_radio_button_new( gtk_radio_button_group(GTK_RADIO_BUTTON(radio4)));
	gtk_box_pack_start (GTK_BOX(hbox),radio8,0,0,0);
	gtk_widget_set_size_request(radio1,100,20);
	gtk_widget_set_size_request(radio2,100,20);
	gtk_widget_set_size_request(radio4,100,20);
	gtk_widget_set_size_request(radio8,100,20);

	g_signal_connect(radio1,"toggled",G_CALLBACK(setDur),(gpointer)"1");
	g_signal_connect(radio2,"toggled",G_CALLBACK(setDur),(gpointer)"2");
	g_signal_connect(radio4,"toggled",G_CALLBACK(setDur),(gpointer)"4");
	g_signal_connect(radio8,"toggled",G_CALLBACK(setDur),(gpointer)"8");

	LeftTable = gtk_table_new (15, 5, TRUE);
	gtk_table_attach_defaults (GTK_TABLE (LeftTable),hbox , 0, 1, 0, 1);
	gtk_table_attach_defaults (GTK_TABLE (MainTable),LeftTable , 0, 1, 0, 1);
	
	
}



void playSnare()
{
	system("rplay samples/live/snare.rra");
	if(RecFlag == 1)
		drum(duration,snare,SNARE);
	
}

void playHihat()
{
	system("rplay samples/live/hihat.rra");
	if(RecFlag == 1)
		drum(duration,hihat,HAT_CLOSED);
}
void playBass()
{
	system("rplay samples/live/bass.rra");
	if(RecFlag == 1)
		drum(duration,bass,BASS_MIDDLE);
	
}
void playHi()
{
	system("rplay samples/live/hitom.rra");
	if(RecFlag == 1)
		drum(duration,hitom,TOM_HIGH);
	
}
void playLow()
{
	system("rplay samples/live/lotom.rra");
	if(RecFlag == 1)
		drum(duration,lotom,TOM_LOW);
	

}
void playFloor()
{
	system("rplay samples/live/floortom.rra");
	if(RecFlag == 1)
		drum(duration,floortom,TIM_MIDDLE);
	

}
void playCrash()
{
	system("rplay samples/live/crash.rra");
	if(RecFlag == 1)
		drum(duration,crash, CRASH);
	
	
}

void playRest()
{
	if(RecFlag == 1);
		rest(duration);
}
void playRide()
{
	system("rplay samples/live/ride1.rra");
	if(RecFlag == 1)
		drum(duration,ride,RIDE);
	
	
}


void startPlay()
{
	if(PlayFlag==1)
	{
		setWindow(window,"mohnish/gb-drum-kit play4.jpg");
		system(PlaySong);
	}	
}
void startRec()
{
	if(RecFlag == 0)
	{	
		setWindow(window,"mohnish/gb-drum-kit record1.jpg");
		printf("%d-Tempo \n",Tempo);
		setTempo(Tempo);
		setTime(4,4);
		openOutput(SongName,0,0);
		RecFlag = 1;
		PlayFlag = 1;
	}
	else
	{
		closeOutput();
		setWindow(window,"mohnish/gb-drum-kit changed1.jpg");
		RecFlag = 0;
		
	}	
}

void goBack()
{
	hidePageTwo();
	page = 1;
	showPageOne();
	
}

void sense(int x, int y)
{
	if( (x > 545 && x < 600) && (y > 15 && y < 49) )//Record Button
		startRec();
	else if( (x > 476 && x < 545) && (y > 15 && y < 49) )//Play
		startPlay();
	else if( (x > 426 && x < 476) && (y > 15 && y < 49) )//Back
		goBack();
	else if( (x > 452 && x < 574) && (y > 115 && y < 160) )//Back
		playRest();
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
	if(page == 2)
	{
		
		if (event->button == 1)
		{
			sense( (int)event->x, (int)event->y);
		}   
		
	}
	else if(page == 1)
	{
		if(((int)event->x > 715 && (int)event->x < 942) && ((int)event->y > 628 && (int)event->y < 693))
		{
			
			hidePageOne();
			showPageTwo();
			Tempo = (int)gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(TempoEntry));
			SongName = (char*)gtk_entry_get_text(GTK_ENTRY(NameEntry));
			strcat(SongName,".rra");
			PlaySong = (char*)malloc(strlen("rplay ")+1+strlen(SongName));
			target = (char*)malloc(strlen("rra2mp3 ")+1+strlen(SongName));
			PlaySong[0]='\0';
			target[0]='\0';
			strcat(PlaySong,"rplay ");
			strcat(PlaySong,SongName);
			strcat(target,SongName);

			page = 2;
		}	
	}
	else if(page == 0)
	{
		showPageOne();
		page = 1;
	}
	printf( "%d %d \n",(int)event->x, (int)event->y);
	return TRUE;
}
void pageOne()
{
    
    /* Set the window title */
    gtk_window_set_title (GTK_WINDOW (window), "Start Here");
	g_signal_connect (window, "delete-event",
                      G_CALLBACK (delete_event), NULL);
    /* Creating tables */
    MainTable = gtk_table_new (1, 2, TRUE);
	RightTable = gtk_table_new (16, 5, TRUE);
    
    /* Put the table in the main window */
    gtk_container_add (GTK_CONTAINER (window), MainTable);

   	gtk_table_attach_defaults (GTK_TABLE (MainTable),RightTable , 1, 2, 0, 1);
    
    // Creating the tempo entry/
    NameEntry = gtk_entry_new ();
    gtk_entry_set_text(GTK_ENTRY(NameEntry),"Default");

    //TempoEntry = gtk_spin_button_new( NULL, 2, 0);
    gtk_table_attach_defaults (GTK_TABLE (RightTable),NameEntry, 0, 2, 4, 5);

  //* Creating the Tempo entry
  	adjustment = gtk_adjustment_new (150.0, 100.0, 300.0, 1.0, 5.0, 0.0);

    TempoEntry = gtk_spin_button_new( adjustment, 2.0, 0);
    gtk_spin_button_set_increments (GTK_SPIN_BUTTON(TempoEntry), 1, 5);
    gtk_table_attach_defaults (GTK_TABLE (RightTable),TempoEntry, 0, 2, 6, 7);
    
}
void hidePageOne()
{
	gtk_widget_hide (NameEntry);
    
    gtk_widget_hide (TempoEntry);
    gtk_widget_hide (RightTable);
    gtk_widget_hide (MainTable);	
}
void showPageOne()
{
	setWindow(window,"mohnish/Home1.jpg");
	gtk_widget_show (NameEntry);
   
    gtk_widget_show (TempoEntry);
    gtk_widget_show (RightTable);
    gtk_widget_show (MainTable);

}
void musicBackground(void* msg)
{
	system("play song.mp3");
}
int main( int   argc,
          char *argv[] )
{
	PROGRAM_NAME = "DrumHero";
	PROGRAM_VERSION = "0.03";
	page = 0;
	RecFlag = 0;
	PlayFlag = 0;
	
	gtk_init (&argc, &argv);
	
	//Window here
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	
	gtk_widget_set_events(window,GDK_BUTTON_PRESS_MASK);
	
	gtk_signal_connect (GTK_OBJECT (window), "button_press_event",
		      (GtkSignalFunc) button_press_event, NULL);
	
	
	gtk_window_set_title (GTK_WINDOW (window), "Drum Studio");
	gtk_widget_set_size_request(window,1024,768);
	gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
	gtk_window_set_icon(GTK_WINDOW(window),load_pixbuf_from_file("mohnish/OpCover.jpg"));
	g_signal_connect (window, "delete-event",
                      G_CALLBACK (delete_event), NULL);
	
	//pageOne();
	setWindow(window,"mohnish/OpCover.jpg");
	
	pageOne();
	pageTwo();
	gtk_widget_show (window);

    gtk_main();
    return 0;
}
