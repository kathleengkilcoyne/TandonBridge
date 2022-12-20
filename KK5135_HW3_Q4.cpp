// Question 4:
// Define the following constants:
// Write a program that asks the user to enter a Real number, then it asks the user to enter the method by which they want to round that number (floor, ceiling or to the nearest integer). The program will then print the rounded result.
// Your program should interact with the user exactly as it shows in the following example: Please enter a Real number:
// 4.78
// Choose your rounding method:
// 1. Floor round
// 2. Ceiling round
// 3. Round to the nearest whole number 2
// 5
// Implementation requirements:
// 1. Use a switch statement.
// 2. You are not allowed to include and use the math library.
#include <iostream>
using namespace std;
int main()
{
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    double user_num;
    double decimal;
    int menu_no;
    int floor;

    int ceiling;

    cout<<"Please enter a Real number: ";
    cin>>user_num;
    cout<<endl<<"Choose your rounding method: "<<endl<<"1. Floor round"<<endl;
    cout<<"2. Ceiling round"<<endl<<"3. Round to the nearest whole number"<<endl;
    cin>>menu_no;

    floor = int(user_num);
    decimal = user_num - floor;

    switch(menu_no)
    {
        case FLOOR_ROUND:
            cout<<endl<<floor;
            break;
        case CEILING_ROUND:
            if (user_num < 0 || decimal == 0)
            {
                 cout<<endl<<floor;
                break;
            }
            else
            {
                int ceiling;
                user_num += 1;
                ceiling = int(user_num);
                cout<<ceiling;
                break;
            }
        case ROUND:
            if (decimal >= 0.5)
            {
                int ceiling;
                user_num += 1;
                ceiling = int(user_num);
                cout<<ceiling;
            }
            else
            {
                floor = int(user_num);
                cout<<endl<<floor;
            }
            break;
        default:
            cout<<"error";
    }

    return 0;
}