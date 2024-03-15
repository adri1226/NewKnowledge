#include <ctime>
#include <cmath>
#include <cairomm/context.h>
#include <glibmm/main.h>
#include "clock.hpp"

Clock::Clock() : 
  m_radius(0.42), m_line_width(0.05)
{
  Glib::signal_timeout().connect(sigc::mem_fun(*this, &Clock::on_timeout), 1000);
}

Clock::~Clock()
{
}

bool Clock::on_draw(const Cairo::RefPtr<Cairo::Context> &cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  // scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
  // the center of the window
  cr->scale(width, height);
  cr->translate(0.5, 0.5);
  cr->set_line_width(m_line_width);

  cr->save();
  cr->set_source_rgba(0.337, 0.612, 0.117, 0.9); // green
  cr->paint();
  cr->restore();

  cr->arc(0, 0, m_radius, 0, 2 * M_PI);

  cr->save();
  cr->set_source_rgba(1.0, 1.0, 1.0, 0.8);
  cr->fill_preserve();
  cr->restore();

  cr->stroke_preserve();
  cr->clip();

  double angleHourIncrement = M_PI / 6; // 360/12, porque quiero hacer 12 marcas en el reloj

  // clock ticks
  for (int i = 0; i < 12; i++)
  {
    double hourMarkOffset = 0.05;
    bool isHourMark = i % 3 != 0;

    cr->save();
    cr->set_line_cap(Cairo::LINE_CAP_ROUND);

    if (isHourMark)
    {
      hourMarkOffset *= 0.8;
      cr->set_line_width(0.03);
    }

    // Transform the start and end Polar coordinates into Cartesians coordinates
    double startX = (m_radius - hourMarkOffset) * cos(i * angleHourIncrement);
    double startY = (m_radius - hourMarkOffset) * sin(i * angleHourIncrement);
    double endX = m_radius * cos(i * angleHourIncrement);
    double endY = m_radius * sin(i * angleHourIncrement);

    // Draw the mark of the hours
    cr->move_to(startX, startY);
    cr->line_to(endX, endY);
    cr->stroke();
    cr->restore(); /* stack-pen-size */
  }

  // store the current time
  time_t rawtime;
  time(&rawtime);
  struct tm *timeinfo = localtime(&rawtime);

  double angleMinuteIncrement = M_PI / 30; // 360/60, porque quiero hacer 60 marcas en el reloj

  // compute the angles of the indicators of our clock
  double minutes = timeinfo->tm_min * angleMinuteIncrement;
  double hours = timeinfo->tm_hour * angleHourIncrement;
  double seconds = timeinfo->tm_sec * angleMinuteIncrement;

  cr->save();
  cr->set_line_cap(Cairo::LINE_CAP_ROUND);

  // draw the seconds hand
  double secondsHandX = (m_radius * 0.9) * sin(seconds);
  double secondsHandY = (m_radius * 0.9) * -cos(seconds);
  cr->save();
  cr->set_line_width(m_line_width / 3);
  cr->set_source_rgba(0.7, 0.7, 0.7, 0.8); // gray
  cr->move_to(0, 0);
  cr->line_to(secondsHandX, secondsHandY);
  cr->stroke();
  cr->restore();

  // draw the minutes hand
  double minutesHandX = (m_radius * 0.8) * sin(minutes + seconds / 60);
  double minutesHandY = (m_radius * 0.8) * -cos(minutes + seconds / 60);
  cr->set_source_rgba(0.117, 0.337, 0.612, 0.9); // blue
  cr->move_to(0, 0);
  cr->line_to(minutesHandX, minutesHandY);
  cr->stroke();

  // draw the hours hand
  double hoursHandX = (m_radius * 0.5) * sin(hours + minutes / 12.0);
  double hoursHandY = (m_radius * 0.5) * -cos(hours + minutes / 12.0);
  cr->set_source_rgba(0.337, 0.612, 0.117, 0.9); // green
  cr->move_to(0, 0);
  cr->line_to(hoursHandX, hoursHandY);
  cr->stroke();
  cr->restore();

  // draw a little dot in the middle
  cr->arc(0, 0, m_line_width / 3.0, 0, 2 * M_PI);
  cr->fill();

  return true;
}

bool Clock::on_timeout()
{
  // force our program to redraw the entire clock.
  auto win = get_window();
  if (win)
  {
    Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
    win->invalidate_rect(r, false);
  }
  return true;
}