SET(TEST_SRC
  ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

ADD_EXECUTABLE(test_polygon ${TEST_SRC})
TARGET_LINK_LIBRARIES(test_polygon libpolyp ${UNITTEST_LIBRARY})

ADD_TEST(Polygon test_polygon)