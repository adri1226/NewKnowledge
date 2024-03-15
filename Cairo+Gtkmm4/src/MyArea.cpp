#include "MyArea.hpp"

MyArea::MyArea() :
  mText("TEXTO INICIAL")
{
  set_draw_func(sigc::mem_fun(*this, &MyArea::onDraw));
  set_content_width(200);
  set_content_height(200);
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

  drawEllipse(context, 400, 200, 10, 10);
  drawEllipse(context, 400, 200, 10, 100);
  drawEllipse(context, 400, 200, 10, 100, 45);
  drawEllipse(context, 400, 200, 100, 10);
  drawEllipse(context, 400, 200, 100, 10, 45);
  drawEllipse(context, 400, 200, 100, 100);
  drawEllipse(context, 400, 200, 200, 100);
  drawEllipse(context, 400, 200, 200, 100, 45);
  drawEllipse(context, 400, 200, 100, 200);
  drawEllipse(context, 400, 200, 100, 200, 45);
  
  drawEllipse(context, 500, 500, 5, 5);
  // context->set_source_rgb(0.1, 0.9, 0.5);
  // drawRectangle(context, 500, 500, 200, 100, 25);
  // drawRectangleCentered(context, 500, 500, 200, 100, 25);

  drawEllipse(context, 200, 700, 5, 5);
  context->set_source_rgb(0.3, 0.6, 0.1);
  drawRectangle(context, 200, 700, 200, 200, 20);
  drawRectangle(context, 200, 700, 200, 200, 20, 45);

  context->set_source_rgb(0.1, 0.23, 0.1);
  drawRectangleCentered(context, 200, 700, 200, 200, 40);
  drawRectangleCentered(context, 200, 700, 200, 200, 40, 45);
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

void MyArea::drawSimpleRectangle(const Cairo::RefPtr<Cairo::Context> &context, int x, int y, int width, 
                                int height, double rotationAngleDegrees)
{
  double rotationAngleRadians = rotationAngleDegrees * M_PI / 180;
  double xCenter = x + width / 2.0;
  double yCenter = y + height / 2.0;

  int xInitialPoint = - width / 2;
  int yInitialPoint = height / 2;
  int xSecondPoint = width / 2;
  int ySecondPoint = height / 2;
  int xThirdPoint = width / 2;
  int yThirdPoint = - height / 2;
  int xFourthPoint = - width / 2;
  int yFourthPoint = - height / 2;

  context->save();
  context->translate(xCenter, yCenter);
  context->rotate(rotationAngleRadians);
  context->move_to(xInitialPoint, yInitialPoint);
  context->line_to(xSecondPoint, ySecondPoint);
  context->line_to(xThirdPoint, yThirdPoint);
  context->line_to(xFourthPoint, yFourthPoint);
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
  context->line_to(width / 2 - roundedSize, height / 2);

  context->curve_to(width / 2 - roundedSize, height / 2, width / 2, height / 2, width / 2, height / 2 - roundedSize);
  context->line_to(width / 2, -height / 2 + roundedSize);

  context->curve_to(width / 2, -height / 2 + roundedSize, width / 2, -height / 2, width / 2 - roundedSize, -height / 2);
  context->line_to(-width / 2 + roundedSize, -height / 2);

  context->curve_to(-width / 2 + roundedSize, - height / 2, -width / 2, - height / 2, -width / 2, - height / 2 + roundedSize);
  context->line_to(-width / 2, height / 2 - roundedSize);

  context->curve_to(-width / 2, height / 2 - roundedSize, -width / 2, height / 2, -width / 2 + roundedSize, height / 2);
  context->stroke();

  context->restore();
}

void MyArea::drawEllipse(const Cairo::RefPtr<Cairo::Context> &context, int xCenter, int yCenter, int width,
                         int heigth, double rotationAngleDegrees)
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
