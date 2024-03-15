#include <gtkmm.h>

#include "MyArea.hpp"

class ExampleWindow : public Gtk::Window
{
  public:
    ExampleWindow();
    
  private:
    Gtk::Box mVerticalBox;
    Gtk::Button mButtonBox00;
    Gtk::Button mButtonBox01;
    Gtk::Button mButtonBox02;
    MyArea mArea;
};