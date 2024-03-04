#include <memory>
#include <iostream>

#include <gtk/gtk.h>

#include "Window.hpp"
#include "Label.hpp"

void buttonClicked(std::shared_ptr<GtkWidget> widget, gpointer data)
{
  gtk_label_set_text(GTK_LABEL(data), "Se ha pulsado el boton");
}

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  Window mainWindow;

  mainWindow.setTitle("Esto es una prueba");
  mainWindow.setSize(350, 120);

  std::shared_ptr<GtkWidget> labelWidget(gtk_label_new("Label columna 1"));
  std::shared_ptr<GtkWidget> labelWidget2(gtk_label_new("Label Columna 2"));
  
  std::shared_ptr<GtkWidget> buttonWidget(gtk_button_new_with_label("Click me"));
  std::shared_ptr<GtkWidget> buttonWidget2(gtk_button_new_with_label("Click me"));
  g_signal_connect(buttonWidget.get(), "clicked", G_CALLBACK(buttonClicked), labelWidget.get());

  std::shared_ptr<GtkWidget> verticalBoxWidget(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
  std::shared_ptr<GtkWidget> horizontalBoxWidget(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0));
  std::shared_ptr<GtkWidget> horizontalBoxWidget2(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0));

  g_signal_connect(buttonWidget.get(), "clicked", G_CALLBACK(buttonClicked), (gpointer) labelWidget.get());

  std::shared_ptr<GtkBox> horizontalBox(GTK_BOX(verticalBoxWidget.get()));
  gtk_box_pack_start(horizontalBox.get(), labelWidget.get(), false, false, 10);
  gtk_box_pack_start(horizontalBox.get(), buttonWidget.get(), false, false, 10);

  mainWindow.addChild(verticalBoxWidget);

  mainWindow.show();
  
  gtk_main();
  return 0;
}
