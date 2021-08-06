#include<iostream>
#include<chrono>
#include<fstream>
#include<cmath>
#include<limits>
#include "Files/Color.h"

using namespace std;

int main()
{
    Color obj;

    cout << "\n";

    obj.setN();
    obj.setK();
    obj.setM();
    obj.setR();

    cout << "\n";

    obj.Start();
    cout << "There are " << obj.getS() << " many PPS.\n";

    return 0;
}