#ifndef ILABEL
#define ILABEL

#include <iostream>
#include <memory>

#include "iWidget.hpp"

class iLabel :
  public iWidget
{
  public:
    iLabel() = default;

    virtual void setText(std::string text) = 0;
};

#endif // ILABEL