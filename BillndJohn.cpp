#include <iostream>
using namespace std;

int main()
{   
    //declare john time
    int days_j;
    int hours_j;
    int mins_j;
    //declare bill time
    int days_b;
    int hours_b;
    int mins_b;
    //create variable to hold their sums
    int days_tot = 0;
    int hours_tot = 0;
    int mins_tot = 0;
    //declare time constants
    const int MINS_IN_HOURS = 60;
    const int HOURS_IN_DAYS = 24;

    //get john time from user
    cout<<"Please enter the number of days John has worked: ";
    cin>>days_j;
    cout<<endl<<"Please enter the number of hours John has worked: ";
    cin>>hours_j;
    cout<<endl<<"Please enter the number of minutes John has worked: ";
    cin>>mins_j;

    //get bill time from user
    cout<<endl<<"Please enter the number of days Bill has worked: ";
    cin>>days_b;
    cout<<endl<<"Please enter the number of hours Bill has worked: ";
    cin>>hours_b;
    cout<<endl<<"Please enter the number of minutes Bill has worked: ";
    cin>>mins_b;

    //assign the sum of their respective units of time to their total variable
    days_tot = days_b + days_j;
    hours_tot = hours_b + hours_j;
    mins_tot = mins_b + mins_j;

    //find the number of hours in total minutes. 
    //Add these hours to the total hour variable
    //Reset the value for total mins to the quotient remainder
    hours_tot += mins_tot / MINS_IN_HOURS;
    mins_tot = mins_tot % MINS_IN_HOURS;

    //find the number of days in total hours 
    //Add these days to the total days variable
    //Reset the value for total hours to the quotient remainder
    days_tot += hours_tot / HOURS_IN_DAYS;
    hours_tot = hours_tot % HOURS_IN_DAYS;

    //Print time to user
    cout<<"The total time both of them worked together is: ";
    cout<<days_tot<<" days, "<<hours_tot<<" hours, "<<mins_tot;
    cout<<" minutes.";

    return 0; 
}