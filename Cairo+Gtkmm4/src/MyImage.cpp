#include "MyImage.hpp"

MyImage::MyImage(Glib::ustring pathToImage) :
  mImagePath(pathToImage)
{
  try
  {
    mImage = Gdk::Pixbuf::create_from_file(mImagePath);
  }
  catch(const Gio::ResourceError& ex)
  {
    std::cerr << "ResourceError: " << ex.what() << std::endl;
  }
  catch(const Gdk::PixbufError& ex)
  {
    std::cerr << "PixbufError: " << ex.what() << std::endl;
  }

  set_content_width(1280);
  set_content_height(720);

  std::cout << "MyImage tamaño: " << get_width() << ", " << get_height() << std::endl;

  if(mImage)
  {
    mImage = mImage->scale_simple(1280, 720, Gdk::InterpType::NEAREST);
  }

  set_draw_func(sigc::mem_fun(*this, &MyImage::onDraw));
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
