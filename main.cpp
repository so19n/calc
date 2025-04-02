#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "processcalculating.h"
#include <QQmlContext>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QFontDatabase fontDatabase;
    if (fontDatabase.addApplicationFont(":/font/open-sans-semibold.ttf") == -1)
        qDebug() << "Failed to load open-sans-semibold.ttf";
    QQmlApplicationEngine engine;

    ProcessCalculating processCalculating;
    engine.rootContext()->setContextProperty("processCalculating", &processCalculating);

    const QUrl url(QStringLiteral("qrc:/untitled1/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
