set(TEST_SRC
  point.cpp
  polygon.cpp
  )

foreach(TEST_FILE ${TEST_SRC})
  get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
  set(TEST_EXE "${TEST_NAME}_test")
  add_executable(${TEST_EXE} ${TEST_FILE})
  target_link_libraries(${TEST_EXE} libpolyp ${UNITTEST_LIBRARY})
  add_test(${TEST_NAME} ${TEST_EXE})
endforeach()

