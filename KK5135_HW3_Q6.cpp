// Write a program that computes the cost of a long-distance call. The cost of the call is determined according to the following rate schedule:
// • Any call started between 8:00 A.M. and 6:00 P.M., Monday through Friday, is billed at a
// rate of $0.40 per minute. 
// • Any call starting before 8:00 A.M. or after 6:00 P.M., Monday through Friday, is charged
// at a rate of $0.25 per minute. 
// • Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute. 
// The input will consist of the day of the week, the time the call started, and the length of the call in minutes.
// The output will be the cost of the call.
// Notes:
// 1. The time is to be input in 24-hour notation, so the time 1:30 P.M. is input as 13:30 
// 2. The day of the week will be read as one of the following two character string: Mo Tu
// We Th Fr Sa Su
// 3. The number of minutes will be input as a positive integer.
#include <iostream>
using namespace std;
int main()
{
    string time;
    string day;
    string day_2char;
    //defined so time canbe "split" by hours and minutes
    char colon= ':';
    //bool created for switch statement
    bool weekend;
    bool offhour;
    int hours;
    int minutes_time;
    int minutes_call;
    double cost;

    const double WEEKEND_RATE = 0.15;
    const double WEEKDAY_DURING_RATE = 0.4;
    const double WEEKDAY_OFF_RATE = 0.25;

    cout<<"Please enter the time the call began in 24 hr format (i.e 00:00): "<<endl;
    cin>>hours>>colon>>minutes_time;
    cout<<"Please enter the day of the week the call began: "<<endl;
    cin>>day;
    cout<<"Please enter in minutes the duration of the call: "<<endl;
    cin>>minutes_call;

    //experimenting with strings. I just knew i was gonna type stuff out wrong during testing so i nipped this problem in the bud by getting the first two letters of whatever i typed
    day_2char = day.substr(0,2);
    //again im bad a typing sometimes so i wanted to included all upper/lower cases for the string. didn't want to spend too much time investigating how to use strings tho
    weekend = (day_2char == "Sa" || day_2char == "SA" || day_2char == "sa" || day_2char == "Su" || day_2char == "SU" || day_2char == "su");
    offhour = (hours == 18 && minutes_time > 0) || hours > 18 || hours < 8;
    switch(weekend)
    {
        case 1:
            cost = minutes_call * WEEKEND_RATE;
            cout<<"Cost: $"<<cost<<endl;
            break;
        //i like putting the last case as default in case anything wants to break
        default:
            switch(offhour)
            {
                case 1:
                    cost = minutes_call * WEEKDAY_OFF_RATE;
                    cout<<"Cost: $"<<cost<<endl;
                    break;
                default:
                    cost = minutes_call * WEEKDAY_DURING_RATE;
                    cout<<"Cost: $"<<cost<<endl;
            }
            
    }
    return 0;
}