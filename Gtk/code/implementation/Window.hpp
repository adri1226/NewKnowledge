#ifndef WINDOW
#define WINDOW

#include <iostream>
#include <memory>

#include <gtk/gtk.h>

#include "../design/iWindow.hpp"
#include "aWidget.hpp"

class Window :
  public iWindow,
  public aWidget
{
  public:
    Window();
    ~Window();

    void show() override;
     
    void setSize(int width, int height) override;
    void setTitle(std::string title) override;

  private: 
    std::shared_ptr<GtkWindow> mWindow;
};

#endif // WINDOW