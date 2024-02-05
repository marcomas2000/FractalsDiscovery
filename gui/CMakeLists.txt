cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

set(PROJECT_SOURCES
        experiments/bifurfractalparams.cpp
        experiments/bifurfractalparams.h
        experiments/bifurfractals_ui.h
#        juliasquaredfractalparams.cpp
#        juliasquaredfractalparams.h
#        juliasquaredfractals_ui.h
#        juliacoshfractalparams.cpp
#        juliacoshfractalparams.h
#        juliacoshfractals_ui.h
#        juliaexpfractalparams.cpp
#        juliaexpfractalparams.h
#        juliaexpfractals_ui.h
#        juliapower4fractalparams.cpp
#        juliapower4fractalparams.h
#        juliapower4fractals_ui.h
#        mandelbrotfractalparams.cpp
#        mandelbrotfractalparams.h
#        mandelbrotfractals_ui.h
#        lyapfractalparams.cpp
#        lyapfractalparams.h
#        lyapfractals_ui.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_library(gui
        STATIC
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(gui PUBLIC Qt6::Core Qt6::Widgets)

target_include_directories(gui INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})