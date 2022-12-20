// Body mass index (BMI) is a number calculated from a person’s weight and height using the following formula: 𝑤𝑒𝑖𝑔h𝑡/h𝑒𝑖𝑔h𝑡!. Where 𝑤𝑒𝑖𝑔h𝑡 is in kilograms and h𝑒𝑖𝑔h𝑡 is in meters.
// According to the Centers for Disease Control and Prevention, the BMI is a fairly reliable indicator of body fatness for most people. BMI does not measure body fat directly, but research has shown that BMI correlates to direct measures of body fat, such as underwater weighing and dual-energy X-ray absorptiometry.
// The following table gives the weight status in respect to the BMI value:

// BMI Range
// Below 18.5 ... Underweight
// [18.5, 25) ... Normal
// [25, 30) ... Overweight 
// 30 and above ... Obese

// Write a program that prompts for weight (in pounds) and height (in inches) of a person, and prints the weight status of that person.
// Your program should interact with the user exactly as it shows in the following example: Please enter weight (in pounds): 135
// Please enter height (in inches): 71
// The weight status is: Normal
// Note: 1 pound is 0.453592 kilograms and 1 inch is 0.0254 meters.
#include <iostream>
#include <cmath>
using namespace std;
int main()
{   const double KG = 0.453592;
    const double METER = 0.0254;
    double weight;
    double height;
    double weight_met;
    double height_met;
    double BMI;
    cout<<"Please enter weight (in pounds): ";
    cin>>weight;
    cout<<endl<<"Please enter height (in inches): "; 
    cin>>height;
    weight_met = weight * KG;
    height_met = height * METER;
    BMI = (weight_met) / (height_met * height_met);
    
    bool underweight = (BMI < 18.5);
    bool norm = (18.5 <= BMI) && (BMI < 25);
    bool overweight = (25 <= BMI) && (BMI < 30);
    bool obese = (30 <= BMI);  

    if (underweight == 1)
    {
        cout<<"The weight status is: underweight"<<endl;
    }
    else if (norm == 1)
    {
        cout<< "The weight status is: normal"<<endl;
    }
    else if (overweight == 1)
    {
        cout<<"The weight status is: overweight"<<endl;
    }
    else if (obese == 1)
    {
        cout<<"The weight status is: obese"<<endl;
    }
    return 0;
}