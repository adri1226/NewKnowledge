#include <gtkmm.h>

#include "MyArea.hpp"
#include "MyImage.hpp"

class ExampleWindow : 
  public Gtk::Window
{
  public:
    ExampleWindow();
    
  private:
    Gtk::Fixed mFixed;
    MyArea mArea;
    MyImage mImage;
};