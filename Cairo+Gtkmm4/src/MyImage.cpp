#include "MyImage.hpp"

MyImage::MyImage(Glib::ustring pathToImage, int width, int height) :
  mImagePath(pathToImage)
{
  set_content_width(width);
  set_content_height(height);

  changeImage(mImagePath);

  set_draw_func(sigc::mem_fun(*this, &MyImage::onDraw));
}

bool MyImage::changeImage(Glib::ustring newImagePath)
{
  Glib::RefPtr<Gdk::Pixbuf> newImage;
  try
  {
    newImage = Gdk::Pixbuf::create_from_file(newImagePath);
  }
  catch(const Gio::ResourceError& ex)
  {
    std::cerr << "ResourceError: " << ex.what() << std::endl;
    return false;
  }
  catch(const Gdk::PixbufError& ex)
  {
    std::cerr << "PixbufError: " << ex.what() << std::endl;
    return false;
  }

  mImage = newImage;

  scaleImage(get_content_width(), get_content_height());

  queue_draw();

  return true;
}

void MyImage::onDraw(const Cairo::RefPtr<Cairo::Context> &context, int width, int height)
{
  if (!mImage)
  {
    return;
  }

  double pixbufWidth = (width - mImage->get_width()) / 2;
  double pixbufHeigth = (height - mImage->get_height()) / 2;

  Gdk::Cairo::set_source_pixbuf(context, mImage, pixbufWidth, pixbufHeigth);
  context->paint();
}

void MyImage::scaleImage(int width, int heigth)
{
  if(mImage)
  {
    mImage = mImage->scale_simple(width, heigth, Gdk::InterpType::TILES);
  }
}
