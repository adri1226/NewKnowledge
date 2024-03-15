#ifndef BUTTONBOX_HPP
#define BUTTONBOX_HPP

#include <gtkmm.h>

class ButtonBox :
  public Gtk::Box
{
  public:
    ButtonBox();
    virtual ~ButtonBox();

  private:
    Gtk::Button mButton00;
    Gtk::Button mButton01;
    Gtk::Button mButton02;
};

#endif //BUTTONBOX_HPP