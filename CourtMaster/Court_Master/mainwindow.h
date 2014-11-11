#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "PlayerQueue.h"
#include "Player.h"
#include <qtimer.h>
#include <QMainWindow>
#include <qscrollbar.h>
#include <qscrollarea.h>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QScrollBar verticalScrollBar;
    QScrollArea PlayerListScrollArea;
    static unsigned const int TEAMSIZE = 2;
    PlayerQueue waitList;
    PlayerQueue playerLibrary;
    Player HomeTeam[TEAMSIZE];
    Player AwayTeam[TEAMSIZE];
    bool homeTeamFilled = false;
    bool awayTeamFilled = false;
    QString tempLibraryText;
    QString waitListText;
    QString awayTeamText;
    QString homeTeamText;
    QString toFileString;

    QString updatePlayerText(Player array[]);
    QString updatePlayerText(nodePtr listHead);
    void homeTeamWinsStats();
    void awayTeamWinsStats();
    QString fullStatsQToString(nodePtr x);
    QString fullStatsToString(Player[]);


private slots:
    void on_Start_clicked();

    void on_Stop_clicked();

    void on_Reset_clicked();

    void on_verticalScrollBar_sliderMoved(int position);

    void on_Import_Home_clicked();

    void on_Import_Away_clicked();

    void on_Join_Queue_clicked();

    void on_Declare_Winner_clicked();

private:
    Ui::MainWindow *ui;
    QTimer MiliTimer;
    QTimer SecondsTimer;
    QTimer MinutesTimer;
    int MiliSeconds=0;
    int Seconds=0;
    int Minutes=0;



};

#endif // MAINWINDOW_H
