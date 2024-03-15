#include "Column.hpp"

Column::Column(int padding)
{
  mWidget = std::shared_ptr<GtkWidget>(gtk_box_new(GTK_ORIENTATION_VERTICAL, padding));
  mContainer = std::shared_ptr<GtkContainer>(GTK_CONTAINER(mWidget.get()));
  mBox = std::shared_ptr<GtkBox>(GTK_BOX(mWidget.get()));
}

void Column::show()
{
  aWidget::show();
}

void Column::addChild(std::shared_ptr<aWidget> child)
{
  gtk_box_pack_start(mBox.get(), child->getWidget().get(), false, false, 0);
}

void Column::addChild(bool expand, bool fill, int padding, std::shared_ptr<aWidget> child)
{
  gtk_box_pack_start(mBox.get(), child->getWidget().get(), expand, fill, padding);
}
