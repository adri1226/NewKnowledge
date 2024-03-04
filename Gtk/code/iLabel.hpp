#ifndef ILABEL
#define ILABEL

#include <iostream>
#include <memory>

#include "iGraphicElement.hpp"

class iLabel :
  public iGraphicElement
{
  public:
    iLabel() = default;

    virtual void setText(std::string text) = 0;
};

#endif // ILABEL