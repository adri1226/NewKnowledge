#ifndef IWINDOW
#define IWINDOW

#include <iostream>
#include <memory>

#include "iGraphicElement.hpp"

class iWindow :
  public iGraphicElement
{
  public:
    iWindow() = default;

    virtual void addChild(std::shared_ptr<iGraphicElement> child) = 0;
    
    virtual void setSize(int width, int height) = 0;
    virtual void setTitle(std::string title) = 0;
};

#endif // IWINDOW