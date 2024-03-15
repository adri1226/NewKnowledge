#ifndef AWIDGET
#define AWIDGET

#include <iostream>
#include <memory>

#include <gtk/gtk.h>

#include "../design/iWidget.hpp"

class aWidget :
  public iWidget
{
  public:
    aWidget() = default;

    void show() override;
    void addChild(std::shared_ptr<aWidget> child);

    std::shared_ptr<GtkWidget> getWidget() const;
    std::shared_ptr<GtkContainer> getContainer() const;

  protected:
    std::shared_ptr<GtkWidget> mWidget;
    std::shared_ptr<GtkContainer> mContainer;
};

#endif // AWIDGET