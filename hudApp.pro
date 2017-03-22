# QT Modules
QT += qml quick serialport network widgets gui core

# Target
TARGET = hudApp
TEMPLATE = app

# Extra Configs
#DEFINES += CAN_DEBUG
#DEFINES += CAN_TIMER
#DEFINES += DEBUG_INFO_TO_FILE
#CONFIG += qtquickcompiler

#CONFIG(release, debug|release) {
#        DEFINES += QT_NO_DEBUG_OUTPUT
#}

# Sources and Headers
SOURCE_FOLDER = src
HEADER_FOLDER = src/include

INCLUDEPATH += $$HEADER_FOLDER
HEADERS += src/include/changepics.h \
    src/include/changepicsmallcamera.h \
    src/include/changepicsmallchannel.h \
    src/include/changepicsmallcross.h \
    src/include/changepicsmalllogo.h \
    src/include/changepicsmallother.h \
    src/include/changepicsmallturn.h \
    src/include/fontName.h \
    src/include/screenimageprovider.h \
    src/include/ServerStream.h \
    src/include/workmodel.h

SOURCES +=  $$SOURCE_FOLDER/main.cpp \
    src/ServerStream.cpp

# Qml Files
QML_FOLDER = qml
#QML_FOLDERS = qml/content
lupdate_only {
    SOURCES = $$QML_FOLDER/*.qml
}

#TRANSLATIONS = translations/njgdbus_chinese.ts

OTHER_FILES += \
    $$QML_FOLDERS/*.qml \
    $$QML_FOLDERS/qmldir


# Cross Compile
cross_compile {
    DEFINES += FONTS_PATH
}

# Resources
RESOURCES += hudApp.qrc
#QMAKE_RESOURCE_FLAGS += -no-compress

# Target Pathes
fontsFiles.files = fonts/fangzheng.TTF
fontsFiles.path = /usr/lib/fonts
INSTALLS += fontsFiles


target.path = /home/root
INSTALLS += target

# Objects Pathes
DESTDIR = bin
UI_DIR = build
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build

QMAKE_DISTCLEAN += *_qtquickcompiler.qrc # in my .pro file

DISTFILES += \
    fonts/fangzheng.TTF

