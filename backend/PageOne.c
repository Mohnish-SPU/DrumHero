#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <songlib/util.h>
#include <songlib/songlib.h>
/* Our callback.
 * The data passed to this function is printed to stdout */

char *PROGRAM_NAME = "DrumHero";
char *PROGRAM_VERSION = "0.01";

GtkWidget *window;
GtkWidget *RightTwo;

GtkWidget *BPMeasureEntry;
GtkWidget *TempoEntry;
GtkWidget *NameEntry;


GtkWidget *SetTempoButton;
GtkWidget *SetBPMeasureButton;			
GtkWidget *SetNameButton;
GtkWidget *NextButton;
	
//To find out which button was pressed Utility for debugging
static void callback( GtkWidget *widget,
                      gpointer   data )
{
    g_print ("Hello again - %s was pressed\n", (char *) data);
}

/* This callback starts the song lib program */

void startRec(GtkWidget *widget,gpointer   data )
{
	songInit();
	gtk_widget_show (NameEntry);
	gtk_widget_show (SetNameButton);
	gtk_widget_show (NextButton);
    gtk_widget_show (SetBPMeasureButton);
    gtk_widget_show (BPMeasureEntry);    
    gtk_widget_show (SetTempoButton);
    gtk_widget_show (TempoEntry);
	
}

//void na//
//
void tempoSet( GtkWidget *widget,
                      gpointer data )
{
	//setTempo(*((int*)gtk_get_entry_buffer(TempoEntry)));      //Look up the function to do this
	//g_print("%d\n",(int)*(gtk_get_entry_buffer(TempoEntry)));  //Do call backs for all bpm , name , tempo,
}

static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
    gtk_main_quit ();
    return FALSE;
}

void nextPage(GtkWidget *widget,gpointer hide)
{
	gtk_window_set_title (GTK_WINDOW (window), "Drum Studio");
	gtk_widget_hide(hide);
	gtk_widget_show(RightTwo);
	//makeDrumSet();
}

