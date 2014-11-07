#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <songlib/util.h>
#include <songlib/songlib.h>
#include<gtk/gtk.h>

int main( int argc,
			char *argv[])
{
	GtkWidget *MainWindow;
	GtkWidget *MainTable;
	GtkWidget *MainRightBox;
	GtkWidget *MainVSeperator;
	
	GtkWidget *StartButton;
	
	GtkWidget *TempoEntry;
	GtkWidget *TempoBox;
	GtkWidget *TempoSetButton;
	GtkWidget *TempoSeperator;
/* Main Window related */	

	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (MainWindow), "Beat Box");
	gtk_container_set_border_width (GTK_CONTAINER (MainWindow), 10);

	g_signal_connect (MainWindow, "destroy", G_CALLBACK (exit), NULL);

	MainTable = gtk_table_new( 1, 2, TRUE);
	
	gtk_container_add (GTK_CONTAINER (MainWindow), MainTable);

	MainVSeperator = gtk_hseparator_new();
	MainRightBox = gtk_vbox_new(FALSE, 0);
	gtk_box_pack_start(GTK_BOX(MainRightBox),MainVSeperator,FALSE,TRUE,5);

gtk_table_attach_defaults (GTK_TABLE (MainTable), MainRightBox, 1, 2, 0, 1);


	gtk_widget_show(MainVSeperator);
	gtk_widget_show(MainRightBox);
	gtk_widget_show(MainTable);
	gtk_widget_show(MainWindow);

/* Start Button Related
	
	MainVSeperator = gtk_hseparator_new();
	gtk_box_pack_start(GTK_BOX(MainRightBox),MainVSeperator,FALSE,TRUE,5);
	gtk_widget_show(MainVSeperator);
	StartButton = gtk_button_new_with_label("Start Recording");
	 gtk_box_pack_start (GTK_BOX (MainRightBox), StartButton, FALSE, FALSE, 0);
	 gtk_widget_show(StartButton);
	//Event Handlers
	//g_signal_connect (StartButton,"clicked",G_CALLBACK(onStart),TempoBox);
	
 Setting the Tempo	
	
	TempoBox = make_box(FALSE, 0, FALSE, FALSE, 0);
	SetButtonTempo = gtk_button_new_with_label("Set Tempo");
	
	gtk_box_pack_end (GTK_BOX (box2), label, FALSE, FALSE, 0); 

	TempoEntry = gtk_entry_new_with_buffer ("90");

	gtk_widget_show(SetButtonTempo);
	
	gtk_entry_set_placeholder_text (TempoEntry,"Tempo");
	
	gtk_box_pack_start(GTK_BOX(TempoBox),TempoEntry,);
*/	
	return 0;
}
