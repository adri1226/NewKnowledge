#ifndef MYAREATEST_HPP
#define MYAREATEST_HPP

#include <iostream>

#include <gtkmm.h>
#include <gdkmm.h>
#include <cairomm/context.h>

class MyAreaTest : 
  public Gtk::DrawingArea
{
  public:
    MyAreaTest(int width, int heigth);
    virtual ~MyAreaTest();

  protected:
    void onDraw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height);
};

#endif // MYAREATEST_HPP