set(SRC
  polygon.cpp
)

add_library(libpolyp SHARED ${SRC})
target_link_libraries(libpolyp m)
