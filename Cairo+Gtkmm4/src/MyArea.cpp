#include "MyArea.hpp"

MyArea::MyArea(int width, int heigth) :
  mText("TEXTO INICIAL")
{
  set_content_width(width);
  set_content_height(heigth);

  set_draw_func(sigc::mem_fun(*this, &MyArea::onDraw));
}

MyArea::~MyArea()
{
}

void MyArea::changeText(Glib::ustring text)
{
  mText = text;
  queue_draw();
}

void MyArea::onDraw(const Cairo::RefPtr<Cairo::Context>& context, int width, int height)
{
  context->set_line_width(5);
  context->set_source_rgb(0.5, 0.1, 0.9);

  drawEllipseCentered(context, 400, 200, 10, 10);

  drawEllipseCentered(context, 400, 200, 100, 100);

  context->set_line_width(2);
  context->set_source_rgb(0.5, 0.5, 0.5);
  drawEllipseCentered(context, 100, 100, 10, 10);
  context->set_line_width(5);
  drawEllipse(context, 100, 100, 100, 100);
  // drawEllipseCentered(context, 400, 200, 10, 100, 45);
  // drawEllipseCentered(context, 400, 200, 100, 10);
  // drawEllipseCentered(context, 400, 200, 100, 10, 45);
  // drawEllipseCentered(context, 400, 200, 100, 100);
  // drawEllipseCentered(context, 400, 200, 200, 100);
  // drawEllipseCentered(context, 400, 200, 200, 100, 45);
  // drawEllipseCentered(context, 400, 200, 100, 200);
  // drawEllipseCentered(context, 400, 200, 100, 200, 45);
  
  drawEllipseCentered(context, 500, 500, 5, 5);

  drawEllipseCentered(context, 200, 550, 5, 5);
  context->set_source_rgb(0.8, 0.6, 0.1);
  drawRectangle(context, 200, 550, 200, 200, 20);
  drawRectangle(context, 200, 550, 200, 200, 20, 45);

  context->set_source_rgb(0.4, 0.23, 0.1);
  drawRectangleCentered(context, 200, 550, 200, 200, 0);
  drawRectangleCentered(context, 200, 550, 200, 200, 0, 45);
}

void MyArea::drawText(const Cairo::RefPtr<Cairo::Context> &context, Glib::ustring text, int xPosition,
                      int yPosition)
{
  // Pango::FontDescription sirve para establecer el tipo de fuente y diferentes características del texto 
  // como si es en negrita, cursiva, tamaño...
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::Weight::BOLD);

  // Creamos el Layout donde se pintara el texto. El tamaño del layout se calcurá en función del texto que 
  // tenga dentro
  Glib::RefPtr<Pango::Layout> layout = create_pango_layout(text);
  layout->set_font_description(font);

  // Nos posicionamos donde queremos pintar y pintamos
  context->move_to(xPosition, yPosition);
  layout->show_in_cairo_context(context);
}

void MyArea::drawTextCentered(const Cairo::RefPtr<Cairo::Context> &context, Glib::ustring text,
                                int xPosition, int yPosition)
{
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::Weight::BOLD);
  font.set_absolute_size(20 * PANGO_SCALE);

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

void MyArea::drawRectangle(const Cairo::RefPtr<Cairo::Context> &context, int x, int y, int width, int height, 
                           int roundedSize, double rotationAngleDegrees)
{
  if(roundedSize == 0)
  {
    drawSimpleRectangle(context, x, y, width, height, rotationAngleDegrees);
  }
  else
  {
    drawRoundedRectangle(context, x, y, width, height, roundedSize, rotationAngleDegrees);
  }
}

void MyArea::drawRectangleCentered(const Cairo::RefPtr<Cairo::Context> &context, int xCenter, int yCenter, 
                                   int width, int height, int roundedSize, double rotationAngleDegrees)
{
  int x = xCenter - width / 2;
  int y = yCenter - height / 2;
  
  if(roundedSize == 0)
  {
    drawSimpleRectangle(context, x, y, width, height, rotationAngleDegrees);
  }
  else
  {
    drawRoundedRectangle(context, x, y, width, height, roundedSize, rotationAngleDegrees);
  }
}

