#include "point.h"

point::point():
  _x(0.0),
  _y(0.0)
{
}

point::point(double x, double y):
  _x(x),
  _y(y)
{
}

point::~point()
{
}

void point::set_x(double x)
{
  _x= x;
}

void point::set_y(double y)
{
  _y= y;
}

