QT       += core gui quick concurrent quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/app/Translations.cpp \
    src/app/main.cpp \
    src/model/UserRepository.cpp \
    src/viewmodel/UserDisplayData.cpp \
    src/viewmodel/UserDisplayDataDeserializer.cpp \
    src/viewmodel/UserListModel.cpp \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    qml.qrc

INCLUDEPATH += src/
HEADERS += \
    src/app/Translations.h \
    src/model/UserRepository.h \
    src/viewmodel/UserDisplayData.h \
    src/viewmodel/UserDisplayDataDeserializer.h \
    src/viewmodel/UserListModel.h

TRANSLATIONS += \
    i18n/src/translations_en.ts
