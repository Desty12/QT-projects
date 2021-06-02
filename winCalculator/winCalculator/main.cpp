#include "wincalculator.h"
#include <QtGui/QApplication>
#include<QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	winCalculator w;
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	w.show();
	return a.exec();
}
