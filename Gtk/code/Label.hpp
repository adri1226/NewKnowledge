#ifndef LABEL
#define LABEL

#include <iostream>
#include <memory>

#include <gtk/gtk.h>

#include "iLabel.hpp"

class Label :
  public iLabel
{
  public:
    Label(std::string text);

    void show() override;
    void setText(std::string text) override;

  private: 
    std::shared_ptr<GtkWidget> mWidget;
    std::shared_ptr<GtkContainer> mContainer;
    std::shared_ptr<GtkLabel> mLabel;
};

#endif // LABEL