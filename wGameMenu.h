#ifndef WGAMEMENU_H
#define WGAMEMENU_H

#include <QInputDialog>
#include <QWidget>

#include "wInGame.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class wGameMenu;
}
QT_END_NAMESPACE

class wGameMenu : public QWidget
{
    Q_OBJECT

public:
    wGameMenu(QWidget *parent = nullptr);
    ~wGameMenu();

private:
    Ui::wGameMenu *ui;
    wInGame *LocalGame, *AIGame;

public slots:
    void showLocalGameWindow();
    void showAIGameWindow();
};
#endif // WGAMEMENU_H
