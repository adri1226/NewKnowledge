#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H

#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

#include "MyImage.hpp"

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea(Glib::ustring text);
  virtual ~MyArea();

  void setText(Glib::ustring text);

protected:
  // Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context> &context) override;

private:
  void force_redraw();
  void draw_text(const Cairo::RefPtr<Cairo::Context> &context, Glib::ustring text, int xPosition,
                 int yPosition);
  void draw_text_centered(const Cairo::RefPtr<Cairo::Context> &context, Glib::ustring text, int xPosition,
                          int yPosition);

  Glib::ustring mText;
};

#endif // GTKMM_EXAMPLE_MYAREA_H