#include <memory>
#include <iostream>

#include <gtkmm.h>

#include "gtkBook/ExampleWindow.hpp"
#include "gtkBook/clock.hpp"

int main(int argc, char *argv[])
{
   auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  //  Gtk::Window win;
  //  win.set_title("Cairomm Clock");

  //  Clock c;
  //  win.add(c);
  //  c.show();

  ExampleWindow win;


   return app->run(win);
}
