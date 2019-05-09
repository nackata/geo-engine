QT += core
QT -= gui

TARGET = geoRiddle
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    src/fpsCam.cpp \
    src/mesh.cpp \
    src/model.cpp \
    src/shader.cpp \
    src/sceneobject.cpp \
    src/renderer.cpp \
    src/dynamicobject.cpp \
    src/rotatingcube.cpp \
    src/scene.cpp \
    src/game.cpp \
    src/dynamicinter.cpp \
    src/button.cpp \
    src/player.cpp \
    src/inputmanager.cpp \
    src/aabbtritest.cpp \
    src/stand.cpp \
    src/attachedbutton.cpp \
    src/screentext.cpp \
    src/soundmaster.cpp \
    src/objectfactory.cpp

HEADERS += \
    include/fpsCam.h \
    include/mesh.h \
    include/model.h \
    include/shader.h \
    include/stb_image.h \
    include/sceneobject.h \
    include/staticobject.h \
    include/room.h \
    include/light.h \
    include/renderer.h \
    include/dynamicobject.h \
    include/rotatingcube.h \
    include/scene.h \
    include/dynamicnoninter.h \
    include/game.h \
    include/dynamicinter.h \
    include/button.h \
    include/player.h \
    include/aabb.h \
    include/inputmanager.h \
    include/color.h \
    include/stand.h \
    include/attachedbutton.h \
    include/tojsonconvert.h \
    include/screentext.h \
    include/soundmaster.h \
    include/objectfactory.h

DISTFILES += \
    common/shaders/fragment_shader.glsl \
    common/shaders/lamp_shader.glsl \
    common/shaders/vertex_shader.glsl \
    common/shaders/text_frag.glsl \
    common/shaders/text_vs.glsl

unix:!macx: LIBS += -L~/libs/freetype-2.9.1/build/ -lfreetype

INCLUDEPATH += ~/libs/freetype-2.9.1/include
DEPENDPATH += ~/libs/freetype-2.9.1/include

unix:!macx: PRE_TARGETDEPS += ~/libs/freetype-2.9.1/build/libfreetype.a

LIBS += -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor -lassimp -lpng -lz

unix:!macx: LIBS += -L$$PWD/../../../../libs/irrKlang-64bit-1.6.0/bin/linux-gcc-64/ -lIrrKlang

INCLUDEPATH += $$PWD/../../../../libs/irrKlang-64bit-1.6.0/include
DEPENDPATH += $$PWD/../../../../libs/irrKlang-64bit-1.6.0/include
