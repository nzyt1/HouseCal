#include "model.h"
#include <QDebug>

int Repayment::setIncome(float money)
{
    this->income = money;
    return 0;
}

float Repayment::getIncome()
{
    return this->income;
}

int Repayment::setExpers(float money)
{
    this->expers = money;
    return 0;
}

float Repayment::getExpers()
{
    return this->expers;
}

int Repayment::setSavings(float money)
{
    this->savings = money;
    return 0;
}

float Repayment::getSavings()
{
    return this->savings;
}

int Repayment::setFundSavings(float money)
{
    this->fundSavings = money;
    return 0;
}

float Repayment::getFundSavings()
{
    return this->fundSavings;
}

int Repayment::setArrears(float money)
{
    this->arrears = money;
    return 0;
}

float Repayment::getArrears()
{
    return arrears;
}

int Repayment::setBankRepay(float money)
{
    this->bankRepay = money;
    return 0;
}

float Repayment::getBankRepay()
{
    return this->bankRepay;
}

int Repayment::setBankArrears(float money)
{
    this->bankArrears = money;
    return 0;
}

float Repayment::getBankArrears()
{
    return this->bankArrears;
}

int Repayment::setFundRepay(float money)
{
    this->fundRepay = money;
    return 0;
}

float Repayment::getFundRepay()
{
    return this->fundRepay;
}

int Repayment::setFundArrears(float money)
{
    this->fundArrears = money;
    return 0;
}

float Repayment::getFundArrears()
{
    return this->fundArrears;
}

int Repayment::setBankPrincipal(float money)
{
    this->bankPrincipal = money;
    return 0;
}

float Repayment::getBankPrincipal()
{
    return this->bankPrincipal;
}

int Repayment::setBankInterest(float money)
{
    this->bankInterest = money;
    return 0;
}

float Repayment::getBankInterest()
{
    return this->bankInterest;
}

int Repayment::setFundPrincipal(float money)
{
    this->fundPrincipal = money;
    return 0;
}

float Repayment::getFundPrincipal()
{
    return this->fundPrincipal;
}

int Repayment::setFundInterest(float money)
{
    this->fundInterest = money;
    return 0;
}

float Repayment::getFundInterest()
{
    return this->fundInterest;
}

int Person::setBaseWage(float wage)
{
    this->baseWage = wage;
    return 0;
}

float Person::getBaseWage()
{
    return this->baseWage;
}

int Person::setPerfWage(float wage)
{
    this->perfWage = wage;
    return 0;
}

float Person::getPerfWage()
{
    return this->perfWage;
}

int Person::setSubsidy(float subsidy)
{
    this->subsidy = subsidy;
    return 0;
}

float Person::getSubsidy()
{
    return this->subsidy;
}

int Person::setInsureRate(float rate)
{
    this->insureRate = rate;
    return 0;
}

float Person::getInsureRate()
{
    return this->insureRate;
}

int Person::setInsure(float insure)
{
    this->insure = insure;
    return 0;
}

float Person::getInsure()
{
    return this->insure;
}

int Person::setFundRate(float rate)
{
    this->fundRate = rate;
    return 0;
}

float Person::getFundRate()
{
    return this->fundRate;
}

int Person::setFund(float fund)
{
    this->fund = fund;
    return 0;
}

float Person::getFund()
{
    return this->fund;
}

int Person::setAward(float award)
{
    this->award = award;
    return 0;
}

float Person::getAward()
{
    return this->award;
}

int Person::setDedection(float money)
{
    this->dedection = money;
    return 0;
}

float Person::getDedection()
{
    return this->dedection;
}

int Person::setTax(float tax)
{
    this->tax = tax;
    return 0;
}

float Person::getTax()
{
    return this->tax;
}

int Family::setDebt(float debt)
{
    if(debt < 0)
    {
        this->debt = 0;
    }else{
        this->debt = debt;
    }
    return 0;
}

float Family::getDebt()
{
    return debt;
}

int Family::setFood(float food)
{
    this->food = food;
    return 0;
}

float Family::getFood()
{
    return this->food;
}

int Family::setRent(float rent)
{
    this->rent = rent;
    return 0;
}

float Family::getRent()
{
    return this->rent;
}

int Family::setSaving(float saving)
{
    this->saving = saving;
    return 0;
}

float Family::getSaving()
{
    return this->saving;
}

int Family::setOthers(float others)
{
    this->others = others;
    return 0;
}

float Family::getOthers()
{
    return this->others;
}

int Family::getFundBalance()
{
    return this->fundBalance;
}

int Family::setFundBalance(float money)
{
    this->fundBalance = money;
    return 0;
}

int House::setYears(int years)
{
    this->years = years;
    return 0;
}

int House::getYears()
{
    return this->years;
}

int House::setPrice(float price)
{
    this->price = price;
    return 0;
}

float House::getPrice()
{
    return this->price;
}

int House::setBankIoan(float ioan)
{
    if(ioan < 0)
    {
        this->bankIoan = 0;
    }else{
        this->bankIoan = ioan;
    }

    return 0;
}

float House::getBankIoan()
{
    return this->bankIoan;
}

int House::setBankRate(float rate)
{
    this->bankRate = rate;
    return 0;
}

float House::getBankRate()
{
    return this->bankRate;
}

int House::setFundIoan(float ioan)
{
    this->fundIoan = ioan;
    return 0;
}

float House::getFundIoan()
{
    return this->fundIoan;
}

int House::setFundRate(float rate)
{
    this->fundRate = rate;
    return 0;
}

float House::getFundRate()
{
    return this->fundRate;
}

int House::setDownpay(float downpay)
{
    this->downpay = downpay;
    return 0;
}

float House::getDownpay()
{
    return this->downpay;
}

int House::setDownpayRate(float rate)
{
    this->downpayRate = rate;
    return 0;
}

float House::getDownpayRate()
{
    return this->downpayRate;
}
