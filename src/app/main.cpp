#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QtCore>
#include <QtQuick/QQuickView>
#include <app/Translations.h>
#include <viewmodel/UserListModel.h>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    Translations translations;
    QTranslator *translator = translations.load();
    a.installTranslator(translator);

    UserListModel userListModel(&a);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("userListModel", QVariant::fromValue(&userListModel));
    QQuickStyle::setStyle("Material");
    engine.load(QUrl("qrc:/src/view/UserList.qml"));

    return a.exec();
}
