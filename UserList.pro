QT       += core gui quick concurrent quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 app_bundle

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

TEMPLATE=app

BUILD_DIR=build
TMP_DIR=$${BUILD_DIR}/tmp

MOC_DIR=$${TMP_DIR}/moc
RCC_DIR=$${TMP_DIR}/rcc
UI_DIR=$${TMP_DIR}/ui
OBJECTS_DIR=$${TMP_DIR}/obj

DESTDIR=$${BUILD_DIR}/out


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DMGFILE=$${DESTDIR}/UserList.dmg
dmgfile.target = $${DMGFILE}
dmgfile.commands = macdeployqt $${DESTDIR}/UserList.app -qmldir=$${PWD} -qmlimport=$${PWD} -dmg
QMAKE_EXTRA_TARGETS += dmgfile

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
