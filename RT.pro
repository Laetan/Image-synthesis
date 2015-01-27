TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Bmpfile.cpp \
    Camera.cpp \
    Object.cpp \
    PointLight.cpp \
    Ray.cpp \
    Scene.cpp \
    Sphere.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    BaseObject.h \
    Camera.h \
    Color.h \
    Common.h \
    Inter.h \
    Light.h \
    Object.h \
    PointLight.h \
    Ray.h \
    Scene.h \
    Sphere.h \
    Vector3d.h \
    Bmpfile.h

