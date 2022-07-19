#include <QDebug>

#include "wGameMenu.h"
#include "ui_wGameMenu.h"

wGameMenu::wGameMenu(QWidget *parent)
    : QWidget(parent), ui(new Ui::wGameMenu)
{
    ui->setupUi(this);
    connect(ui->btnLocalGame, &QPushButton::clicked, this, &wGameMenu::showLocalGameWindow);
}

wGameMenu::~wGameMenu()
{
    delete ui;
}

void wGameMenu::showLocalGameWindow()
{
    QString dlgTitle = QStringLiteral("请选择游戏人数");
    QString txtLabel = QStringLiteral("请输入游戏人数：");
    bool ok = false;
    int numPlayer = 0;
    while (!ok)
    {
        numPlayer = QInputDialog::getInt(this, dlgTitle, txtLabel, 2, 2, 6, 1, &ok);
        if (ok)
        {
            if (numPlayer != 5) break;
            else ok = false;
        }
    }
    this->hide();
    // qDebug() << "Number of Players:" << numPlayer;
    LocalGame = new wInGame(nullptr, &numPlayer);
    LocalGame->show();
    connect(LocalGame, &wInGame::closed, this, &wGameMenu::show);
}
