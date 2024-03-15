#include "aWidget.hpp"

void aWidget::show()
{
  gtk_widget_show(mWidget.get());
}

void aWidget::addChild(std::shared_ptr<aWidget> child)
{
  gtk_container_add(mContainer.get(), child->getWidget().get());
}

std::shared_ptr<GtkWidget> aWidget::getWidget() const
{
  return mWidget;
}

std::shared_ptr<GtkContainer> aWidget::getContainer() const
{
  return mContainer;
}
