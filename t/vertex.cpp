#include <unittest/unittest.hpp>
#include "polyp.h"

int main() {
  using namespace unittest;

  test("vertex") = {
    task("default") = []{
      vertex v;
      self.assert_almost_equal(v.x, 0.0);
      self.assert_almost_equal(v.y, 0.0);
    },
    task("with x and y") = []{
      vertex v{23.0, 42.0};
      self.assert_almost_equal(v.x, 23.0);
      self.assert_almost_equal(v.y, 42.0);
    }
  };
}