void MyArea::drawEllipse(const Cairo::RefPtr<Cairo::Context> &context, int x, int y, int width, int heigth, 
                         double rotationAngleDegrees)
{
  double xScale = width / 2;
  double yScale = heigth / 2;
  double xCenterElipse = 1;
  double yCenterElipse = 1;
  double radiusElipse = 1.0;
  double initAngleElipse = 0.0;
  double endAngleElipse = 2 * M_PI;
  double rotationAngleRadians = rotationAngleDegrees * M_PI / 180;

  Cairo::Matrix matrix;
  context->get_matrix(matrix);

  context->translate(x, y);
  context->rotate(rotationAngleRadians);
  context->scale(xScale, yScale);
  context->arc(xCenterElipse, yCenterElipse, radiusElipse, initAngleElipse, endAngleElipse);

  context->set_matrix(matrix);
  context->stroke();
}

void MyArea::drawSimpleRectangle(const Cairo::RefPtr<Cairo::Context> &context, int x, int y, int width, 
                                int height, double rotationAngleDegrees)
{
  double rotationAngleRadians = rotationAngleDegrees * M_PI / 180;
  double xCenter = x + width / 2.0;
  double yCenter = y + height / 2.0;

  std::vector<Point> points
  {
    {- width / 2.0, height / 2.0},
    {width / 2.0, height / 2.0},
    {width / 2.0, - height / 2.0},
    {- width / 2.0, - height / 2.0}
  };

  context->save();

  context->translate(xCenter, yCenter);
  context->rotate(rotationAngleRadians);

  context->move_to(points[0].x, points[0].y);
  context->line_to(points[1].x, points[1].y);
  context->line_to(points[2].x, points[2].y);
  context->line_to(points[3].x, points[3].y);
  context->close_path();
  context->stroke();

  context->restore();
}

void MyArea::drawRoundedRectangle(const Cairo::RefPtr<Cairo::Context> &context, int x, int y, int width, 
                                  int height, int roundedSize, double rotationAngleDegrees)
{
  // w A --- B z
  // H         C
  // |         |
  // G         D
  // x F --- E y
  double rotationAngleRadians = rotationAngleDegrees * M_PI / 180;
  double xCenter = x + width / 2.0;
  double yCenter = y + height / 2.0;

  std::vector<Point> points 
    {
      {-width / 2.0 + roundedSize, height / 2.0},
      {width / 2.0 - roundedSize, height / 2.0},
      {width / 2.0, height / 2.0 - roundedSize},
      {width / 2.0, -height / 2.0 + roundedSize},
      {width / 2.0 - roundedSize, -height / 2.0},
      {-width / 2.0 + roundedSize, -height / 2.0},
      {-width / 2.0, - height / 2.0 + roundedSize},
      {-width / 2.0, height / 2.0 - roundedSize}
    };
  
  std::vector<Point> controlPoints
  {
    {width / 2.0, height / 2.0},
    {width / 2.0, -height / 2.0},
    {-width / 2.0, - height / 2.0},
    {-width / 2.0, height / 2.0}
  };

  context->save();

  context->translate(xCenter, yCenter);
  context->rotate(rotationAngleRadians);

  context->move_to(points[0].x, points[0].y);
  context->line_to(points[1].x, points[1].y);
  context->curve_to(points[1].x, points[1].y, controlPoints[0].x, controlPoints[0].y, 
                    points[2].x, points[2].y);
  context->line_to(points[3].x, points[3].y);
  context->curve_to(points[3].x, points[3].y, controlPoints[1].x, controlPoints[1].y, 
                    points[4].x, points[4].y);
  context->line_to(points[5].x, points[5].y);
  context->curve_to(points[5].x, points[5].y, controlPoints[2].x, controlPoints[2].y, 
                    points[6].x, points[6].y);
  context->line_to(points[7].x, points[7].y);
  context->curve_to(points[7].x, points[7].y, controlPoints[3].x, controlPoints[3].y, 
                    points[0].x, points[0].y);
  context->stroke();

  context->restore();
}

void MyArea::drawEllipseCentered(const Cairo::RefPtr<Cairo::Context> &context, int xCenter, int yCenter, 
                                 int width, int heigth, double rotationAngleDegrees)
{
  double xScale = width / 2;
  double yScale = heigth / 2;
  double xCenterElipse = 0.0;
  double yCenterElipse = 0.0;
  double radiusElipse = 1.0;
  double initAngleElipse = 0.0;
  double endAngleElipse = 2 * M_PI;
  double rotationAngleRadians = rotationAngleDegrees * M_PI / 180;

  Cairo::Matrix matrix;
  context->get_matrix(matrix);

  context->translate(xCenter, yCenter);
  context->rotate(rotationAngleRadians);
  context->scale(xScale, yScale);
  context->arc(xCenterElipse, yCenterElipse, radiusElipse, initAngleElipse, endAngleElipse);

  context->set_matrix(matrix);
  context->stroke();
}
