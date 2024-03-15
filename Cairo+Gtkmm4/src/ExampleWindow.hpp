#include <gtkmm.h>

#include "MyArea.hpp"
#include "MyAreaTest.hpp"
#include "MyImage.hpp"

class ExampleWindow : 
  public Gtk::Window
{
  public:
    ExampleWindow();

    const int kWindowWidth = 1280;
    const int kWindowHeigth = 720;

  protected:
    void onClickButton();
    
  private:
    Gtk::Fixed mFixed;
    MyArea mArea;
    MyImage mImage;
    Gtk::CheckButton mCheckButton;
    MyAreaTest mTest;
};