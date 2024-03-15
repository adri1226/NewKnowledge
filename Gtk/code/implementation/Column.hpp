#ifndef COLUMN_HPP
#define COLUMN_HPP

#include <iostream>

#include <gtk/gtk.h>

#include "../design/iColumn.hpp"
#include "aWidget.hpp"

class Column :
  public iColumn,
  public aWidget
{
  public:
    Column(int padding);

    void show() override;
    void addChild(std::shared_ptr<aWidget> child);
    void addChild(bool expand, bool fill, int padding, std::shared_ptr<aWidget> child);

  private:
    std::shared_ptr<GtkBox> mBox;
};

#endif //COLUMN_HPP