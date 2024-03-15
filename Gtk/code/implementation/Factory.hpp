#ifndef FACTORY
#define FACTORY

#include <memory>

#include <gtk/gtk.h>

class Factory
{
  public:
    Factory() = default;

    std::shared_ptr<GtkWidget> createGtkWindow();
    std::shared_ptr<GtkContainer> toContainer(std::shared_ptr<GtkWidget> gtkWidget);
};

#endif // FACTORY