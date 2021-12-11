#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include <QCoreApplication>
#include <QObject>
#include <QTranslator>

class Translations : public QObject
{
    Q_OBJECT
public:
    explicit Translations(QObject *parent = nullptr);
    QTranslator* load(QCoreApplication &app);
};

#endif // TRANSLATIONS_H
