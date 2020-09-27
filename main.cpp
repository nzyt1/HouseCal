#include "calculator.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("D:\\codeLib\\HouseCal\\HouseCal_zh_CN.qm");
    a.installTranslator(&translator);
    Calculator w;
    w.show();
    return a.exec();
}
