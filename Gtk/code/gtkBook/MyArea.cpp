#include "MyArea.hpp"
#include <cairomm/context.h>
#include <giomm/resource.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>

MyArea::MyArea(Glib::ustring text) :
  mText(text)
{
  set_size_request (300, 300);
}

MyArea::~MyArea()
{
  
}

void MyArea::setText(Glib::ustring text)
{
  mText = text;
  force_redraw();
}

void MyArea::force_redraw()
{
  Glib::RefPtr<Gdk::Window> win = get_window();
  if (win)
  {
    Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
    win->invalidate_rect(r, false);
  }
}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context> &context)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  context->scale(width, height);

  context->set_source_rgb(1.0, 1.0, 1.0);

  context->

  draw_text_centered(context, mText, width / 2, height / 2);

  return true;
}

void MyArea::draw_text(const Cairo::RefPtr<Cairo::Context> &context, Glib::ustring text, int xPosition,
                       int yPosition)
{
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_BOLD);

  Glib::RefPtr<Pango::Layout> layout = create_pango_layout(text);
  layout->set_font_description(font);

  context->move_to(xPosition, yPosition);
  layout->show_in_cairo_context(context);
}

void MyArea::draw_text_centered(const Cairo::RefPtr<Cairo::Context> &context, Glib::ustring text,
                                int xPosition, int yPosition)
{
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_BOLD);
  font.set_absolute_size(20 * PANGO_SCALE);
  // font.set_size(20 * PANGO_SCALE);
  std::cout << font.get_size() << std::endl;

  Glib::RefPtr<Pango::Layout> layout = create_pango_layout(text);

  layout->set_font_description(font);

  int text_width;
  int text_height;
  layout->get_pixel_size(text_width, text_height);

  // Position the text in the middle
  double xText = (xPosition - text_width/2);
  double yText = (yPosition - text_height/2);
  context->move_to(xText, yText);
  layout->show_in_cairo_context(context);
}
