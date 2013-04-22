#ifndef _POLYP_POLYGON_H_
#define _POLYP_POLYGON_H_

#include <vector>
#include "point.h"

class polygon {
 public:
  polygon();
  ~polygon();

 private:
  std::vector<point> _points;
  bool _is_closed;

 public:
  void add(const double x, const double y);
  void add(const point& p);
  unsigned int get_point_count() const;

  double get_perimeter() const;
  double get_area() const;

  bool is_closed() const;
  void close();
};

#endif
