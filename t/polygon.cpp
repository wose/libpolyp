#include <unittest/unittest.hpp>
#include "polyp.h"

int main ()
{
  using namespace unittest;

  polygon rectangle = {{-2, -1}, {-2, 1}, {2, 1}, {2, -1}};
  polygon square    = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
  polygon hexagon   = {{0, -2}, {sqrt(3), -1}, {sqrt(3), 1}, {0, 2},
                       {-sqrt(3), 1}, {-sqrt(3), -1}};


  test("polygon") = {
    task("default") = []{
      polygon p;
      self.assert_equal(p.size(), 0);
    },
    task("initializer list do not close") = []{
      polygon p({{-1, -1}, {-1, 1}, {1, 1}, {1, -1}}, false);

      self.assert_equal(p.size(), 4);
      self.assert_false(p.is_closed());
    },
    task("initializer list close") = []{
      polygon p({{-1, -1}, {-1, 1}, {1, 1}, {1, -1}});

      self.assert_equal(p.size(), 4);
      self.assert_true(p.is_closed());
    }
  };

  test("push_back") = {
    task("push_back double") = []{
      polygon p;

      p.push_back(-1, -1);
      self.assert_equal(p.size(), 1);
      p.push_back(-1, 1);
      self.assert_equal(p.size(), 2);
    },
    task("push_back vertex") = []{
      polygon p;

      p.push_back(vertex{1, 1});
      self.assert_equal(p.size(), 1);
      
      vertex v{1, -1};
      p.push_back(v);
      self.assert_equal(p.size(), 2);
      p.push_back({0, -2});
      self.assert_equal(p.size(), 3);
    }
  };

  test("close") = {
    task("is_closed") = []{
      polygon p;
      self.assert_false(p.is_closed());
    },
    task("close") = []{
      polygon p;
      p.push_back({-1, -1});
      p.push_back({-1, 1});
      p.push_back({0, 0});

      p.close();
      self.assert_true(p.is_closed());
    }
  };

  test("area") = {
    task("area") = [=]{
      self.assert_almost_equal(rectangle.area(), 8.0);
      self.assert_almost_equal(square.area(), 4.0);
      self.assert_almost_equal(hexagon.area(), 10.3923, 4.0);
    }
  };

  test("perimeter") = {
    task("perimeter") = [=]{
      self.assert_almost_equal(rectangle.perimeter(), 12.0);
      self.assert_almost_equal(square.perimeter(), 8.0);
      self.assert_almost_equal(hexagon.perimeter(), 12.0);
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

