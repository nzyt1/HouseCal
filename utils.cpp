#include "utils.h"

#include <cmath>
#include <QDebug>

float calAvgCapMouth(float total, float rate, int mouth)
{
    qDebug() << "calAvgCapMouth" << total << rate << mouth;
    float repay = 0.0;
    float multiplier = pow((1 + rate), mouth) / (pow((1 + rate), mouth) - 1);
    qDebug() << "calAvgCapMouth" << multiplier;
    repay = (float)total * rate * multiplier;
    qDebug() << "calAvgCapMouth" << repay;
    return repay;
}

float salaryAfterTax(Person person, int index)
{
    int mouth = index % 12 + 1;
    if(mouth == 1)
    {
        person.setTax(0.0);
    }
    float tax = 0.0;
    float tax_salary = (person.getBaseWage() - TAX_THRESHOLD - person.getInsure() - person.getFund() / 2 - person.getDedection()) * mouth;

    if(tax_salary < 0)
    {
        tax = 0;
    }else if(tax_salary < 36000)
    {
        tax = tax_salary * 0.03;
    }else if(tax_salary < 144000)
    {
        tax = tax_salary * 0.1 - 2520;
    }else if(tax_salary < 300000)
    {
        tax = tax_salary * 0.2 - 16920;
    }else if(tax_salary < 420000)
    {
        tax = tax_salary * 0.25 - 31920;
    }else if(tax_salary < 660000)
    {
        tax = tax_salary * 0.3 - 52920;
    }else if(tax_salary < 960000)
    {
        tax = tax_salary * 0.35 - 85920;
    }else{
        tax = tax_salary * 0.4 - 181920;
    }
    tax = tax - person.getTax();
    person.setTax(person.getTax() + tax);

    qDebug() << "Mouth" << mouth << "TAX" << tax;

    return person.getBaseWage() - person.getInsure() - person.getFund() / 2 - tax;
}


int showData(Person *husb, Person *wife, Family *family, House *house)
{
    qDebug() << "收入";
    qDebug() << "丈夫";
    qDebug() << "基本工资" << husb->getBaseWage();
    qDebug() << "绩效工资" << husb->getPerfWage();
    qDebug() << "补贴" << husb->getSubsidy();
    qDebug() << "税后收入";
    qDebug() << "公金" << husb->getFund();
    qDebug() << "妻子";
    qDebug() << "基本工资" << wife->getBaseWage();
    qDebug() << "绩效工资" << wife->getPerfWage();
    qDebug() << "补贴" << wife->getSubsidy();
    qDebug() << "税后收入";
    qDebug() << "公金" << wife->getFund();
    qDebug() << "家庭支出";
    qDebug() << "住房" << family->getRent();
    qDebug() << "食物" << family->getFood();
    qDebug() << "其他" << family->getOthers();
    qDebug() << "资金";
    qDebug() << "现有资金" << family->getSaving();
    qDebug() << "欠款" << family->getDebt();
    qDebug() << "房子";
    qDebug() << "价格" << house->getPrice();
    qDebug() << "首付" << house->getDownpay();
    qDebug() << "公金贷款" << house->getFundIoan();
    qDebug() << "银行贷款" << house->getBankIoan();
    qDebug() << "贷款年限" << house->getYears();
    return 0;
}
