#ifndef _POLYP_POINT_H_
#define _POLYP_POINT_H_

class point {

public:
  point();
  point(double x, double y);
  ~point();

private:
  double _x;
  double _y;

public:
  double get_x() const {return x;};
  void set_x(double x);

  double get_y() const {return y;};
  void set_y(double y);
};

#endif
