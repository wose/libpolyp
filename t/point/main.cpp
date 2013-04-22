#include <unittest/unittest.hpp>
#include "point.h"

int main () {
  using namespace unittest;

  test("point") = {
    task("constructors") = []{
      point p1;
      self.assert_almost_equal(p1.get_x(), 0.0, 7);
      self.assert_almost_equal(p1.get_y(), 0.0, 7);

      point p2(2.3, 4.2);
      self.assert_almost_equal(p2.get_x(), 2.3, 7);
      self.assert_almost_equal(p2.get_y(), 4.2, 7);
    },
    task("setter") = []{
      point p1;
      p1.set_x(2.3);
      p1.set_y(4.2);

      self.assert_almost_equal(p1.get_x(), 2.3, 7);
      self.assert_almost_equal(p1.get_y(), 4.2, 7);
    }
  };

  run();
}

