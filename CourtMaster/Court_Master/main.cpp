#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <qfile.h>
#include <qtextstream.h>
#include <qmessagebox.h>
#include "PlayerQueue.h"
#include "Player.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("Court Master 3000");




    QFile file("/home/sneet/cis330-project/Court_Master/Test2.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);



//    int i = 0;
//    while(!file.atEnd())
//    {
//        HomeTeam[i] = new Player;
//        HomeTeam[i].setName();
//        HomeTeam[i].setWins();
//        HomeTeam[i].setLosses();
//        i++;
//    }

    w.show();

    return a.exec();
}
