#include "Translations.h"
#include <QLocale>
#include <QTranslator>

Translations::Translations(QObject *parent)
    : QObject{parent}
{

}

QTranslator *Translations::load(QCoreApplication &app) {
    QVector<QString> supportedLanguages;
    supportedLanguages.append("en");
    QTranslator *translator = new QTranslator();
    QString language = QLocale::languageToCode(QLocale::system().language());
    if (!supportedLanguages.contains(language))
        language = "en";
    if(!translator->load(QString("translations_%1").arg(language), ":/")) {
        qDebug() << "Failed to load translation file, falling back to English";
    }
    return translator;
}
