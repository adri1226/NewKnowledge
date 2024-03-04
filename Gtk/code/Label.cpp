#include "Label.hpp"

Label::Label(std::string text)
{
  mWidget =  std::shared_ptr<GtkWidget>(gtk_label_new(text.c_str()));
  mContainer = std::shared_ptr<GtkContainer>(GTK_CONTAINER(mWidget.get()));
  mLabel = std::shared_ptr<GtkLabel>(GTK_LABEL(mWidget.get()));
}

void Label::show()
{
  gtk_widget_show(mWidget.get());
}

void Label::setText(std::string text)
{
  gtk_label_set_text(mLabel.get(), text.c_str());
}
