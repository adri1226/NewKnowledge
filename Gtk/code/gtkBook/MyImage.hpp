#ifndef GTKMM_EXAMPLE_MYIMAGE_HPP
#define GTKMM_EXAMPLE_MYIMAGE_HPP

#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

class MyImage : public Gtk::DrawingArea
{
public:
  MyImage();
  virtual ~MyImage();

protected:
  // Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context> &context) override;

private:
  void force_redraw();
};

#endif // GTKMM_EXAMPLE_MYIMAGE_HPP