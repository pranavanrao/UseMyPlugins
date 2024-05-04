#include "mywidget.h"

#include <QApplication>
#include <QPluginLoader>
#include <QDebug>

// Set the location based on your system path
#include "C:\Users\prana\OneDrive\Desktop\QT-QML-projects\QTWidgetExamples\MyDeviceSupport\mydevicesupport.h"
#include "C:\Users\prana\OneDrive\Desktop\QT-QML-projects\QTWidgetExamples\SeimensPlugin\seimensplugin.h"

void loadPlugin() {

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();

    QPluginLoader loadTata;
    QPluginLoader loadSeimens;

    // Set the location based on your system path
    loadTata.setFileName("C:/Users/prana/OneDrive/Desktop/QT-QML-projects/QTWidgetExamples/MyDeviceSupport/bins/MyDeviceSupport.dll");
    loadSeimens.setFileName("C:/Users/prana/OneDrive/Desktop/QT-QML-projects/QTWidgetExamples/SeimensPlugin/bins/SeimensPlugin.dll");
    if(loadTata.load()) {
        qDebug() << "Tata plugin loaded successfully";
    } else {
        qWarning() << "it is saturday. Tata not loaded yet";
    }

    if (loadSeimens.load()) {
        qDebug() << "Seimens plugin loaded succefully";
    } else {
        qWarning() << "It's saturday. Seimens not loaded yet";
    }

    QObject* objTata = loadTata.instance();
    QObject* objSeimens = loadSeimens.instance();
    if(objTata) {
        qDebug() << "Load Tata";
        MyDeviceSupport* iface = qobject_cast<MyDeviceSupport*>(objTata);
        iface->open();
    } else {
        qWarning()<<"it is saturday";
    }

    if (objSeimens) {
        qDebug() << "Load Seimens";
        SeimensPlugin* iface = qobject_cast<SeimensPlugin*>(objSeimens);
        iface->open();
    } else {
        qWarning() << "It is saturday";
    }
    return a.exec();
}
