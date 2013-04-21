SET(TEST_SRC
  ${CMAKE_CURRENT_LIST_DIR}/test_point.cpp
)

ADD_EXECUTEABLE(test_point ${TEST_SRC})
TARGET_LINK_LIBRARIES(test_point libpolyp ${UNITTEST_LIBRARY})

ADD_TEST(TPoint test_point)