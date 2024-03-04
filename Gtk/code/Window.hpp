#ifndef WINDOW
#define WINDOW

#include <iostream>
#include <memory>

#include <gtk/gtk.h>

#include "iWindow.hpp"

class Window :
  public iWindow
{
  public:
    Window();
    ~Window();

    void show() override;
    void addChild(std::shared_ptr<iGraphicElement> child) override;
    void addChild(std::shared_ptr<GtkWidget> child);
     
    void setSize(int width, int height) override;
    void setTitle(std::string title) override;

  private: 
    std::shared_ptr<GtkWidget> mWidget;
    std::shared_ptr<GtkContainer> mContainer;
    std::shared_ptr<GtkWindow> mWindow;
};

#endif // WINDOW