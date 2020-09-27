#include "dialog.h"
#include "ui_plan.h"

#include <QStandardItemModel>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::createView(QAbstractItemModel *model)
{
    ui->tableView->setModel(model);
    for(int col = 0; col < 13; col++)
    {
        ui->tableView->setColumnWidth(col, 100);
    }
    return 0;
}
