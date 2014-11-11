#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <qtimer.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qmessagebox.h>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->lcd_MiliSeconds->display("00");
    this->ui->lcd_Seconds->display("00");
    this->ui->lcd_Minutes->display("00");

    QFile file("/home/sneet/cis330-project/Court_Master/Library.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
    QString libraryText;

    while(!in.atEnd())
    {
        QStringList list;
        QString str = in.readLine();
        list = str.split(QRegularExpression("\t"));
        Player newPlayer;
        //newPlayer.setSecs(list.takeLast().toInt());
        //newPlayer.setMins(list.takeLast().toInt());
        //newPlayer.setLosses(list.takeLast().toInt());
        //newPlayer.setWins(list.takeLast().toInt());
        newPlayer.setName(list.takeFirst().toStdString());
        playerLibrary.enqueue(newPlayer);
    }

    nodePtr n = playerLibrary.getHead();
    QString temp;
    while(n != NULL)
    {
        temp = QString::fromStdString(n->player.getName());
        libraryText.append(temp);
        libraryText.append("\n");
        n = n->next;
    }

    ui->Library_Browser->setText(libraryText);
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Start_clicked()
{
    //ui->label->setText("Start");
    MiliTimer.start(0001);
    Minutes = 0;
    for(int k=1;k < 60; k++)
    {
        Seconds = 0;
        for(int i = 1;i < 60; i++)
        {
            MiliSeconds = 0;
            for(int j = 1;j < 1000; j++)
            {
                QEventLoop loop1;
                connect(&MiliTimer,SIGNAL(timeout()),&loop1,SLOT(quit()));
                loop1.exec();
                this->ui->lcd_MiliSeconds->display(j);
                MiliSeconds++;
            }
            this->ui->lcd_Seconds->display(i);
            Seconds++;
        }
        this->ui->lcd_Minutes->display(k);
        Minutes++;
    }
}

void MainWindow::on_Stop_clicked()
{
    MiliTimer.stop();
    for(int i = 0;i < TEAMSIZE; i++)
    {
        HomeTeam[i].setMins(Minutes);
        AwayTeam[i].setSecs(Seconds);
    }
}

void MainWindow::on_Reset_clicked()
{
    MiliTimer.stop();
    this->ui->lcd_MiliSeconds->display("00");
    this->ui->lcd_Seconds->display("00");
    this->ui->lcd_Minutes->display("00");
    MiliSeconds = 0;
    Seconds = 0;
    Minutes = 0;
}

void MainWindow::on_verticalScrollBar_sliderMoved(int position)
{

}


void MainWindow::on_Import_Home_clicked()
{

    for(int i = 0;i < TEAMSIZE;i++)
    {
        playerLibrary.enqueue(HomeTeam[i]);
    }
}

void MainWindow::on_Import_Away_clicked()
{

    for(int i = 0;i < TEAMSIZE;i++)
    {
        playerLibrary.enqueue(AwayTeam[i]);
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_Join_Queue_clicked()
{
    tempLibraryText = "";
    waitListText = "";
    QString playerName;

    playerName = ui->lineEdit_PlayerName->text();

    if(playerLibrary.findPlayer(playerName.toStdString()))
    {
        waitList.enqueue(playerLibrary.removeKey(playerName.toStdString()));
        nodePtr m = playerLibrary.getHead();
        QString thisTemp;
        while(m != NULL)
        {
            thisTemp = QString::fromStdString(m->player.getName());
            tempLibraryText.append(thisTemp);
            tempLibraryText.append("\n");
            m = m->next;
        }

        ui->Library_Browser->setText(tempLibraryText);
    }
    else
    {
        Player newPlayer(playerName.toStdString());
        waitList.enqueue(newPlayer);
    }
    nodePtr n = waitList.getHead();
    QString temp;
    QString awayTemp;
    QString homeTemp;



    if(waitList.getSize() >= TEAMSIZE && !homeTeamFilled)
    {
        for(int i = 0;i < TEAMSIZE; i++)
        {
            HomeTeam[i] = waitList.dequeue();
            homeTemp = QString::fromStdString(HomeTeam[i].getName());
            homeTeamText.append(homeTemp);
            homeTeamText.append("\n");
        }
        homeTeamFilled = true;
        ui->HomeBrowser->setText(homeTeamText);
    }

    if(waitList.getSize() >= TEAMSIZE && !awayTeamFilled)
    {
        for(int j = 0;j < TEAMSIZE; j++)
        {
            AwayTeam[j] = waitList.dequeue();
            awayTemp = QString::fromStdString(AwayTeam[j].getName());
            awayTeamText.append(awayTemp);
            awayTeamText.append("\n");
        }
        awayTeamFilled = true;
        ui->AwayBrowser->setText(awayTeamText);
    }

    nodePtr tempNode = waitList.getHead();
    while(tempNode != NULL)
    {
        temp = QString::fromStdString(tempNode->player.getName());
        waitListText.append(temp);
        waitListText.append("\n");
        tempNode = tempNode->next;

    }
    ui->WaitList_Browser->setText(waitListText);
    ui->lineEdit_PlayerName->setText("");
}
//--------------------------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_Declare_Winner_clicked()
{
    QString temp = "Home";

    std::cout << "1" << std::endl;
    std::cout<<"In declare winner clicked; waitlist print:";
    waitList.printQueue();
    std::cout<<"end."<<std::endl;
    if(ui->winnerDropDown->currentText() == temp)
    {
        std::cout << "1.5" << std::endl;

        homeTeamWinsStats();
        toFileString.append(fullStatsToString(HomeTeam));

        std::cout << "1.6" << std::endl;

        for(int i = 0;i < TEAMSIZE; i++)
        {
            playerLibrary.enqueue(AwayTeam[i]);
        }
        awayTeamFilled = false;

    }
    else
    {
        std::cout << "1.6" << std::endl;

        awayTeamWinsStats();
        toFileString.append(fullStatsToString(AwayTeam));

        for(int i = 0;i < TEAMSIZE; i++)
        {
            playerLibrary.enqueue(HomeTeam[i]);
            HomeTeam[i] = AwayTeam[i];
        }
        homeTeamText = awayTeamText;
        ui->HomeBrowser->setText(homeTeamText);

        awayTeamFilled = false;
    }
    ui->AwayBrowser->setText("");
    std::cout << "3" << std::endl;
    awayTeamText = "";

    QString awayTempQString = "";
    if(waitList.getSize() >= TEAMSIZE && !awayTeamFilled)
    {
        for(int j = 0;j < TEAMSIZE; j++)
        {
            AwayTeam[j] = waitList.dequeue();
            awayTempQString = QString::fromStdString(AwayTeam[j].getName());
            awayTeamText.append(awayTempQString);
            awayTeamText.append("\n");
        }
        awayTeamFilled = true;
        std::cout << "Awayteam text " << awayTeamText.toStdString() << std::endl;
        ui->AwayBrowser->setText(awayTeamText);
    }

    toFileString.append(fullStatsQToString(waitList.getHead()));
    std::cout << toFileString.toStdString() << std::endl;

    waitList.printQueue();
    std::cout << "4" << std::endl;
//====================================================================================================================

    toFileString.append(fullStatsQToString(playerLibrary.getHead()));

    homeTeamText = updatePlayerText(HomeTeam);

    waitListText = "";

    waitListText = updatePlayerText(waitList.getHead());
    ui->AwayBrowser->setText(waitListText);

    nodePtr tempForIter = waitList.getHead();

    while(tempForIter != NULL)
    {
        waitListText.append(tempForIter->player.toQString());
        tempForIter = tempForIter->next;
        std::cout << "here I am" << std::endl;
    }

    std::cout << "4.3" << std::endl;


//    nodePtr tempNode = waitList.getHead();
//    QString textTemp ="";
//    QString temp2 = "";

//    for(int i = 0;i < waitList.getSize(); i++)
//    {
//        std::cout << "while 1" << std::endl;//test
//        std::cout << tempNode->player.getName() << std::endl;

//        temp2 = QString::fromStdString(tempNode->player.getName());
//        std::cout << "while 2" << std::endl;//test

//        textTemp.append(temp);
//        std::cout << "while 3" << std::endl;//test

//        textTemp.append("\n");
//        std::cout << "while 4" << std::endl;//test

//        tempNode = tempNode->next;
//        std::cout << "while 5" << std::endl;//test
//    }

//=============================================================================================================

    std::cout << "4.3" << std::endl;
    tempLibraryText = updatePlayerText(playerLibrary.getHead());
    std::cout << "4.4" << std::endl;

    ui->HomeBrowser->setText(homeTeamText);
    std::cout << "4.5" << std::endl;

    ui->WaitList_Browser->setText(waitListText);
    std::cout << "4.6" << std::endl;

    ui->AwayBrowser->setText(awayTeamText);


    ui->Library_Browser->setText(tempLibraryText);
    std::cout << "5" << std::endl;


    QFile file("/home/sneet/cis330-project/Court_Master/Library.txt");
    if(!file.open(QIODevice::ReadWrite))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
    std::cout << "6" << std::endl;

    in << toFileString;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
QString MainWindow::updatePlayerText(Player thisArray[])
{
    QString playerTextTemp = "";
    QString playerText = "";
    for(int i = 0;i < TEAMSIZE; i++)
    {
        playerText = QString::fromStdString(thisArray[i].getName());
        playerTextTemp.append(playerText);
        playerTextTemp.append("\n");
    }
    return playerTextTemp;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
QString MainWindow::updatePlayerText(nodePtr x)
{
    std::cout << "Inside update Playertext: " << std::endl;//test

    QString textTemp ="";
    QString temp = "";




    nodePtr index = x;
//    std::cout << "HEAD works: "  << "done" << std::endl;//test
//    std::cout<< index->player.getName()<<std::endl;
    std::cout<<"sandwhich"<<std::endl;
    while(index != NULL)
    {
        std::cout << "Inside while " << std::endl;
        temp.append(index->player.toQString());
        temp.append("\n");
        index = index->next;
    }



    return temp;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::homeTeamWinsStats()
{
    QString tempHolder = "";
    for(int i = 0;i < TEAMSIZE; i++)
    {
        unsigned int tempMins=0,
                     tempSecs=0,
                     tempWins=0,
                     tempLosses=1;

        tempWins = HomeTeam[i].getWins() + 1;
        HomeTeam[i].setWins(tempWins);

        tempSecs = HomeTeam[i].getSecs() + Seconds;
        HomeTeam[i].setSecs(tempSecs);
        if(HomeTeam[i].getSecs() > 59)
        {
            tempSecs %= 60;
            tempMins++;
        }
        tempMins += HomeTeam[i].getMins();
        HomeTeam[i].setMins(tempMins);

        tempMins=0;
        tempSecs=0;
        tempWins=0;
        tempLosses=1;

        tempLosses += AwayTeam[i].getLosses();
        AwayTeam[i].setLosses(tempLosses);

        tempSecs = AwayTeam[i].getSecs() + Seconds;
        AwayTeam[i].setSecs(tempSecs);
        if(AwayTeam[i].getSecs() > 59)
        {
            tempSecs %= 60;
            tempMins++;
        }
        tempMins += AwayTeam[i].getMins();
        AwayTeam[i].setMins(tempMins);

        tempHolder = QString::fromStdString(AwayTeam[i].getName());
        tempLibraryText.append(tempHolder);
        tempLibraryText.append("\n");

    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::awayTeamWinsStats()
{
    QString newTempHolder = "";
    for(int i = 0;i < TEAMSIZE; i++)
    {
        unsigned int tempMins=0,
                     tempSecs=0,
                     tempWins=0,
                     tempLosses=1;

        tempWins = AwayTeam[i].getWins() + 1;
        AwayTeam[i].setWins(tempWins);

        tempSecs = AwayTeam[i].getSecs() + Seconds;
        AwayTeam[i].setSecs(tempSecs);
        if(AwayTeam[i].getSecs() > 59)
        {
            tempSecs %= 60;
            tempMins++;
        }
        tempMins += AwayTeam[i].getMins();
        AwayTeam[i].setMins(tempMins);

        tempMins=0;
        tempSecs=0;
        tempWins=0;
        tempLosses=1;

        tempLosses += HomeTeam[i].getLosses();
        HomeTeam[i].setLosses(tempLosses);

        tempSecs = HomeTeam[i].getSecs() + Seconds;
        HomeTeam[i].setSecs(tempSecs);
        if(HomeTeam[i].getSecs() > 59)
        {
            tempSecs %= 60;
            tempMins++;
        }
        tempMins += HomeTeam[i].getMins();
        HomeTeam[i].setMins(tempMins);

        newTempHolder = QString::fromStdString(HomeTeam[i].getName());
        tempLibraryText.append(newTempHolder);
        tempLibraryText.append("\n");
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
QString MainWindow::fullStatsQToString(nodePtr wait)
{
    QString temp = "";
    nodePtr index = wait;
    while(index != NULL)
    {
        temp.append(index->player.toQString());
        index = index->next;
    }
    return temp;
}
QString MainWindow::fullStatsToString(Player toBeStringed []){
    QString temp = "";
    std::cout << "Got to fullStatsToString" << std::endl;
    for (int i = 0; i < TEAMSIZE;i++){
        std::cout << i << toBeStringed[i].toQString().toStdString();
        temp.append(toBeStringed[i].toQString());
    }
    return temp;
}




















