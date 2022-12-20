#include <iostream>
using namespace std;
int main()
{
    string name;
    int graduation = 0;
    int current = 0;
    int difference = 0;
    const int freshman = 4;
    const int sophomore = 3;
    const int junior = 2;
    const int senior = 1;
    const int graduated = 0;
    cout<<"Please enter your name: "<<endl;
    cin>>name;
    cout<<"Please enter your graduation year: "<<endl;
    cin>>graduation;
    cout<<"Please enter current year: "<<endl;
    cin>>current;
    difference = graduation - current; 
    if (difference > 4)
        {
            cout<<name<<", you are not in college yet"<<endl;
        }
    else if (difference == freshman)
        {
            cout<<name<<", you are a Freshman"<<endl;
        }
    else if (difference == sophomore)
        {
            cout<<name<<", you are a Sophomore"<<endl;
        }
    else if (difference == junior)
        {
            cout<<name<<", you are a Junior"<<endl;
        }
    else if (difference == senior)
        {
            cout<<name<<", you are a Senior"<<endl;
        }
    else if (difference <= graduated)
        {
            cout<<name<<", you are graduated"<<endl;
        }
    return 0;
}