#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window
{
public:
    HelloWorld();
    ~HelloWorld() override;

protected:
    // Signal handlers:
    void on_button_clicked();

    Gtk::Box mBox;
    Gtk::Button mButton00, mButton01;
};

#endif // GTKMM_EXAMPLE_HELLOWORLD_H