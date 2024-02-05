set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        common/fractimage.cpp
#        juliaset.cpp
#        juliasquared.cpp
#        juliacosh.cpp
#        juliaexp.cpp
#        juliapower4.cpp
#        mandelbrotset.cpp
#        mandelbrot.cpp
#        lyapset.cpp
#        lyapunov.cpp
        experiments/bifurcation/bifurset.cpp
        experiments/bifurcation/bifurcation.cpp
        experiments/universality/unisin.cpp
        experiments/universality/unipisin.cpp
        experiments/universality/uni1minussquare.cpp
        experiments/universality/unixcubed.cpp
        experiments/universality/unixquater.cpp
        experiments/universality/unilyaplike.cpp
        experiments/universality/unitent.cpp
)

add_library(creators STATIC ${PROJECT_SOURCES})
