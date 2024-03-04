#include "Factory.hpp"

std::shared_ptr<GtkWidget> Factory::createGtkWindow()
{
  return std::shared_ptr<GtkWidget>(gtk_window_new(GTK_WINDOW_TOPLEVEL));
}

std::shared_ptr<GtkContainer> Factory::toContainer(std::shared_ptr<GtkWidget> gtkWidget)
{
  return std::shared_ptr<GtkContainer>(GTK_CONTAINER(gtkWidget.get()));
}
