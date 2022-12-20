// Question 3:
// Write a program that does the following:
// • Ask user to input three Real numbers a, b and c. They represent the parameters of a
// quadratic equation 𝑎𝑥! + 𝑏𝑥 + 𝑐 = 0
// • Classify to one of the following:
// - ’Infinite number of solutions’ (for example, 0𝑥! + 0𝑥 + 0 = 0 has infinite number of solutions)
// - ’No solution’ (for example, 0𝑥! + 0𝑥 + 4 = 0 has no solution)
// - ’No real solution’ (for example, 𝑥! + 4 = 0 has no real solutions)
// - ’One real solution’
// - ’Two real solutions’
// • In cases there are 1 or 2 real solutions, also print the solutions.
// Notes:
// 1. If 𝑎 ≠ 0 and there are real solutions to the equation, you can get these solutions using
//  the following formula:
// The number of solutions depends on whether (b2 -4ac) is positive, zero, or negative.
// 2. In order to calculate the square root of a number (of type double), you should call the sqrt function, located in the cmath library.
// Follow the syntax as demonstrated in the code below:
// Your program should interact with the user exactly as it shows in the following example: Please enter value of a: 1
// Please enter value of b: 4
// Please enter value of c: 4
// This equation has a single real solution x=-2.0
#include <iostream>
#include <cmath>

using namespace std;
int main()
{   
    double a;
    double b;
    double c;
    double square;
    double sqrt_plus;
    double sqrt_minus;
    double power;
    bool a_is_zero;
    bool square_is_zero;
    bool square_is_negative;
    bool all_are_0;



    

    cout<<"Please enter value of a: ";
    cin>>a;
    cout<<endl<<"Please enter value of b: ";
    cin>>b;
    cout<<endl<<"Please enter value of c: ";
    cin>>c;

    power = pow(b, 2);
    square = power - (4*a*c);
    //claculating plus or minus
    sqrt_plus = (-b + sqrt(square))/(2*a);
    sqrt_minus = (-b - (sqrt(square)))/(2*a);

    //bool flags created for if/else statement
    a_is_zero = (a == 0);
    all_are_0 = (a_is_zero && (b == 0) && (c == 0));
    square_is_zero = square == 0;
    square_is_negative = square < 0;

    if (all_are_0 == 1)
    {
        cout<<endl<<"Infinite solutions"<<endl;
    }
    else if (a_is_zero == 1)
    {
        cout<<endl<<"No solution"<<endl;
    }
    else if (square_is_zero == 1)
    {
        cout<<endl<<"One real solution: x = "<<sqrt_plus<<endl;
    }
    else if (square_is_negative == 1)
    {
        cout<<endl<<"No real solutions"<<endl;
    }
    else if (square_is_negative == 0)
    {
        cout<<endl<<"Two real solutions: "<<endl<<"Plus: x = "<<sqrt_plus<<endl<<"Minus: x = "<<sqrt_minus<<endl;
    }

    return 0;
}