#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QtCore>
#include <QtQuick/QQuickView>
#include <Translations.h>
#include <UserDisplayData.h>
#include <UserDisplayDataDeserializer.h>
#include <UserListModel.h>
#include <UserRepository.h>


int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    Translations translations;
    QTranslator *translator = translations.load(a);
    a.installTranslator(translator);

    UserListModel userListModel(&a);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("userListModel", QVariant::fromValue(&userListModel));
    QQuickStyle::setStyle("Material");
    engine.load(QUrl("qrc:/UserList.qml"));

    return a.exec();
}
