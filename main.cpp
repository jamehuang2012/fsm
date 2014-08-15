#include <QApplication>
#include <mainuser.h>
#include <QStyleFactory>
#include <QStyle>

#include "inputreader.h"

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    //QApplication::setStyle(QStyleFactory::create("Plastique"));
    QApplication::setPalette(QApplication::style()->standardPalette());

   // MainUser mainUser;
    //mainUser.show();
    InputReader inputDialog;
    inputDialog.show();

    return app.exec();
}
