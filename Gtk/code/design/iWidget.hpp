#ifndef IWIDGET
#define IWIDGET

#include <iostream>
#include <memory>

class iWidget
{
  public:
    iWidget() = default;

    virtual void show() = 0;
};

#endif // IWIDGET