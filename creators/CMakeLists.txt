set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        fractimage.cpp
        juliaset.cpp
        juliasquared.cpp
)

add_library(creators STATIC ${PROJECT_SOURCES})
