#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/fixed.h>
#include <gtkmm/label.h>

#include "MyArea.hpp"
#include "MyImage.hpp"

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  //Signal handlers:
  void on_button_toggled();

private:
  Gtk::Grid m_Container;
  MyArea mDrawingArea;
  Gtk::CheckButton m_Button_FixLines;
  MyImage mImage;
  Gtk::Fixed mFixed;
  Gtk::Label mLabel;
};

#endif //GTKMM_EXAMPLEWINDOW_H