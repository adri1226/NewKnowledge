#include "Window.hpp"

Window::Window()
{
  mWidget = std::shared_ptr<GtkWidget>(gtk_window_new(GTK_WINDOW_TOPLEVEL));
  mContainer = std::shared_ptr<GtkContainer>(GTK_CONTAINER(mWidget.get()));
  mWindow = std::shared_ptr<GtkWindow>(GTK_WINDOW(mWidget.get()));

  g_signal_connect(mWidget.get(), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
}

Window::~Window()
{
  mContainer.reset();
  mWindow.reset();
  mWidget.reset();
}

void Window::show()
{
  gtk_widget_show_all(mWidget.get());
}

void Window::addChild(std::shared_ptr<iGraphicElement> child)
{
  // gtk_container_add(mContainer.get(), child.get());
}

void Window::addChild(std::shared_ptr<GtkWidget> child)
{
  gtk_container_add(mContainer.get(), child.get());
}

void Window::setSize(int width, int height)
{
  gtk_widget_set_size_request(mWidget.get(), width, height);
}

void Window::setTitle(std::string title)
{
  gtk_window_set_title(mWindow.get(), title.c_str());
}