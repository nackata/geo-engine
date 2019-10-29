QT += core
QT -= gui

TARGET = geoRiddle
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    lib/glad/src/glad.c \
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
    src/soundmaster.cpp

HEADERS += \
    include/fpsCam.h \
    include/mesh.h \
    include/model.h \
    include/shader.h \
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


DISTFILES += \
    common/shaders/fragment_shader.glsl \
    common/shaders/lamp_shader.glsl \
    common/shaders/vertex_shader.glsl \
    common/shaders/text_frag.glsl \
    common/shaders/text_vs.glsl


# LINUX libs
#LIBS += -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor -lassimp -lpng -lz

# Win libs (no need (glfw3dll))
#LIBS += -lgdi32 -lopengl32 -luser32 -lkernel32 -lglu32

INCLUDEPATH += $$PWD/lib/glad/include
INCLUDEPATH += $$PWD/lib
INCLUDEPATH += $$PWD/lib/stb_image

win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/Assimp/lib/x64/ -lassimp-vc141-mtd

INCLUDEPATH += $$PWD/lib/Assimp/include
DEPENDPATH += $$PWD/lib/Assimp/include/assimp


win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/freetype/win64/ -lfreetype

INCLUDEPATH += $$PWD/lib/freetype/include
DEPENDPATH += $$PWD/lib/freetype/include

win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/irrKlang-64bit-1.6.0/lib/Winx64-visualStudio/ -lirrKlang

INCLUDEPATH += $$PWD/lib/irrKlang-64bit-1.6.0/include
DEPENDPATH += $$PWD/lib/irrKlang-64bit-1.6.0/include

win32: LIBS += -L$$PWD/lib/glfw-3.3.bin.WIN64/lib-vc2017/ -lglfw3dll

INCLUDEPATH += $$PWD/lib/glfw-3.3.bin.WIN64/include
DEPENDPATH += $$PWD/lib/glfw-3.3.bin.WIN364/include
