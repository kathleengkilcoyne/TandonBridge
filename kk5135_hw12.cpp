/*CH12 #7: Write a checkbook balancing program. The program will read in, 
from the console, the following for all checks that were not cashed as of 
the last time you balanced your checkbook: the number of each check (int), 
the amount of the check (double), and whether or not it has been cashed 
(1 or 0, boolean in the array). Use an array with the class as the type.
The class should be a class for a check. There should be three member variables
to record the check number, the check amount, and whether or not the check was cashed.
The class for a check will have a member variable of type Money 
(as defined on page 662 in the book; Display 11.9) to record the check amount. 
So, you will have a class used within a class. 
The class for a check should have accessor and mutator functions as well as constructors and functions
for both input and output of a check. In addition to the checks, the program also reads all the deposits 
(from the console; cin), the old and the new account balance (read this in from the user at the console; cin).
You may want another array to hold the deposits. 
The new account balance should be the old balance plus all deposits, minus all checks that have been cashed.
The program outputs the total of the checks cashed, the total of the deposits, what the new balance should be,
and how much this figure differs from what the bank says the new balance is. 
It also outputs two lists of checks: the checks cashed 
since the last time you balanced your checkbook and the checks still not cashed. 
[ edit: if you can, Display both lists of checks in sorted order from lowest to highest check number.]
*/
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;



class Money
{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //precondition: amount1 and amount 2 have been given values
    //returns the sum of the values of amount 1 and amount 2
    friend bool operator ==(const Money& amount1, const Money& amount2);
    //precondition: amount 1 and amount 2 have been given values.
    //returns the sum of the values of amount1 and amount 2
    friend Money operator -(const Money& amount1, const Money& amount2);
    //precondition: amount1 and amount 2 have been given values
    //returns the difference of the values of amount 1 and amount 2
    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in -$100.00
    //precondition: If ins is a file input stream then ins has already been 
    //connected to the file
    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign
    //precondition if outs is a file output stream then outs has already been connected to a file

    //constructors below: 
    Money(long dollars, int cents);
    Money(long dollars);
    Money();

    double get_value() const;

private: 
    long all_cents;
};

class check : public Money
{
public:
    //constructors below: 
    check(int the_check_num, Money the_amount, bool the_check_cashed);
    check();

    //overloaded operators below
    //friend check operator -(const Money& account, const check& the_check);
    //precondition: amount1 and amount 2 have been given values
    //returns the difference of the values of the account with the cashed check taken out of the balance

    //friend check operator +(const Money& account, const check& the_check);
    //precondition: amount1 and amount 2 have been given values
    //returns the difference of the values of the account with the added check

    //friend istream& operator >>(istream& ins, check& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in -$100.00
    //precondition: If ins is a file input stream then ins has already been 
    //connected to the file

    friend ostream& operator <<(ostream& outs, const check& amount);
    //Overloads the << operator so it can be used to output values of type
    //prints full int for check num;
    //references << operator for money class when printing amount
    //prints cashed is cashed = true
    //prints not cashed if cashed == false
    //precondition if outs is a file output stream then outs has already been connected to a file

    int get_check_num() const;
    bool get_checkcashed() const;

private: 
    int check_num;
    bool check_cashed;
    Money amount;

};



