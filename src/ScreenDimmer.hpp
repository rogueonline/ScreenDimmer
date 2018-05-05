#ifndef SCREENDIMMER_HPP
#define SCREENDIMMER_HPP

#include <iostream>

#include <gtk/gtk.h>

class ScreenDimmer {
	public:
		int run(int argc, char** argv);
	protected:
		static void activate(GtkApplication* application, gpointer pointer);
};

#endif
