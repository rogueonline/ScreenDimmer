#include <iostream>

#include <gtk/gtk.h>

#include "Properties.hpp"
#include "ScreenDimmer.hpp"

void ScreenDimmer::activate(GtkApplication* application, gpointer pointer) {
	// Get rc file in home directory
	const char* home = getenv("HOME");
	std::string rc = "/.screendimmerrc";
	std::string homeRC = home + rc;
	Properties properties = Properties(homeRC);

	int x = 0;
	int y = 0;
	int monitorCount = stoi(properties.get("monitor.count", "1"));
	for (int i = 0; i < monitorCount; i++) {
		std::string index = std::to_string(i + 1);
		int width = stoi(properties.get("monitor." + index + ".width", "1920")); // Default 1920
		int height = stoi(properties.get("monitor." + index + ".height", "1080")); // Default 1080
		double opacity = stod(properties.get("monitor." + index + ".opacity", ".5")); // Default .5

		// Skip if opacity set to 0
		if (opacity == 0) {
			// Set xy for next monitor
			x += width;
			y = 0;
			continue;
		}

		// Create window
		GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

		gtk_widget_set_name(window, ("_" + index).c_str()); // ID for css
		gtk_window_set_title(GTK_WINDOW(window), "Screen Dimmer");
		gtk_window_set_default_size(GTK_WINDOW(window), width, height); // Window size
		gtk_window_set_keep_above(GTK_WINDOW(window), true); // Keep window on top
//		gtk_window_maximize(GTK_WINDOW(window)); // Maximize removes title bar
		gtk_window_move(GTK_WINDOW(window), x, y); // Window xy location

		// Set xy for next monitor
		x += width;
		y = 0;

		g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

		// Apply CSS style
		GtkCssProvider* cssProvider = gtk_css_provider_new();
		GdkDisplay* display = display = gdk_display_get_default();
		GdkScreen* screen = gtk_window_get_screen(GTK_WINDOW(window));

		gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

		// Create Css for window
		std::string cssWindow = "#_" + index + " { background-color: " + properties.get("monitor." + index + ".color", "#000000") + "; }"; // Default #000000
		const char* css = cssWindow.c_str();
		gtk_css_provider_load_from_data(cssProvider, css, strlen(css), NULL);
		g_object_unref(cssProvider);

		// Show window
		gtk_widget_show_all(window);
//		gtk_widget_show(window);
		gtk_widget_set_opacity(GTK_WIDGET(window), opacity);

		// GDK setting for click through
		GdkWindow* gdkWindow = gtk_widget_get_window(GTK_WIDGET(window));
		gdk_window_set_override_redirect(GDK_WINDOW(gdkWindow), true); // Prevent window manager from taking control so click through works
		gdk_window_input_shape_combine_region(GDK_WINDOW(gdkWindow), cairo_region_create(), 0, 0); // Set region width height to 0
		gdk_window_show(GDK_WINDOW(gdkWindow));
	}

	gtk_main();
}

int ScreenDimmer::run(int argc, char** argv) {
	int status;

	GtkApplication* application;
	application = gtk_application_new("com.screendimmer", G_APPLICATION_FLAGS_NONE);

	g_signal_connect(application, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(application), argc, argv);
	g_object_unref(application);

	return status;
}
