#include "ExampleWindow.hpp"

ExampleWindow::ExampleWindow() :
  mButtonBox00("Boton 0"),
  mButtonBox01("Boton 1"),
  mButtonBox02("Boton 2")
{
  set_title("Mi propia ventana");
  set_default_size(1280, 720);
  set_resizable(false);
  // set_decorated(false);
  maximize();
  
  set_child(mArea);

  // mVerticalBox.set_expand(true);

  // mVerticalBox.append(mButtonBox00);
  // mVerticalBox.append(mButtonBox01);
  // mVerticalBox.append(mButtonBox02);

  // mButtonBox00.set_expand(false);
}
