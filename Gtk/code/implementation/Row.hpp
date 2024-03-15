#ifndef ROW_HPP
#define ROW_HPP

#include <iostream>

#include <gtk/gtk.h>

#include "../design/iRow.hpp"
#include "aWidget.hpp"

class Row :
  public iRow,
  public aWidget
{
  public:
    Row(int padding);

    void addChild(std::shared_ptr<aWidget> child);
    void addChild(bool expand, bool fill, int padding, std::shared_ptr<aWidget> child);

  private:
    std::shared_ptr<GtkBox> mBox;
};

#endif //ROW_HPP