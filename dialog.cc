#include <QDialog>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>

#include "dialog.hh"

Dialog::Dialog(QWidget * par) : QDialog(NULL)
{
  QVBoxLayout * layout = new QVBoxLayout(this);
  QMenuBar * bar = new QMenuBar;
  layout->addWidget(bar);
  QMenu * menu = new QMenu("Stuff");
  QAction * ac = new QAction("Close stuff");
  connect(ac, SIGNAL(triggered()), SLOT(accept()));
  menu->addAction(ac);

  bar->addMenu(menu);
  // // ac->setEnabled(true);
  // bar->setEnabled(true);
  // bar->setNativeMenuBar(false);

  layout->addStretch(1);


  
  QDialogButtonBox * buttons =
    new QDialogButtonBox(QDialogButtonBox::Ok,
                         Qt::Horizontal);
  layout->addWidget(buttons);

  connect(buttons, SIGNAL(accepted()), SLOT(accept()));

}
