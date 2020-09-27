#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>

class Person
{
private:
    float baseWage;
    float perfWage;
    float subsidy;
    float insureRate = 0.11;
    float insure;
    float fundRate = 0.05;
    float fund;
    float award;
    float dedection = 0;
    float tax = 0.0;

public:
    int setBaseWage(float wage);
    float getBaseWage();
    int setPerfWage(float wage);
    float getPerfWage();
    int setSubsidy(float subsidy);
    float getSubsidy();
    int setInsureRate(float rate);
    float getInsureRate();
    int setInsure(float insure);
    float getInsure();
    int setFundRate(float rate);
    float getFundRate();
    int setFund(float fund);
    float getFund();
    int setAward(float award);
    float getAward();
    int setDedection(float dedecte);
    float getDedection();
    int setTax(float tax);
    float getTax();
};

class Family
{
private:
    float rent;
    float food;
    float others;
    float saving;
    float debt;
    float fundBalance;

public:
    int setRent(float rent);
    float getRent();
    int setFood(float food);
    float getFood();
    int setOthers(float others);
    float getOthers();
    int setSaving(float saving);
    float getSaving();
    int setDebt(float debt);
    float getDebt();
    int setFundBalance(float balance);
    int getFundBalance();
};

class House
{
private:
    float price;
    float downpay;
    float downpayRate = 0.3;
    float fundIoan;
    float fundRate = 0.0325;
    float bankIoan;
    float bankRate = 0.0465;
    int years = 10;

public:
    int setPrice(float price);
    float getPrice();
    int setDownpay(float downpay);
    float getDownpay();
    int setDownpayRate(float rate);
    float getDownpayRate();
    int setFundIoan(float ioan);
    float getFundIoan();
    int setFundRate(float rate);
    float getFundRate();
    int setBankIoan(float ioan);
    float getBankIoan();
    int setBankRate(float rate);
    float getBankRate();
    int setYears(int years);
    int getYears();

};

class Repayment
{
private:
    float income;
    float expers;
    float savings;
    float fundSavings;
    float arrears;
    float bankRepay;
    float bankArrears;
    float bankPrincipal;
    float bankInterest;
    float fundRepay;
    float fundArrears;
    float fundPrincipal;
    float fundInterest;

public:
    int setIncome(float money);
    float getIncome();
    int setExpers(float money);
    float getExpers();
    int setSavings(float money);
    float getSavings();
    int setFundSavings(float money);
    float getFundSavings();
    int setArrears(float money);
    float getArrears();
    int setBankRepay(float money);
    float getBankRepay();
    int setBankArrears(float money);
    float getBankArrears();
    int setFundRepay(float money);
    float getFundRepay();
    int setFundArrears(float money);
    float getFundArrears();
    int setBankPrincipal(float money);
    float getBankPrincipal();
    int setBankInterest(float money);
    float getBankInterest();
    int setFundPrincipal(float money);
    float getFundPrincipal();
    int setFundInterest(float money);
    float getFundInterest();
};

#endif // MODEL_H
