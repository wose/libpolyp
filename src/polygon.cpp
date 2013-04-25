#include "libpolyp/vertex.h"
#include "libpolyp/polygon.h"
#include <math.h>
#include <vector>

polygon::polygon()
{
}

polygon::polygon(std::initializer_list<vertex> il, bool close_polygon)
{
  for(auto v : il)
    _vertices.push_back(v);
  if(close_polygon)
    close();
}

polygon::~polygon()
{
}

void polygon::push_back(const double x, const double y)
{
  _vertices.push_back({x, y});
}

void polygon::push_back(const vertex& p)
{
  _vertices.push_back(p);
}

unsigned int polygon::size() const
{
  return _is_closed ? _vertices.size() - 1 : _vertices.size();
}

std::vector<vertex>::iterator polygon::begin()
{
  return _vertices.begin();
}

std::vector<vertex>::iterator polygon::end()
{
  return _vertices.end();
}

double polygon::perimeter() const
{
  double perimeter = 0.0;

  for (auto ci = _vertices.cbegin(); ci < _vertices.cend() - 1; ++ci)
    {
      auto ti = ci + 1;
      perimeter += sqrt(pow(ci->x - ti->x, 2) +
                        pow(ci->y - ti->y, 2) );
    }

  return perimeter;
}

double polygon::area() const
{
  double area = 0.0;

  for (auto ci = _vertices.cbegin(); ci < _vertices.cend() - 1; ++ci)
    {
      auto ti = ci + 1;
      area += ci->x * ti->y - ci->y * ti->x;
    }

  return fabs(area) / 2;
}

void polygon::close()
{
  if(!_is_closed)
    {
      _vertices.push_back(*_vertices.cbegin());
      _is_closed = true;
    }
}

bool polygon::is_closed() const
{
  return _is_closed;
}
