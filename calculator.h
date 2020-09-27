#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "dialog.h"
#include "model.h"
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

public slots:
    void on_avgCapButton_clicked();
    void on_avgCapIntButton_clicked();
    int calAvgCap();
    int calAvgCapInt();
    int showModel(QStandardItemModel *model);
    int setHeader(QStandardItemModel *model);
    int setHusbBaseWage();
    int setHusbPerfWage();
    int setHusbSubsidy();
    int setHusbFundRate();
    int setHusbAward();
    int setHusbDedection();
    int setWifeBaseWage();
    int setWifePerfWage();
    int setWifeSubsidy();
    int setWifeFundRate();
    int setWifeAward();
    int setWifeDedection();
    int setFamilyRent();
    int setFamilyFood();
    int setFamilyOthers();
    int setFamilyMoney();
    int setFamilyDebt();
    int setFamilyFundBalance();
    int setHousePrice();
    int setHouseDownpayRate();
    int setHouseFundIoan();
    int setHouseBankIoanRate();
    int setHouseCycle();

private:
    Ui::Calculator *ui;
    Dialog *dialog;

    int setValidator();
};

#endif // CALCULATOR_H
