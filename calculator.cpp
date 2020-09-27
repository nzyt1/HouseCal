#include "calculator.h"
#include "ui_calculator.h"
#include "utils.h"

#include <QValidator>
#include <QIntValidator>
#include <QDebug>
#include <QString>

Person *husb = new Person();
Person *wife = new Person();
Family *family = new Family();
House *house = new House();
QList<Repayment> *repays = new QList<Repayment>;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    Calculator::setValidator();

}

int Calculator::setValidator()
{
    QValidator *intValidator = new QIntValidator(0, 5000000, this);
    QList<QLineEdit*> lineedits = ui->centralwidget->findChildren<QLineEdit*>();
    foreach (QLineEdit* var, lineedits) {
        if(var->objectName() == "qt_spinbox_lineedit")
        {
            continue;
        }
        var->setValidator(intValidator);

    }
    return 0;
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_avgCapButton_clicked()
{
    showData(husb, wife, family, house);

    calAvgCap();

    QStandardItemModel *model = new QStandardItemModel(house->getYears() * 12, 13);
    dialog = new Dialog(this);
    setHeader(model);
    showModel(model);
    dialog->createView(model);
    dialog->setModal(true);
    dialog->show();
}

void Calculator::on_avgCapIntButton_clicked()
{
    showData(husb, wife, family, house);

    calAvgCapInt();

    QStandardItemModel *model = new QStandardItemModel(house->getYears() * 12, 13);
    dialog = new Dialog(this);
    setHeader(model);
    showModel(model);
    dialog->createView(model);
    dialog->setModal(true);
    dialog->show();
}

int Calculator::setHeader(QStandardItemModel *model)
{
    QStringList labels = (QStringList() << "收入" << "支出" << "积蓄" << "公金积蓄" << "欠款" << "商贷欠款"
                          << "商贷还款" << "商贷本金" << "商贷利息" << "公金欠款" << "公金还款" << "公金本金" << "公金利息" );
    model->setHorizontalHeaderLabels(labels);
    return 0;
}

int Calculator::calAvgCap()
{
    repays->clear();

    float bankrepay = calAvgCapMouth(house->getBankIoan(), house->getBankRate() / 12, house->getYears() * 12);
    float fundrepay = calAvgCapMouth(house->getFundIoan(), house->getFundRate() / 12, house->getYears() * 12);

    for(int index = 0; index < house->getYears() * 12; index ++)
    {
        Repayment *repay = new Repayment();

        repay->setIncome(salaryAfterTax(*husb, index) + salaryAfterTax(*wife, index)
                         + husb->getPerfWage() + wife->getPerfWage()
                         + husb->getSubsidy() + wife->getSubsidy());
        if(index % 12 == 11)
        {
            repay->setIncome(repay->getIncome() + husb->getAward() + wife->getAward());
        }

        repay->setExpers(family->getRent() + family->getFood() + family->getOthers());
        repay->setArrears(family->getDebt());
        repay->setBankRepay(bankrepay);
        repay->setFundRepay(fundrepay);

        if(index == 0)
        {
            repay->setSavings(0 + repay->getIncome() - repay->getExpers());
            repay->setFundSavings(family->getFundBalance() + husb->getFund() + wife->getFund() - repay->getFundRepay());

            repay->setBankInterest(house->getBankIoan() * house->getBankRate() / 12);
            repay->setBankPrincipal(repay->getBankRepay() - repay->getBankInterest());
            repay->setBankArrears(house->getBankIoan() - repay->getBankPrincipal());

            repay->setFundInterest(house->getFundIoan() * house->getFundRate() / 12);
            repay->setFundPrincipal(repay->getFundRepay() - repay->getFundInterest());
            repay->setFundArrears(house->getFundIoan() - repay->getFundPrincipal());
        }else{
            repay->setSavings(repays->last().getSavings() + repay->getIncome() - repay->getExpers());
            repay->setFundSavings(repays->last().getFundSavings() + husb->getFund() + wife->getFund() - repay->getFundRepay());

            repay->setBankInterest(repays->last().getBankArrears() * house->getBankRate() / 12);
            repay->setBankPrincipal(repay->getBankRepay() - repay->getBankInterest());
            repay->setBankArrears(repays->last().getBankArrears() - repay->getBankPrincipal());

            repay->setFundInterest(repays->last().getFundArrears() * house->getFundRate() / 12);
            repay->setFundPrincipal(repay->getFundRepay() - repay->getFundInterest());
            repay->setFundArrears(repays->last().getFundArrears() - repay->getFundPrincipal());
        }

        repays->append(*repay);
    }

    return 0;
}

int Calculator::calAvgCapInt()
{
    repays->clear();

    for(int index = 0; index < house->getYears() * 12; index ++)
    {
        Repayment *repay = new Repayment();

        repay->setIncome(salaryAfterTax(*husb, index) + salaryAfterTax(*wife, index)
                         + husb->getPerfWage() + wife->getPerfWage()
                         + husb->getSubsidy() + wife->getSubsidy());
        if(index % 12 == 11)
        {
            repay->setIncome(repay->getIncome() + husb->getAward() + wife->getAward());
        }

        repay->setExpers(family->getRent() + family->getFood() + family->getOthers());
        repay->setArrears(family->getDebt());

        repay->setBankPrincipal(house->getBankIoan() / house->getYears() / 12);
        repay->setFundPrincipal(house->getFundIoan() / house->getYears() / 12);

        if(index == 0)
        {
            repay->setSavings(0 + repay->getIncome() - repay->getExpers());
            repay->setFundSavings(family->getFundBalance() + husb->getFund() + wife->getFund() - repay->getFundRepay());

            repay->setBankInterest(house->getBankIoan() * house->getBankRate() / 12);
            repay->setBankArrears(house->getBankIoan() - repay->getBankPrincipal());

            repay->setFundInterest(house->getFundIoan() * house->getFundRate() / 12);
            repay->setFundArrears(house->getFundIoan() - repay->getFundPrincipal());
        }else{
            repay->setSavings(repays->last().getSavings() + repay->getIncome() - repay->getExpers());
            repay->setFundSavings(repays->last().getFundSavings() + husb->getFund() + wife->getFund() - repay->getFundRepay());

            repay->setBankInterest(repays->last().getBankArrears() * house->getBankRate() / 12);
            repay->setBankArrears(repays->last().getBankArrears() - repay->getBankPrincipal());

            repay->setFundInterest(repays->last().getFundArrears() * house->getFundRate() / 12);
            repay->setFundArrears(repays->last().getFundArrears() - repay->getFundPrincipal());
        }

        repay->setBankRepay(repay->getBankPrincipal() + repay->getBankInterest());
        repay->setFundRepay(repay->getFundPrincipal() + repay->getFundInterest());

        repays->append(*repay);
    }

    return 0;
}

int Calculator::showModel(QStandardItemModel *model)
{
    if(repays->isEmpty())
    {
        return 0;
    }

    for(int row = 0; row < model->rowCount(); ++row) {
        Repayment repay = repays->at(row);
        for(int column = 0; column < model->columnCount(); ++ column) {
            QStandardItem *item;
            switch(column)
            {
            case 0:
                item = new QStandardItem(QString::number(repay.getIncome(), 'f', 2));
                break;
            case 1:
                item = new QStandardItem(QString::number(repay.getExpers(), 'f', 2));
                break;
            case 2:
                item = new QStandardItem(QString::number(repay.getSavings(), 'f', 2));
                break;
            case 3:
                item = new QStandardItem(QString::number(repay.getFundSavings(), 'f', 2));
                break;
            case 4:
                item = new QStandardItem(QString::number(repay.getArrears(), 'f', 2));
                break;
            case 5:
                item = new QStandardItem(QString::number(repay.getBankArrears(), 'f', 2));
                break;
            case 6:
                item = new QStandardItem(QString::number(repay.getBankRepay(), 'f', 2));
                break;
            case 7:
                item = new QStandardItem(QString::number(repay.getBankPrincipal(), 'f', 2));
                break;
            case 8:
                item = new QStandardItem(QString::number(repay.getBankInterest(), 'f', 2));
                break;
            case 9:
                item = new QStandardItem(QString::number(repay.getFundArrears(), 'f', 2));
                break;
            case 10:
                item = new QStandardItem(QString::number(repay.getFundRepay(), 'f', 2));
                break;
            case 11:
                item = new QStandardItem(QString::number(repay.getFundPrincipal(), 'f', 2));
                break;
            case 12:
                item = new QStandardItem(QString::number(repay.getFundInterest(), 'f', 2));
                break;
            default:
                break;
            }

            item->setBackground(QColor(0xF1, 0xF3, 0xF8));

            if(repay.getSavings() > repay.getArrears())
            {
                item->setBackground(QColor(0xD6, 0xE0, 0xF0));
            }
            if(repay.getSavings() > (repay.getArrears() + repay.getBankArrears()))
            {
                item->setBackground(QColor(0x8D, 0x93, 0xAD));
                item->setForeground(QColor(0xFF, 0xFF, 0xFF));
            }

            model->setItem(row, column, item);
        }
    }
    return 0;
}

/**
* Code after this comment is used by UI.
**/

int Calculator::setHusbBaseWage()
{
    husb->setBaseWage(ui->lineEditHusBaseWage->text().toInt());
    husb->setInsure((float)husb->getBaseWage() * husb->getInsureRate());
    husb->setFund((float)husb->getBaseWage() * husb->getFundRate() * 2);
    ui->lineEditHusInsure->setText(QString::number(husb->getInsure()));
    ui->lineEditHusFund->setText(QString::number(husb->getFund()));
    return 0;
}

int Calculator::setHusbPerfWage()
{
    husb->setPerfWage(ui->lineEditHusPerfWage->text().toInt());
    return 0;
}

int Calculator::setHusbSubsidy()
{
    husb->setSubsidy(ui->lineEditHusSubsidy->text().toInt());
    return 0;
}

int Calculator::setHusbFundRate()
{
    husb->setFundRate(ui->comboBoxHusFundRate->currentText().toFloat() / 100);
    husb->setFund((float)husb->getBaseWage() * husb->getFundRate() * 2);
    ui->lineEditHusFund->setText(QString::number(husb->getFund()));
    return 0;
}

int Calculator::setHusbAward()
{
    husb->setAward(ui->lineEditHusAward->text().toInt());
    return 0;
}

int Calculator::setHusbDedection()
{
    husb->setDedection(ui->lineEditHusDedection->text().toInt());
    return 0;
}

int Calculator::setWifeBaseWage()
{
    wife->setBaseWage(ui->lineEditWifeBaseWage->text().toInt());
    wife->setInsure((float)wife->getBaseWage() * wife->getInsureRate());
    wife->setFund((float)wife->getBaseWage() * wife->getFundRate() * 2);
    ui->lineEditWifeInsure->setText(QString::number(wife->getInsure()));
    ui->lineEditWifeFund->setText(QString::number(wife->getFund()));
    return 0;
}

int Calculator::setWifePerfWage()
{
    wife->setPerfWage(ui->lineEditWifePerfWage->text().toInt());
    return 0;
}

int Calculator::setWifeSubsidy()
{
    wife->setSubsidy(ui->lineEditWifeSubsidy->text().toInt());
    return 0;
}

int Calculator::setWifeFundRate()
{
    wife->setFundRate(ui->comboBoxWifeFundRate->currentText().toFloat() / 100);
    wife->setFund((float)wife->getBaseWage() * wife->getFundRate() * 2);
    ui->lineEditWifeFund->setText(QString::number(wife->getFund()));
    return 0;
}

int Calculator::setWifeAward()
{
    wife->setAward(ui->lineEditWifeAward->text().toInt());
    return 0;
}

int Calculator::setWifeDedection()
{
    wife->setDedection(ui->lineEditWifeDedection->text().toInt());
    return 0;
}

int Calculator::setFamilyDebt()
{
    family->setDebt(ui->lineEditDebt->text().toInt());
    return 0;
}

int Calculator::setFamilyFood()
{
    family->setFood(ui->lineEditFood->text().toInt());
    return 0;
}

int Calculator::setFamilyRent()
{
    family->setRent(ui->lineEditRent->text().toInt());
    return 0;
}

int Calculator::setFamilyMoney()
{
    family->setSaving(ui->lineEditReady->text().toFloat());
    family->setDebt(house->getDownpay() - family->getSaving());
    ui->lineEditDebt->setText(QString::number(family->getDebt()));
    return 0;
}

int Calculator::setFamilyOthers()
{
    family->setOthers(ui->lineEditOthers->text().toFloat());
    return 0;
}

int Calculator::setFamilyFundBalance()
{
    family->setFundBalance(ui->lineEditFundBalance->text().toFloat());
    return 0;
}

int Calculator::setHouseCycle()
{
    house->setYears(ui->comboBoxCycle->currentText().toInt());
    return 0;
}

int Calculator::setHousePrice()
{
    house->setPrice(ui->lineEditHousePrice->text().toInt());
    house->setDownpay(house->getPrice() * house->getDownpayRate());
    ui->lineEditDownPay->setText(QString::number(house->getDownpay()));
    family->setDebt(house->getDownpay() - family->getSaving());
    ui->lineEditDebt->setText(QString::number(family->getDebt()));
    house->setBankIoan(house->getPrice() - house->getFundIoan() - house->getDownpay());
    ui->lineEditBankIoan->setText(QString::number(house->getBankIoan(), 'f', 2));
    return 0;
}

int Calculator::setHouseDownpayRate()
{
    house->setDownpayRate(ui->comboBoxDownPayRate->currentText().toFloat() / 100);
    house->setDownpay(house->getPrice() * house->getDownpayRate());
    ui->lineEditDownPay->setText(QString::number(house->getDownpay()));
    return 0;
}

int Calculator::setHouseBankIoanRate()
{
    house->setBankRate(ui->doubleSpinBoxBankRate->value()/100);
    return 0;
}

int Calculator::setHouseFundIoan()
{
    house->setFundIoan(ui->lineEditFundIoan->text().toInt());
    house->setBankIoan(house->getPrice() - house->getFundIoan() - house->getDownpay());
    ui->lineEditBankIoan->setText(QString::number(house->getBankIoan(), 'f', 2));
    return 0;
}