int main()
{
    //The new account balance should be the old balance plus all deposits, minus all checks that have been cashed.
    //The program outputs the total of the checks cashed, the total of the deposits, what the new balance should be,
    //and how much this figure differs from what the bank says the new balance is. 
    //It also outputs two lists of checks: the checks cashed 
    //since the last time you balanced your checkbook and the checks still not cashed. 
    int volume_checks;
    cout<<"How many transactions are you recording today?"<<endl;
    cin>>volume_checks;
    Money initial_account_balance;
    int temp_num=0;
    bool cashed_true;
    //list for all checks, checks cashed, and not cashed
    check all_checks[60];
    check cashed[60];
    check not_cashed[60];
    //variable to hold values put in array of classes
    int cashed_count=0;
    int not_cashed_count=0;
    Money cashed_total;
    Money deposit_total;
    cashed_total= Money();
    deposit_total= Money();
    Money temp_amount;
    
    bool check_yes_deposit_no;
    cout<<"What was your last recorded bank balance?"<<endl;
    cin>>initial_account_balance;
    Money bank_balance = initial_account_balance;
    Money checkbook_balance = initial_account_balance;
    for (int i =0; i < volume_checks; i++)
    {
        //determine if transaction is deposit or check cashed
        cout<<"New Transaction: Check or deposit? (enter 1 for check and 0 for deposit)"<<endl;
        cin>>check_yes_deposit_no;
        if (check_yes_deposit_no==0)
        {
            Money temp_deposit;
            cout<<i+1<<": How much are you depositing?"<<endl;
            cin>>temp_deposit;
            deposit_total= deposit_total+temp_deposit;
            initial_account_balance= initial_account_balance+ temp_deposit;
        }
        else
        {
            //read check variables from user
            cout<<i+1<<": What is the ID # of this check?"<<endl;
            cin>>temp_num;
            cout<<i+1<<": How much is this check for?"<<endl;
            //overloaded >> operator for money should work here
            cin>>temp_amount;
            cout<<i+1<<": Has the check been cashed? Give 1 for yes and 0 for no:"<<endl;
            cin>>cashed_true;
            //store cashed vs not cashed in two dif check arr
            if (cashed_true==1)
            {
                cashed[cashed_count]= check(temp_num,temp_amount,cashed_true);
                cashed_total = cashed_total + temp_amount;
                cashed_count++;
                bank_balance = bank_balance - temp_amount;
                checkbook_balance= checkbook_balance - temp_amount;
                

            }
            else
            {
                not_cashed[not_cashed_count]= check(temp_num,temp_amount,cashed_true);
                not_cashed_count++;
                checkbook_balance= checkbook_balance - temp_amount;
            }

            //use constructor with input variables
            all_checks[i]= check(temp_num,temp_amount,cashed_true);
        }
    }

// // The new account balance should be the old balance plus all deposits, minus all checks that have been cashed.
//     //create new money type bank_balance and set it to the value of original balance 
//     //use loop to subtract cashed check amount from bank_balance
//     Money bank_balance = initial_account_balance;
//     for (int i = 0; i < cashed_count; i++)
//     {
//         bank_balance = bank_balance - cashed[i];
//     }
//     Money checkbook_balance= bank_balance;
//     //create new money type checkbook balance and set it to the value of bank_balance
//     //use loop to subtract uncashed check amount from bank balance
//     for (int i = 0; i < not_cashed_count; i++)
//     {
//         checkbook_balance = checkbook_balance - not_cashed[i];
//     }
    
    Money account_difference= bank_balance - checkbook_balance;
    

// The program outputs the total of the checks cashed
    
    cout<<"TOTAL OF CHECKS CASHED: "<<cashed_total<<endl;

//the total of the deposits
    cout<< "TOTAL OF DEPOSITS: "<<deposit_total<<endl;
//what the new balance should be
    cout<<"ACCURATE NEW BALANCE: "<<checkbook_balance<<endl;
//how much this figure differs from what the bank says the new balance is
    cout<<"DIFFERENCE BETWEEN BANK BALANCE AND CHECKBOOK BALANCE: "<<account_difference<<endl;
// It also outputs two lists of checks: 
//the checks cashed since the last time you balanced your checkbook 
    for (int i =0; i<cashed_count; i++)
{
    cout<<cashed[i];
}
//and the checks still not cashed
    for (int i =0; i<not_cashed_count; i++)
{
    cout<<not_cashed[i];
}

return 0;
}

////CONSTRUCTORS
//MONEY
Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0) //If one is negative and one is positive
    {
        cout<<"Illegal values for dollars and cents. \n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}
Money::Money(long dollars) : all_cents(dollars * 100)
{
    //Body intentionally blank
}
Money::Money() : all_cents(0)
{
    //Body intentionally blank
}
//CHECKS
check:: check(int the_check_num, Money the_amount, bool the_check_cashed)
{
    check_num = the_check_num;
    amount = the_amount;
    check_cashed= the_check_cashed;
}
check:: check() : check_num(0), amount(0), check_cashed(0)
{
    //body intentionally left blank
}

////ACCESSORS
//MONEY
// double Money::get_value()
// {
//     return (all_cents * 0.01);
// }
//CHECKS

//MISC
//used to 
int digit_to_int(char c)
{
    return(static_cast<int>(c) - static_cast<int>('0'));
}

////MUTATORS
//MONEY
//CHECKS
//sort?

////OVERLOADED OPERATORS
//MONEY
istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimal_point, digit1, digit2;
    //digits for the amount of cents
    long dollars;
    int cents;
    bool negative; //set to true if input is negative

    ins >> one_char;
    if(one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one char=='$'
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        cout<< "Error illegal form for money input \n";
        exit(1);
    }
    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

    amount.all_cents = dollars * 100 + cents;
    if (negative)
    {
        amount.all_cents = -amount.all_cents;
    }
    return ins;
    
}
Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}
Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

//uses cstd and iostream
ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;
    if (amount.all_cents < 0)
    {
        outs << "-$"<< dollars << '.';
    }
    else 
    {
        outs << "$" << dollars << '.';
    }
    if (cents < 10)
    {
        outs << '0';
    }
    outs << cents;
    return outs;
}

//CHECKS
ostream& operator <<(ostream& outs, const check& the_check)
{
    //Overloads the << operator so it can be used to output values of type
    //prints full int for check num;
    outs<<"Check number "<<the_check.check_num<<":"<<endl;
    //references << operator for money class when printing amount
    cout<<the_check.amount<<"\t";
    //prints cashed is cashed = true
    if (the_check.check_cashed==1)
    {
        outs<<"CASHED"<<endl<<endl;
    }
    else if (the_check.check_cashed==0)
    {
        outs<<"NOT CASHED"<<endl<<endl;
    }
    return outs;
    //prints not cashed if cashed == false
    //precondition if outs is a file output stream then outs has already been connected to a file
}
// check operator -(const Money& account, const check& the_check)
// {
//     //precondition: amount1 and amount 2 have been given values
//     //returns the difference of the values of the account with the cashed check taken out of the balance
// }
// check operator +(const Money& account, const check& the_check)
// {
//     //precondition: amount1 and amount 2 have been given values
//     //returns the difference of the values of the account with the added check
// }




