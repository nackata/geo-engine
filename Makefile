#############################################################################
# Makefile for building: geoRiddle
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  geoRiddle.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt5/bin/qmake -spec linux-g++-64 -o Makefile geoRiddle.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_CORE_LIB
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -std=c++0x -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I~/libs/freetype-2.9.1/include -I../../../../libs/irrKlang-64bit-1.6.0/include -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64
QMAKE         = /usr/lib/x86_64-linux-gnu/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = geoRiddle1.0.0
DISTDIR = /home/nackata/projects/OOP/course-work/geo-riddle/.tmp/geoRiddle1.0.0
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS) -L~/libs/freetype-2.9.1/build/ -lfreetype -lglfw3 -lGL -lX11 -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor -lassimp -lpng -lz -L/home/nackata/projects/OOP/course-work/geo-riddle/../../../../libs/irrKlang-64bit-1.6.0/bin/linux-gcc-64/ -lIrrKlang -lQt5Core -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
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
OBJECTS       = main.o \
		fpsCam.o \
		mesh.o \
		model.o \
		shader.o \
		sceneobject.o \
		renderer.o \
		dynamicobject.o \
		rotatingcube.o \
		scene.o \
		game.o \
		dynamicinter.o \
		button.o \
		player.o \
		inputmanager.o \
		aabbtritest.o \
		stand.o \
		attachedbutton.o \
		screentext.o \
		soundmaster.o \
		objectfactory.o
DIST          = common/shaders/fragment_shader.glsl \
		common/shaders/lamp_shader.glsl \
		common/shaders/vertex_shader.glsl \
		common/shaders/text_frag.glsl \
		common/shaders/text_vs.glsl \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/c++11.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		geoRiddle.pro include/fpsCam.h \
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
		include/objectfactory.h main.cpp \
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
QMAKE_TARGET  = geoRiddle
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = geoRiddle


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET): ~/libs/freetype-2.9.1/build/libfreetype.a $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: geoRiddle.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/c++11.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		geoRiddle.pro \
		/usr/lib/x86_64-linux-gnu/libQt5Core.prl
	$(QMAKE) -spec linux-g++-64 -o Makefile geoRiddle.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/c++11.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
geoRiddle.pro:
/usr/lib/x86_64-linux-gnu/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -spec linux-g++-64 -o Makefile geoRiddle.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents include/fpsCam.h include/mesh.h include/model.h include/shader.h include/stb_image.h include/sceneobject.h include/staticobject.h include/room.h include/light.h include/renderer.h include/dynamicobject.h include/rotatingcube.h include/scene.h include/dynamicnoninter.h include/game.h include/dynamicinter.h include/button.h include/player.h include/aabb.h include/inputmanager.h include/color.h include/stand.h include/attachedbutton.h include/tojsonconvert.h include/screentext.h include/soundmaster.h include/objectfactory.h $(DISTDIR)/
	$(COPY_FILE) --parents main.cpp src/fpsCam.cpp src/mesh.cpp src/model.cpp src/shader.cpp src/sceneobject.cpp src/renderer.cpp src/dynamicobject.cpp src/rotatingcube.cpp src/scene.cpp src/game.cpp src/dynamicinter.cpp src/button.cpp src/player.cpp src/inputmanager.cpp src/aabbtritest.cpp src/stand.cpp src/attachedbutton.cpp src/screentext.cpp src/soundmaster.cpp src/objectfactory.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp include/game.h \
		include/scene.h \
		include/staticobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h \
		include/dynamicnoninter.h \
		include/dynamicobject.h \
		include/dynamicinter.h \
		include/fpsCam.h \
		include/light.h \
		include/renderer.h \
		include/player.h \
		include/inputmanager.h \
		include/room.h \
		include/stand.h \
		include/rotatingcube.h \
		include/color.h \
		include/button.h \
		include/attachedbutton.h \
		include/screentext.h \
		include/soundmaster.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/irrKlang.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_irrKlangTypes.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_vec3d.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IRefCounted.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IVirtualRefCounted.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ESoundOutputDrivers.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ESoundEngineOptions.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_EStreamModes.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_SAudioStreamFormat.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundEngine.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundSource.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISound.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundEffectControl.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IFileFactory.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundMixedOutputReceiver.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IAudioStream.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IAudioStreamLoader.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IFileReader.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundStopEventReceiver.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundDeviceList.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IAudioRecorder.h \
		include/objectfactory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

fpsCam.o: src/fpsCam.cpp include/fpsCam.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fpsCam.o src/fpsCam.cpp

mesh.o: src/mesh.cpp include/mesh.h \
		include/shader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mesh.o src/mesh.cpp

