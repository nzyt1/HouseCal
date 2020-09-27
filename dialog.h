#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QAbstractItemModel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int createView(QAbstractItemModel *model);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
