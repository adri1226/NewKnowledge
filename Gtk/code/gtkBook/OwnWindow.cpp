#include "OwnWindow.hpp"

OwnWindow::OwnWindow() :
  mButton("Click Here"), mRadioButton1("Radio Button 1"), mRadioButton2("Radio Button 2"), 
  mRadioButton3("Radio Button 3"), mBox(Gtk::ORIENTATION_VERTICAL)
{
  set_border_width(10);

  mButton.signal_clicked().connect(sigc::mem_fun(*this, &OwnWindow::onButtonClicked));

  mRadioButton2.join_group(mRadioButton1);
  mRadioButton3.join_group(mRadioButton1);

  mBox.pack_start(mButton);
  mBox.pack_start(mRadioButton1);
  mBox.pack_start(mRadioButton2);
  mBox.pack_start(mRadioButton3);

  add(mBox);

  mBox.show();
  mButton.show();
  mRadioButton1.show();
  mRadioButton2.show();
  mRadioButton3.show();
}

void OwnWindow::onButtonClicked()
{
  std::cout << "Button Clicked" << std::endl;
}
