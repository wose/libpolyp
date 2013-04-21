#include <unittest/unittest.hpp>

int main () {
  using namespace unittest;

  test("my-first-test") = {
    task("first-task") = []{ self.fail("Not Yet Implemented"); },
    task("second-task") = []{ self.fail("Not Yet Implemented"); }
  };

  run();
}

