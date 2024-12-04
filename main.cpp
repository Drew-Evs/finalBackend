#include <QApplication>
#include "physicalPage.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //create window
    PhysicalPage window;
    window.setWindowTitle("Physical Pollutants Page");
    window.setMinimumSize(900,600);

    //shows 
    window.show();

    return app.exec();
}