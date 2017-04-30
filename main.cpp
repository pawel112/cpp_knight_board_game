#include "choose_language.h"
#include <QApplication>
#include <ctime>

int main (int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a (argc, argv);

    choose_language w;
    w.show();

    return a.exec ();
}
