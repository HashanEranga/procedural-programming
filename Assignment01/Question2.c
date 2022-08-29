#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isLeapYear(int year){
    return (year%4==0)? true : false;
}

int main(int argc, char const *argv[])

{
    printf("█▄░█ █ █▀▀   █▄▄ █ █▀█ ▀█▀ █░█ █▀▄ ▄▀█ █▄█\n");
    printf("█░▀█ █ █▄▄   █▄█ █ █▀▄ ░█░ █▀█ █▄▀ █▀█ ░█░\n");

    char number[15];
    int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int monthsLeap[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    char * namesOfMonths[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Enter NIC number : ");
    scanf("%s", number);
    printf("%s\n", number);

    printf("%lu\n", strlen(number));

    char * eptr;
    if(strlen(number)==12){
        long long num2longlong = strtoll(number, &eptr, 10);
        int year = num2longlong/100000000;
        int days = (num2longlong/100000)%1000;
        if(days>500) days = days - 500;
        
        printf("Year : %d\n", year);
        printf("Days : %d\n", days); 

        bool isLeap = isLeapYear(year);
        if(isLeap){
            int month = 0;
            while(days > monthsLeap[month]){
                days-=months[month];
                month++;
            }
            printf("Months : %s\n", namesOfMonths[month]);
            printf("Days : %d\n", days);
        }else{
            int month = 0;
            while(days > months[month]){
                days-=months[month];
                month++;

            }
            printf("Months : %s\n", namesOfMonths[month]);
            printf("Days : %d\n", days);
        }
    }
    if(strlen(number)==10){
        long long num2longlong = strtoll(number, &eptr, 10);
        int year = num2longlong/10000000;
        int days = (num2longlong/10000)%1000;

        printf("%d\n", year);
        printf("%d\n", days);

        bool isLeap = isLeapYear(year);
        if(isLeap) printf("Leap Year\n");

        if(isLeap){
            int month = 0;
            while(days > monthsLeap[month]){
                days-=months[month];
                month++;
            }
            printf("Months : %s\n", namesOfMonths[month]);
            printf("Days : %d\n", days);
        }else{
            int month = 0;
            while(days > months[month]){
                days-=months[month];
                month++;

            }
            printf("Months : %s\n", namesOfMonths[month]);
            printf("Days : %d\n", days);
        }
    }

    return 0;
}
