#include "cal.h"
#include <iostream>

cal::cal(int num1,int num2): a(num1),b(num2) {};
int cal::add() {return a+b;}
int cal::subtract() {return a-b;}
int cal::multiply() {return a*b;}
int cal::divide() {return a/b;}

