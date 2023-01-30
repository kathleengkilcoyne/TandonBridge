#include <iostream>
using namespace std;

int main()
{   //declare user entered variables
    int int_1;
    int int_2;
    //set arithmetic results to 0
    int sum = 0; 
    int difference = 0;
    int product = 0;
    float quotient = 0;
    int div = 0;
    int remainder = 0;
    //create float variables where int can be converted
    float float_1 = 0;
    float float_2 = 0;

    //get integers from user
    cout<<"Please enter two positive integers, separated by a space:"<<endl;
    cin>>int_1>>int_2;
    float_1 = int_1;
    float_2 = int_2;

    //do arithmetic and set results to their corresponding variable
    sum = int_1 + int_2;
    difference = int_1 - int_2;
    product = int_1 * int_2;
    quotient = float_1/float_2;
    div = int_1/int_2;
    remainder = int_1 % int_2;

    cout<<int_1<<" + "<<int_2<<" = "<<sum<<endl;
    cout<<int_1<<" - "<<int_2<<" = "<<difference<<endl;
    cout<<int_1<<" * "<<int_2<<" = "<<product<<endl;
    cout<<int_1<<" / "<<int_2<<" = "<<quotient<<endl;
    cout<<int_1<<" div "<<int_2<<" = "<<div<<endl;
    cout<<int_1<<" mod "<<int_2<<" = "<<remainder<<endl;


    return 0;
}