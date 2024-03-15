#include "ExampleWindow.hpp"

ExampleWindow::ExampleWindow() : 
  m_Button_FixLines("Fix lines"),
  mDrawingArea("TEXTO INICIAL"),
  mLabel("HOLAAAA")
{
  set_title("Thin lines example");

  m_Container.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

  m_Container.add(m_Button_FixLines);
  m_Container.add(mFixed);

  // mFixed.put(mImage, 0, 0);
  // mFixed.put(mDrawingArea, 0, 0);
  // mFixed.put(mLabel, 0, 0);
  mFixed.add(mImage);
  mFixed.add(mDrawingArea);
  mFixed.put(mLabel, 10, 10);

  add(m_Container);

  m_Button_FixLines.signal_toggled().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_toggled));

  // Synchonize the drawing in mDrawingArea with the state of the toggle button.
  on_button_toggled();

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_toggled()
{
  if (m_Button_FixLines.get_active())
  {
    mDrawingArea.setText("BUTTON TRUE");
  }
  else
  {
    mDrawingArea.setText("BUTTON FALSE");
  }
}