#include "MyImage.hpp"
#include <cairomm/context.h>
#include <giomm/resource.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>

MyImage::MyImage()
{
  // set_size_request (300, 300);
}

MyImage::~MyImage()
{
}

void MyImage::force_redraw()
{
  Glib::RefPtr<Gdk::Window> win = get_window();
  if (win)
  {
    Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
    win->invalidate_rect(r, false);
  }
}

bool MyImage::on_draw(const Cairo::RefPtr<Cairo::Context> &context)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file("images/image.jpg");
  Gdk::Cairo::set_source_pixbuf(context, image, 0, 0);
  context->paint();

  set_size_request (image->get_width(), image->get_height());

  return true;
}