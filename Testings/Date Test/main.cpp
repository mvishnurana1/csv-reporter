#include <iostream>
#include "date.h"
using namespace std;

int main()
{

    Date d;

    d.setDay(2);
    d.setMonth(5);
    d.setYear(1223);

    cout << d.getDay()<<"-" << d.getMonth()<<"-" << d.getYear();
}