int main( int   argc,
          char *argv[] )
{
    
    GtkWidget *RecButton;
    GtkWidget *MainTable;
	GtkWidget *RightTable;
	
	GtkWidget *ExitButton;
	
	
    gtk_init (&argc, &argv);

    /* Create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* Set the window title */
    gtk_window_set_title (GTK_WINDOW (window), "Start Here");

    /* Set a handler for delete_event that immediately
     * exits GTK. */
    g_signal_connect (window, "delete-event",
                      G_CALLBACK (delete_event), NULL);


    /* Creating tables */
    MainTable = gtk_table_new (1, 2, TRUE);
	RightTable = gtk_table_new (16, 5, TRUE);
    
    /* Put the table in the main window */
    gtk_container_add (GTK_CONTAINER (window), MainTable);

    /* Create Recbutton */
    RecButton = gtk_button_new_with_label ("Start Recording");

    //* When the button is clicked, we call the "callback" function
    //* with a pointer to "button 1" as its argument 
    g_signal_connect (RecButton, "clicked",
	              G_CALLBACK (startRec),NULL);


    //* Insert Rec button into the upper right quadrant of the table 
   	gtk_table_attach_defaults (GTK_TABLE (MainTable),RightTable , 1, 2, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE (RightTable), RecButton, 0, 3, 1, 3);
    
    // Creating the tempo entry/
    TempoEntry = gtk_entry_new ();
    gtk_table_attach_defaults (GTK_TABLE (RightTable),TempoEntry, 0, 2, 4, 5);
    
    // creating the tempo set button/
    
    SetTempoButton = gtk_button_new_with_label ("Set Tempo");
    gtk_table_attach_defaults (GTK_TABLE (RightTable),SetTempoButton, 2, 3, 4, 5);
    g_signal_connect (SetTempoButton,"clicked",G_CALLBACK (tempoSet),NULL);
    
    /* Creating the BPMeasure entry*/
    BPMeasureEntry = gtk_entry_new ();
    gtk_table_attach_defaults (GTK_TABLE (RightTable),BPMeasureEntry, 0, 2, 6, 7);
    
    //* creating the BPMeasure set button
    
    SetBPMeasureButton = gtk_button_new_with_label ("Set Beats/Measure");
    gtk_table_attach_defaults (GTK_TABLE (RightTable),SetBPMeasureButton, 2, 3, 6, 7);
	//g_signal_connect (SetTempoButton,"clicked");
    

    //* Creating the Name entry
    NameEntry = gtk_entry_new ();
    gtk_table_attach_defaults (GTK_TABLE (RightTable),NameEntry, 0, 2, 8, 9);
    
    // creating the Name set button
    
    SetNameButton = gtk_button_new_with_label ("Song Name");
    gtk_table_attach_defaults (GTK_TABLE (RightTable),SetNameButton, 2, 3, 8, 9);
	//g_signal_connect (SetTempoButton,"clicked");

	//Next Button
	
	NextButton = gtk_button_new_with_label ("Next");
	gtk_table_attach_defaults (GTK_TABLE (RightTable),NextButton, 3, 4, 15, 16);	
	g_signal_connect (NextButton, "clicked", G_CALLBACK (nextPage), (gpointer) RightTable);
	
	//Exit Button

	ExitButton = gtk_button_new_with_label ("Exit");
	gtk_table_attach_defaults (GTK_TABLE (RightTable),ExitButton, 0, 1, 15, 16);
	g_signal_connect (ExitButton, "clicked", G_CALLBACK (delete_event), NULL);

	gtk_widget_show(ExitButton);
	gtk_widget_show (RecButton);
    gtk_widget_show (RightTable);
    gtk_widget_show (MainTable);
    gtk_widget_show (window);



/***************************************************************\\PAGE-2\\************************************************************************/

	GtkWidget* HihatImage;
	//GtkWidget* HihatButton = gtk_button_new();
	
	GtkWidget* CrashImage;
	GtkWidget *FloorImage;
	GtkWidget *HiImage;
	GtkWidget *LowImage;
	GtkWidget *BaseImage;
	GtkWidget *SnareImage;
	//GtkWidget *background;
	
	GtkWidget *BackButton;
	GtkWidget *RestButton;
	GtkWidget *FinishButton;
	
	BackButton = gtk_button_new_with_label ("Back");
	RestButton = gtk_button_new_with_label ("Rest");
	FinishButton = gtk_button_new_with_label ("Finish");
	

	RightTwo = gtk_table_new(12,12,FALSE);
	gtk_table_attach_defaults (GTK_TABLE (MainTable),RightTwo, 0, 2, 0, 1);

	
	//background = gtk_image_new_from_file ( "cover.png" );
	HihatImage = gtk_image_new_from_file ( "index.jpeg" );  //Look further into this to load from another directory
	CrashImage = gtk_image_new_from_file ( "index.jpeg" );
	FloorImage = gtk_image_new_from_file ( "floor.png" );
	HiImage = gtk_image_new_from_file ( "floor.png" );
	LowImage = gtk_image_new_from_file ( "floor.png" );
	BaseImage = gtk_image_new_from_file ( "floor.png" );
	SnareImage = gtk_image_new_from_file ( "floor.png" );
	
	gtk_table_attach_defaults (GTK_TABLE (RightTwo),BackButton,1,2,9,10);
	gtk_table_attach_defaults (GTK_TABLE (RightTwo),RestButton,3,4,9,10);
	gtk_table_attach_defaults (GTK_TABLE (RightTwo),FinishButton,5,6,9,10);
	
	gtk_table_attach_defaults (GTK_TABLE (RightTwo),HihatImage,1,2,0,1);
	gtk_table_attach_defaults (GTK_TABLE (RightTwo),CrashImage,4,5,0,1);
	gtk_table_attach_defaults (GTK_TABLE (RightTwo),HiImage,2,3,1,2);
	gtk_table_attach_defaults (GTK_TABLE (RightTwo),LowImage,3,4,1,2);
	gtk_table_attach_defaults (GTK_TABLE (RightTwo),BaseImage,4,5,3,4);
	gtk_table_attach_defaults (GTK_TABLE (RightTwo),SnareImage,1,2,2,3);
    gtk_table_attach_defaults (GTK_TABLE (RightTwo),FloorImage,5,6,2,3);
    
    //Events for any widgets must connect to g_signal handlers
    
    gtk_widget_show(BackButton);
    gtk_widget_show(RestButton);
    gtk_widget_show(FinishButton);
    
    gtk_widget_show(HihatImage);
    gtk_widget_show(SnareImage);
    gtk_widget_show(BaseImage);
    gtk_widget_show(FloorImage);
    gtk_widget_show(LowImage);
    gtk_widget_show(HiImage);
    gtk_widget_show(CrashImage);
	
    gtk_main ();

    return 0;
}

