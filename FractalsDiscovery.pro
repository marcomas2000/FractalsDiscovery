QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FractalsDiscovery
TEMPLATE = app


SOURCES += main.cpp\
        mainfractals.cpp \
    fractaltypes.cpp \
    fractimage.cpp \
    juliaset.cpp \
    juliasquared.cpp \
    juliafractalparams.cpp \
    juliacosh.cpp \
    juliaexp.cpp \
    paintscene.cpp \
    paintview.cpp \
    mandelbrot.cpp \
    lyapunov.cpp \
    lyapset.cpp \
    lyapfractalparams.cpp \
    juliapower4.cpp \
    attractors.cpp \
    attracthenon.cpp \
    attractikeda.cpp

HEADERS  += mainfractals.h \
    fractaltypes.h \
    fractimage.h \
    juliaset.h \
    juliasquared.h \
    juliafractalparams.h \
    juliacosh.h \
    juliaexp.h \
    paintscene.h \
    paintview.h \
    mandelbrot.h \
    lyapunov.h \
    lyapset.h \
    lyapfractalparams.h \
    juliapower4.h \
    attractors.h \
    attracthenon.h \
    attractikeda.h

FORMS    += mainfractals.ui \
    fractaltypesdlg.ui \
    juliafractalparams.ui \
    lyapfractalparams.ui
