set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        fractimage.cpp
#        juliaset.cpp
#        juliasquared.cpp
#        juliacosh.cpp
#        juliaexp.cpp
#        juliapower4.cpp
#        mandelbrotset.cpp
#        mandelbrot.cpp
#        lyapset.cpp
#        lyapunov.cpp
        bifurset.cpp
        bifurcation.cpp
        unisin.cpp
        unipisin.cpp
        uni1minussquare.cpp
        unixcubed.cpp
        unixquater.cpp
        unilyaplike.cpp
        unitent.cpp
)

add_library(creators STATIC ${PROJECT_SOURCES})
