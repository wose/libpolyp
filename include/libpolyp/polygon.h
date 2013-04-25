#ifndef _POLYP_POLYGON_H_
#define _POLYP_POLYGON_H_

#include <vector>
#include "vertex.h"

class polygon {
 public:
  polygon();
  polygon(std::initializer_list<vertex> il, bool close_polygon = true);
  ~polygon();

 private:
  std::vector<vertex> _vertices;
  std::vector<vertex> _bounding_box;
  bool _is_closed = false;

 public:
  void push_back(const double x, const double y);
  void push_back(const vertex& p);
  std::vector<vertex>::iterator begin();
  std::vector<vertex>::iterator end();
  unsigned int size() const;

  double perimeter() const;
  double area() const;

  bool is_closed() const;
  void close();
};

#endif
