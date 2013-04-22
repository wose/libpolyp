#include "polygon.h"
#include <math.h>
#include <vector>

polygon::polygon()
{
}

polygon::~polygon()
{
}

void polygon::add(const double x, const double y)
{
  _points.push_back({x, y});
}

void polygon::add(const point& p)
{
  _points.push_back(p);
}

unsigned int polygon::get_point_count() const
{
  return _points.size();
}

double polygon::get_perimeter() const
{
  double perimeter = 0.0;

  for (auto ci = _points.cbegin(); ci < _points.cend() - 1; ++ci)
    {
      auto ti = ci + 1;
      perimeter += sqrt(pow(ci->get_x() - ti->get_x(), 2) +
                        pow(ci->get_y() - ti->get_y(), 2) );
    }
  auto first = _points.cbegin();
  auto last = _points.cend() -1;

  perimeter += sqrt(pow(first->get_x() - last->get_x(), 2) +
                   pow(first->get_y() - last->get_y(), 2) );

  return perimeter;
}

double polygon::get_area() const
{
  double area = 0.0;
  //$area += $_[0][0]*$_[1][1] - $_[0][1]*$_[1][0];
  for (auto ci = _points.cbegin(); ci < _points.cend() - 1; ++ci)
    {
      auto ti = ci + 1;
      area += ci->get_x() * ti->get_y() - ci->get_y() * ti->get_x();
    }
  auto first = _points.cbegin();
  auto last = _points.cend() -1;

  area += last->get_x() * first->get_y() - last->get_y() * first->get_x();

  return fabs(area) / 2;
}

void polygon::close()
{
  if(!_is_closed)
    {
      _points.push_back(*_points.cbegin());
      _is_closed = true;
    }
}

bool polygon::is_closed() const
{
  return _is_closed;
}
