#ifndef IWINDOW
#define IWINDOW

#include <iostream>
#include <memory>

#include "iWidget.hpp"

class iWindow :
  public iWidget
{
  public:
    iWindow() = default;
    
    virtual void setSize(int width, int height) = 0;
    virtual void setTitle(std::string title) = 0;
};

#endif // IWINDOW