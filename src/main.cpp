#include <wait.h>
#include <unistd.h>
#include <signal.h>
#include<QApplication>
#include <QtQml>
//#include "ServerStream.h"
#include <QTime>
//#include <QTimer>
#include <QFile>
#include <QtDebug>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QTextStream>
#include <QGuiApplication>
#include <QCommandLineParser>
#include <QQmlApplicationEngine>
#include "ServerStream.h"
#include "QQmlContext"
#include <QQuickView>
#include <QQmlApplicationEngine>
//#include <carstatus.h>
#include <fontName.h>
#include<QQuickView>

static pid_t pid;
static bool exit_loop = true;

static void signal_handler(int signo)
{
	if (signo == SIGINT)
		qDebug() << "main receive signal: SIGINT\n";
	if (signo == SIGTERM)
		qDebug() << "main receive signal: SIGTERM\n";

	if (kill(pid, SIGTERM) < 0)
		qDebug() << "main kill server fail\n";

	exit_loop = false;
}

int server_main(int argc, char *argv[])
{
//    QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
//    app.setOverrideCursor(Qt::BlankCursor);

     MFontName fontName;
     ServerStream *stream = new ServerStream;
     QQmlApplicationEngine engine;

     engine.rootContext()->setContextProperty("client",stream);
     engine.addImageProvider(QLatin1String("screen"),stream->imgProvider);

     engine.rootContext()->setContextProperty("clientSmallTurn", stream);
     engine.addImageProvider(QLatin1String("screenSmallTurn"), stream->imgProviderSimpleTurn);

     engine.rootContext()->setContextProperty("clientSmallChannel", stream);
     engine.addImageProvider(QLatin1String("screenSmallChannel"), stream->imgProviderSimpleChannel);

     engine.rootContext()->setContextProperty("clientSmallCross", stream);
     engine.addImageProvider(QLatin1String("screenSmallCross"), stream->imgProviderSimpleCross);

     engine.rootContext()->setContextProperty("clientSmallCamera", stream);
     engine.addImageProvider(QLatin1String("screenSmallCamera"), stream->imgProviderSimpleCamera);

     engine.rootContext()->setContextProperty("clientSmallLogo", stream);
     engine.addImageProvider(QLatin1String("screenSmallLogo"), stream->imgProviderSimpleLogo);

     engine.rootContext()->setContextProperty("clientSmallOther", stream);
     engine.addImageProvider(QLatin1String("screenSmallOther"), stream->imgProviderSimpleOther);

      engine.rootContext()->setContextProperty("FontName", &fontName);

     engine.rootContext()->setContextProperty("qstream", stream);
     engine.load(QUrl(QStringLiteral("qrc:/qml/qml/mainViewer.qml")));

 //        QQuickView viewer;
 ////        viewer.rootContext()->setContextProperty("CarStatus", &carStatus);
 //        viewer.rootContext()->setContextProperty("FontName", &fontName);

//         engine.rootContext()->setContextProperty("FontName", &fontName);

 //        viewer.setSource(QUrl("qrc:/qml/qml/leftPanel.qml"));
 ////        qmlRegisterType<CarStatus>("Carstatus", 1, 0, "Carstatus");
 //        app.connect(viewer.engine(),&QQmlEngine::quit, &QGuiApplication::quit);
 //        viewer.show();
          return app.exec();
}

int main(int argc, char **argv)
{

	if (signal(SIGINT, signal_handler) == SIG_ERR ||
		signal(SIGTERM, signal_handler) == SIG_ERR) {
		qDebug() << "main process register signal handler fail\n";
		return 0;
	}

    do {
		pid = fork();
		if (pid == 0) {
			if (signal(SIGINT, SIG_DFL) == SIG_ERR ||
				signal(SIGTERM, SIG_DFL) == SIG_ERR) {
				qDebug() << "server process register signal handler fail\n";
				return 0;
			}
			return server_main(argc, argv);
		}
		else if (pid > 0) {
			int status;
			wait(&status);
			qDebug() << "server exit with status: " << status ;
		}
		else {
			qDebug() << "main fork server fail: " << pid ;
			break;
		}
	} while (exit_loop);

	return 0;
}
