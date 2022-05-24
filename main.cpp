#include<iostream>
#include<ctime>
#include<string>
#include<windows.h>

using namespace std;

class Calender{

private:
    string Months[12] = {"January", "February","March","April","May","June",
                "July","August","September","October","November","December"}; 
    int firstDay;

public:
    
    void calHeader(int year, int month){
        cout <<"Year - " << year << endl
        <<"------------------------"<< Months[month] <<"------------------------"<< endl
        << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;
    }

    void DaysOfMonth(int weekday, int date, int month){
        for (int i = date ; i > 1 ; i--) //for locating the first day of the month
        {
            firstDay = weekday - 2;
            if (firstDay < 0)
            {
                firstDay = 6;
            }    
        }
        int m = firstDay;
        int n;

        int daysInMonth;
        if (month%2 == 0)//for determining no of days in each month like days in Jan: 31, Feb: 28
            daysInMonth = 31;
        else if (month = 1)
            daysInMonth = 28;
        else
            daysInMonth = 30;

        for (int k = 0; k < m; k++)
            {
                cout << "\t";
            }
        n = 1;
        for (int j = 1; j <= 5 ; j++)
        {
            for (int l = 0; l <= 6; l++)
            {
                if (n == date){
                    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //highlight current date 
                    SetConsoleTextAttribute(h,2);
                }
                cout << n << "\t";
                HANDLE g = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(g,7);
                n++;
                if (n > daysInMonth)
                {
                    break;
                }
            }
            cout << endl;   
        }
    }

};

int main()
{   
    time_t now = time(0);
    tm * ltm = localtime(&now);
    Calender * c1 = new Calender;
    c1->calHeader(1900 + ltm->tm_year, ltm->tm_mon);
    c1->DaysOfMonth(ltm->tm_wday, ltm->tm_mday, ltm->tm_mon);

    return 0;
}