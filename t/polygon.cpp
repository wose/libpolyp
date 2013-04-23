#include <unittest/unittest.hpp>
#include "point.h"
#include "polygon.h"

int main () {
  using namespace unittest;

  test("polygon building") = {
    task("constructors") = []{
      polygon p1;
      self.assert_equal(p1.get_point_count(), 0);
    },
    task("add_points1") = []{
      polygon p1;
      p1.add(-1.0, -1.0);
      self.assert_equal(p1.get_point_count(), 1);
      p1.add(-1.0, 1.0);
      self.assert_equal(p1.get_point_count(), 2);
    },
    task("add_points2") = []{
      polygon p1;
      p1.add(point(-1.0, -1.0));
      self.assert_equal(p1.get_point_count(), 1);
      
      point poi1(-1.0, 1.0);
      p1.add(poi1);
      self.assert_equal(p1.get_point_count(), 2);
      p1.add({1.0, 1.0});
      self.assert_equal(p1.get_point_count(), 3);
    }
  };

  test("polygon properties") = {
    task("is_closed") = []{
      polygon p1;
      p1.add(-1.0, -1.0);
      p1.add(-1.0, 1.0);
      p1.add(1.0, 1.0);
      p1.add(1.0, -1.0);
      
      self.assert_false(p1.is_closed());
      p1.close();
      self.assert_true(p1.is_closed());
    },
    task("area") = []{
      polygon p1;
      p1.add(-1.0, -1.0);
      p1.add(-1.0, 1.0);
      p1.add(1.0, 1.0);
      p1.add(1.0, -1.0);

      self.assert_almost_equal(p1.get_area(), 4.0);
    },
    task("perimeter square") = []{
      polygon p1;
      p1.add(-1.0, -1.0);
      p1.add(-1.0, 1.0);
      p1.add(1.0, 1.0);
      p1.add(1.0, -1.0);

      self.assert_almost_equal(p1.get_perimeter(), 8.0);
    },
    task("perimeter rectangle") = []{
      polygon p1;
      p1.add(-2.0, -1.0);
      p1.add(-2.0, 1.0);
      p1.add(2.0, 1.0);
      p1.add(2.0, -1.0);

      self.assert_almost_equal(p1.get_perimeter(), 12.0);
    }
  };

  /*  test("polygon convex concav") = {
    task("is_polygon_convex") = []{
      //      self.fail("not implemented");
    },
    task("is_polygon_concav") = []{
      //self.fail("not implemented");
    }
  };
  */
  run();
}

