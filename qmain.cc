/// qmain.cc
/// A file to test the menus on MacOS

#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>

#include "dialog.hh"


class MainWin : public QMainWindow {
  void execDialog() {
    Dialog dlg(this);
    dlg.exec();
  };
public:
  MainWin() {
    QMenu * menu = new QMenu("File");
    QAction * ac = new QAction("Quit");
    connect(ac, SIGNAL(triggered()), SLOT(close()));
    menu->addAction(ac);
    menu->addSeparator();

    ac = new QAction("Test");
    QObject::connect(ac, &QAction::triggered, this, &MainWin::execDialog);
    menu->addAction(ac);
    
    menuBar()->addMenu(menu);
  };
};


int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  MainWin win;
  win.show();
  app.exec();
}
