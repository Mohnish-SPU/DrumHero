#include <iostream>
#include <gtk/gtk.h>

int main(int argc, char* argv[])
{
	gtk_init(&argc, &argv);
	
	GtkWideget *window, *button;
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button = ;
	gtk_container_add(GTK_CONTAINER(window), button);
	g_signal_connect(G_OBJECT(button), "button_press_event", G_CALLBACK(ClickCallback), NULL);
	
   gtk_widget_show_all(window);
      g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy_event), NULL);
     gtk_main(); 

	return 0;
}


  static void destroy_event(GtkWidget *widget, gpointer data)
  {
    gtk_main_quit();
  }

  static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
  {
    return FALSE; // must return false to trigger destroy event for window
  }
