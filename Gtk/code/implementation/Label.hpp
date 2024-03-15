#ifndef LABEL
#define LABEL

#include <iostream>
#include <memory>

#include <gtk/gtk.h>

#include "../design/iLabel.hpp"
#include "aWidget.hpp"

class Label :
  public iLabel,
  public aWidget
{
  public:
    Label(std::string text);

    void show() override;
    void setText(std::string text) override;

  private:
    std::shared_ptr<GtkLabel> mLabel;
};

#endif // LABEL