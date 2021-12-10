#include <QGuiApplication>
#include <QJsonArray>
#include <QJsonObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtCore>
#include <QtQuick/QQuickView>
#include <UserDisplayData.h>
#include <UserDisplayDataDeserializer.h>
#include <UserRepository.h>
#include <UserListModel.h>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    UserListModel userListModel(&a);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("userListModel", QVariant::fromValue(&userListModel));
    engine.load(QUrl("qrc:/UserList.qml"));

    return a.exec();
}
