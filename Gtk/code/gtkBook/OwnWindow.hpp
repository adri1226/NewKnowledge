#ifndef OWNWINDOW_HPP
#define OWNWINDOW_HPP

#include <iostream>

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/box.h>

class OwnWindow : 
  public Gtk::Window
{
  public:
    OwnWindow();

  protected:
    void onButtonClicked();

    Gtk::Button mButton;
    Gtk::Box mBox;
    Gtk::RadioButton mRadioButton1;
    Gtk::RadioButton mRadioButton2;
    Gtk::RadioButton mRadioButton3;
};

#endif // OWNWINDOW_HPP