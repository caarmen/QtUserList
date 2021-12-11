QT       += core gui quick concurrent quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 lrelease embed_translations

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Translations.cpp \
    UserDisplayData.cpp \
    UserDisplayDataDeserializer.cpp \
    UserListModel.cpp \
    UserRepository.cpp \
    main.cpp

lupdate_only{
SOURCES += UserListModel.qml
}
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    qml.qrc

HEADERS += \
    Translations.h \
    UserDisplayData.h \
    UserDisplayDataDeserializer.h \
    UserListModel.h \
    UserRepository.h

TRANSLATIONS += \
    translations_en.ts
