#include <iostream>
using namespace std;

int main()
{   //declarations.
    // set all ints to 0 so no strange values
    int dollars = 0;
    int cents = 0;
    int total_cents = 0;
    int quarters;
    int dimes;
    int nickles;
    int pennies;
    //constant declarations
    const int PENNIES_IN_DOLLAR = 100;
    const int CENTS_IN_QUARTER = 25;
    const int CENTS_IN_DIME = 10;
    const int CENTS_IN_NICKLE = 5;
    const int CENTS_IN_PENNY = 1;

    //get inputs from user
    cout<<"Please enter number of coins:"<<endl;
    cout<<"# of quarters: ";
    cin>>quarters;
    cout<<endl<<"# of dimes: ";
    cin>>dimes;
    cout<<"# of nickles: ";
    cin>>nickles;
    cout<<endl<<"# of pennies: ";
    cin>>pennies;

    //find total cents first
    total_cents += (quarters * CENTS_IN_QUARTER) + (dimes * CENTS_IN_DIME) + (nickles * CENTS_IN_NICKLE) + (pennies * CENTS_IN_PENNY);
    //divide total cents by 100 (PENNIES_IN_DOLLAR) 
    dollars = total_cents/ PENNIES_IN_DOLLAR;
    //then set cents to mod 100
    cents = total_cents % PENNIES_IN_DOLLAR;
    
    //report dollars and cents to user
    cout<<endl<<"The total is "<<dollars<<" dollars and "<<cents<<" cents"<<endl;
    return 0;
}
