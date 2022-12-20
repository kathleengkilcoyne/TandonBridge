 /*
    Question 1:
Write a program that computes how much a customer has to pay after purchasing two items. The price is calculated according to the following rules:
• Buy one get one half off promotion: the lower price item is half price.
• If the customer is club card member, additional 10% off.
• Tax is added.
Inputs to the program include:
• Two items’ prices
• Have club card or not (User enters ‘Y’ or ‘y’ for “yes”; ‘N’ or ‘n’ for “no”)
• Tax rate (User enters the percentage as a number; for example they enter 8.25 if the tax
rate is 8.25%)
Program displays:
• Base price - the price before the discounts and taxes
• Price after discounts - the price after the buy one get one half off promotion and the
member’s discount, if applicable
• Total price – the amount of money the customer has to pay (after tax).
Your program should interact with the user exactly as it shows in the following example: Enter price of first item: 10
Enter price of second item: 20
Does customer have a club card? (Y/N): y Enter tax rate, e.g. 5.5 for 5.5% tax: 8.25 Base price: 30.0
Price after discounts: 22.5
Total price: 24.35625
*/
#include <iostream>
using namespace std;
int main()
{
   
    
   //I'm going to attempt to write this to enhance performance
   //I understand for these calculations it's not going to make much difference, I just want to do this problem from a certain mindset
   //so I'm going to declare as many variables as I can think of in different phases throughout the program
   //i'm going to declare variables in various phases of the program, variables requiring user input will go first
   //the next stage will be variables that require math or comparisons using the inputted values
   float item_price_1;
   float item_price_2;
   float base_price;
   float tax;
   float tax_rate;
   float total_tax;
   float total_price;
   char card;

   //get user input
   cout<<"Enter price of first item: ";
   cin>>item_price_1;
   cout<<endl<<"Enter price of second item: ";
   cin>>item_price_2;
   cout<<endl<<"Does customer have a club card? (Y/N): ";
   cin>>card;
   cout<<endl<<"Enter tax rate: "<<endl;
   cin>>tax;
   tax_rate = tax /100;
   base_price = item_price_1 + item_price_2;
   //declare bool here after item price has been set but before branching statement
   //bool created to optimize
   bool p1_cheaper = (item_price_1<item_price_2);
   bool p2_cheaper = (item_price_2>item_price_1);
   bool same_price = (item_price_2==item_price_1);
   bool card_yes = (card== 'Y' || card == 'y');
   bool card_no = (card== 'N' || card == 'n');
   bool p1_cheaper_card_yes = (p1_cheaper == 1 && card_yes == 1);
   bool p2_cheaper_card_yes = (p2_cheaper == 1 && card_yes == 1);
   bool same_price_card_yes = (same_price == 1 && card_yes == 1);
   bool p1_cheaper_card_no = (p1_cheaper == 1 && card_no == 1);
   bool p2_cheaper_card_no = (p2_cheaper == 1 && card_no == 1);
   bool same_price_card_no = (same_price == 1 && card_no == 1);
   //declare float for bogo equation
   float half_off_1 = item_price_1 - (item_price_1/2);
   float half_off_2 = item_price_2 - (item_price_2/2);
   float bogo_half1 = (item_price_2 + half_off_1);
   float bogo_half2 = (item_price_1 + half_off_2);
   float card_discount_half1 = (bogo_half1 - (bogo_half1*(0.1)));
   float card_discount_half2 = (bogo_half2 - (bogo_half2*(0.1)));


   //begin branching statement use branching statement to print to user and also calculate price after sales tax
   if ( p1_cheaper_card_yes == 1)
        {   
            total_tax = tax_rate*card_discount_half1;
            total_price = card_discount_half1 + total_tax;

            cout<<"Tax: "<<total_tax<<endl;
            cout<<"Base Price: "<<base_price<<endl;
            cout<<"Price After Discounts: "<<card_discount_half1<<endl;
        }
    //for prices that were the same, treat them as if p2 was cheaper. It doesn't matter which price is given the discount as long as its given    
    else if (p2_cheaper_card_yes == 1 || same_price_card_yes == 1)
        {
            total_tax = tax_rate*card_discount_half2;
            total_price = card_discount_half2 + total_tax;

            cout<<"Tax: $"<<total_tax<<endl;
            cout<<"Base Price: $"<<base_price<<endl;
            cout<<"Price After Discounts: $"<<card_discount_half2<<endl;
        }
    else if (p1_cheaper_card_no == 1)   
        {
            total_tax = tax_rate*bogo_half1;
            total_price = bogo_half1 + total_tax;

            cout<<"Tax: "<<total_tax<<endl;
            cout<<"Base Price: "<<base_price<<endl;
            cout<<"Price After Discounts: "<<bogo_half1<<endl;

        }
    else if (p2_cheaper_card_no == 1 || same_price_card_no == 1)   
        {
            total_tax = tax_rate*bogo_half2;
            total_price = bogo_half2 + total_tax;

            cout<<"Tax: "<<total_tax<<endl;
            cout<<"Base Price: "<<base_price<<endl;
            cout<<"Price After Discounts: "<<bogo_half2<<endl;

        }
    cout<<"Total_Price: "<<total_price<<endl;
   return 0;
}