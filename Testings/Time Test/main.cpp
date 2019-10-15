#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time Obj;
    Obj.setHours(12);
    Obj.setMinutes(36);

    cout << Obj.getHours() <<":" <<Obj.getMinutes();

    return 0;
}
