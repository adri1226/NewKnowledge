#include "ExampleWindow.hpp"

ExampleWindow::ExampleWindow() :
  mArea(kWindowWidth, kWindowHeigth),
  mImage("images/image.jpg", kWindowWidth, kWindowHeigth),
  mCheckButton("Cambiar Imagen"),
  mTest(kWindowWidth, kWindowHeigth)
{
  set_title("Mi propia ventana");
  set_default_size(kWindowWidth, kWindowHeigth);
  set_resizable(false);
  // set_decorated(false);
  // maximize();
  
  set_child(mFixed);

  // mFixed.put(mImage, 0, 0);
  // mFixed.put(mArea, 0, 0);
  // mFixed.put(mCheckButton, 10, 10);
  mFixed.put(mTest, 0, 0);
  

  mCheckButton.signal_toggled().connect(sigc::mem_fun(*this, &ExampleWindow::onClickButton));

  std::cout << "Fixed tamaño: " << mFixed.get_width() << ", " << mFixed.get_height() << std::endl;
}

void ExampleWindow::onClickButton()
{
  if(mCheckButton.get_active())
  {
    mImage.changeImage("images/image.jpg");
  }
  else
  {
    mImage.changeImage("images/pokemon.jpg");
  }
}
