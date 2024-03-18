#ifndef MYAREA_HPP
#define MYAREA_HPP

#include <iostream>

#include <gtkmm.h>
#include <gdkmm.h>
#include <cairomm/context.h>

class MyArea : 
  public Gtk::DrawingArea
{
  private:
    struct Point 
    {
      double x;
      double y;
    };

  public:
    MyArea(int width, int heigth);
    virtual ~MyArea();

    void changeText(Glib::ustring text);

    void drawRectangle(const Cairo::RefPtr<Cairo::Context> &context, int x, int y, int width, int height,
                       int roundedSize = 0, double rotationAngleDegrees = 0);
    void drawRectangleCentered(const Cairo::RefPtr<Cairo::Context> &context, int xCenter, int yCenter, 
                               int width, int height, int roundedSize = 0, double rotationAngleDegrees = 0);
    void drawEllipse(const Cairo::RefPtr<Cairo::Context> &context, int x, int y, int width, int heigth, 
                     double rotationAngleDegrees = 0);
    void drawEllipseCentered(const Cairo::RefPtr<Cairo::Context> &context, int xCenter, int yCenter, int width, 
                      int heigth, double rotationAngleDegrees = 0);

  protected:
    void onDraw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height);

  private:
    void drawText(const Cairo::RefPtr<Cairo::Context> &context, Glib::ustring text, int xPosition, 
                  int yPosition);
    void drawTextCentered(const Cairo::RefPtr<Cairo::Context> &context, Glib::ustring text,
                          int xPosition, int yPosition);
    void drawSimpleRectangle(const Cairo::RefPtr<Cairo::Context> &context, int x, int y, int width, 
                             int height, double rotationAngleDegrees = 0);
    void drawRoundedRectangle(const Cairo::RefPtr<Cairo::Context> &context, int x, int y, int width, 
                              int height, int roundedSize, double rotationAngleDegrees = 0);

    Glib::ustring mText;
};

#endif // MYAREA_HPP