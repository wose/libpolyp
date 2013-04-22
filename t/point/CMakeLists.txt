set(TEST_SRC
  ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

add_executable(test_point ${TEST_SRC})
target_link_libraries(test_point libpolyp ${UNITTEST_LIBRARY})

add_test(Point test_point)