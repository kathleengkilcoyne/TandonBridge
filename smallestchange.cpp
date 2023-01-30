#include <iostream>
using namespace std;

int main()
{   //set all variables waiting assignment to 0
    int dollars = 0;
    int cents = 0;
    int quarters = 0;
    int dimes = 0;
    int nickles = 0;
    int pennies = 0;
    //these are counters that will be reset as the program does its calculations for each coin
    int centdiv = 0;
    int centmod = 0;
    //set all constants for math
    const int QUARTERS_IN_DOLLAR = 4;
    const int CENTS_IN_QUARTER = 25;
    const int CENTS_IN_DIME = 10;
    const int CENTS_IN_NICKLE = 5;
    const int CENTS_IN_PENNY = 1;

    //prompt user for value and store in variable
    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollars>>cents;
    //break up dollars into quarters first because we already know 4 quarters is the smallest amount of change for a dollar
    quarters = dollars * QUARTERS_IN_DOLLAR;
    //break remaining cents down now add however many additional quarters there are in cents to the value calculated for quarters in the dollar value
    centdiv = cents / CENTS_IN_QUARTER;
    quarters += centdiv;
    //set counter for remaining change
    centmod = cents % CENTS_IN_QUARTER;
    //use this counter to find how many whole coins there are
    centdiv = centmod / CENTS_IN_DIME;
    dimes += centdiv;
    //reset counter as coins get smaller to continue
    centmod = centmod % CENTS_IN_DIME;
    centdiv = centmod / CENTS_IN_NICKLE;
    nickles += centdiv;
    centmod = centmod % CENTS_IN_NICKLE;
    centdiv = centmod / CENTS_IN_PENNY;
    pennies += centdiv;
    //report calculations to user
    cout<<dollars<<" dollars and "<<cents<<" cents are:"<<endl;
    cout << quarters<<" quarters, "<<dimes<<" dimes, "<<nickles<<" nickles, and "<<pennies<<" pennies."<<endl;

    return 0;
}
