#ifndef MYIMAGE_HPP
#define MYIMAGE_HPP

#include <iostream>

#include <gtkmm.h>
#include <gdkmm.h>
#include <cairomm/context.h>

class MyImage :
  public Gtk::DrawingArea
{
  public:
    MyImage(Glib::ustring pathToImage, int width, int height);

    bool changeImage(Glib::ustring newImagePath);

  protected:
    void onDraw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height);

  private:
  void scaleImage(int width, int heigth);

    Glib::ustring mImagePath;
    Glib::RefPtr<Gdk::Pixbuf> mImage;
};

#endif // MYIMAGE_HPP