model.o: src/model.cpp include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o model.o src/model.cpp

shader.o: src/shader.cpp include/shader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o shader.o src/shader.cpp

sceneobject.o: src/sceneobject.cpp include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sceneobject.o src/sceneobject.cpp

renderer.o: src/renderer.cpp include/renderer.h \
		include/shader.h \
		include/light.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h \
		include/fpsCam.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o renderer.o src/renderer.cpp

dynamicobject.o: src/dynamicobject.cpp include/dynamicobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dynamicobject.o src/dynamicobject.cpp

rotatingcube.o: src/rotatingcube.cpp include/rotatingcube.h \
		include/dynamicnoninter.h \
		include/dynamicobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h \
		include/color.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o rotatingcube.o src/rotatingcube.cpp

scene.o: src/scene.cpp include/scene.h \
		include/staticobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h \
		include/dynamicnoninter.h \
		include/dynamicobject.h \
		include/dynamicinter.h \
		include/fpsCam.h \
		include/light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o scene.o src/scene.cpp

game.o: src/game.cpp include/game.h \
		include/scene.h \
		include/staticobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h \
		include/dynamicnoninter.h \
		include/dynamicobject.h \
		include/dynamicinter.h \
		include/fpsCam.h \
		include/light.h \
		include/renderer.h \
		include/player.h \
		include/inputmanager.h \
		include/room.h \
		include/stand.h \
		include/rotatingcube.h \
		include/color.h \
		include/button.h \
		include/attachedbutton.h \
		include/screentext.h \
		include/soundmaster.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/irrKlang.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_irrKlangTypes.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_vec3d.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IRefCounted.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IVirtualRefCounted.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ESoundOutputDrivers.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ESoundEngineOptions.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_EStreamModes.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_SAudioStreamFormat.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundEngine.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundSource.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISound.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundEffectControl.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IFileFactory.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundMixedOutputReceiver.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IAudioStream.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IAudioStreamLoader.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IFileReader.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundStopEventReceiver.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundDeviceList.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IAudioRecorder.h \
		include/objectfactory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o game.o src/game.cpp

dynamicinter.o: src/dynamicinter.cpp include/dynamicinter.h \
		include/dynamicobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h \
		include/fpsCam.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dynamicinter.o src/dynamicinter.cpp

button.o: src/button.cpp include/button.h \
		include/dynamicinter.h \
		include/dynamicobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h \
		include/fpsCam.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o button.o src/button.cpp

player.o: src/player.cpp include/player.h \
		include/fpsCam.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o player.o src/player.cpp

inputmanager.o: src/inputmanager.cpp include/inputmanager.h \
		include/player.h \
		include/fpsCam.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o inputmanager.o src/inputmanager.cpp

aabbtritest.o: src/aabbtritest.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o aabbtritest.o src/aabbtritest.cpp

stand.o: src/stand.cpp include/stand.h \
		include/dynamicnoninter.h \
		include/dynamicobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o stand.o src/stand.cpp

attachedbutton.o: src/attachedbutton.cpp include/attachedbutton.h \
		include/dynamicinter.h \
		include/dynamicobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h \
		include/fpsCam.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o attachedbutton.o src/attachedbutton.cpp

screentext.o: src/screentext.cpp include/screentext.h \
		include/shader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o screentext.o src/screentext.cpp

soundmaster.o: src/soundmaster.cpp include/soundmaster.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/irrKlang.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_irrKlangTypes.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_vec3d.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IRefCounted.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IVirtualRefCounted.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ESoundOutputDrivers.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ESoundEngineOptions.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_EStreamModes.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_SAudioStreamFormat.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundEngine.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundSource.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISound.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundEffectControl.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IFileFactory.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundMixedOutputReceiver.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IAudioStream.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IAudioStreamLoader.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IFileReader.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundStopEventReceiver.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_ISoundDeviceList.h \
		../../../../libs/irrKlang-64bit-1.6.0/include/ik_IAudioRecorder.h \
		include/dynamicinter.h \
		include/dynamicobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h \
		include/fpsCam.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o soundmaster.o src/soundmaster.cpp

objectfactory.o: src/objectfactory.cpp include/objectfactory.h \
		include/room.h \
		include/staticobject.h \
		include/sceneobject.h \
		include/aabb.h \
		include/model.h \
		include/shader.h \
		include/mesh.h \
		include/stb_image.h \
		include/tojsonconvert.h \
		include/button.h \
		include/dynamicinter.h \
		include/dynamicobject.h \
		include/fpsCam.h \
		include/attachedbutton.h \
		include/stand.h \
		include/dynamicnoninter.h \
		include/rotatingcube.h \
		include/color.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objectfactory.o src/objectfactory.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

