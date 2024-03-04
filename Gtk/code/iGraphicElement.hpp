#ifndef IGRAPHICELEMENT
#define IGRAPHICELEMENT

#include <iostream>
#include <memory>

class iGraphicElement
{
  public:
    iGraphicElement() = default;

    virtual void show() = 0;
};

#endif // IGRAPHICELEMENT