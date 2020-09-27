#ifndef UTILS_H
#define UTILS_H

#include "model.h"

#define TAX_THRESHOLD 5000


float calAvgCapMouth(float total, float rate, int mouth);
float salaryAfterTax(Person person, int index);
int showData(Person *husb, Person *wife, Family *family, House *house);

#endif // UTILS_H
