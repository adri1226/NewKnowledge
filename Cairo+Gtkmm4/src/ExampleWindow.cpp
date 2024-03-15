#include "ExampleWindow.hpp"

ExampleWindow::ExampleWindow() :
  mImage("images/image.jpg")
{
  set_title("Mi propia ventana");
  set_default_size(1280, 720);
  set_resizable(false);
  // set_decorated(false);
  // maximize();
  
  set_child(mFixed);

  mFixed.put(mImage, 0, 0);
  mFixed.put(mArea, 0, 0);

  std::cout << "Fixed tamaño: " << mFixed.get_width() << ", " << mFixed.get_height() << std::endl;
}
