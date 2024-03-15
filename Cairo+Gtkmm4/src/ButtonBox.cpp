#include "ButtonBox.hpp"

ButtonBox::ButtonBox() :
  mButton00("Boton 00"),
  mButton01("Boton 01"),
  mButton02("Boton 02")
{
  set_orientation(Gtk::Orientation::HORIZONTAL);
  
  append(mButton00);
  append(mButton01);
  append(mButton02);
}

ButtonBox::~ButtonBox()
{
}
