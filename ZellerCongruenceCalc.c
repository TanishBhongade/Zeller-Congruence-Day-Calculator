#include<stdio.h>

void getDayWithZeller(int ,int ,int);
void printDay(int);

int main(){
    int date, month, year;
    printf("Enter the date(XX XX XXXX): ");
    scanf("%i%i%i",&date,&month,&year);
    
    getDayWithZeller(date, month, year);
    
    return 0;
}

void getDayWithZeller(int d, int m, int y){
    int actD, actM, actC, actY;
    int day, isoDay;
    
    if(m == 1){
        m = 13;
        y--;
    }
    if(m == 2){
        m = 14;
        y--;
    }
    
    actD = d;
    actM = m;
    actC = y / 100;
    actY = y % 100;
    
    day = (actD + ((13 * (actM + 1)) / 5) + actY + (actY / 4) + (actC / 4) + (5 * actC));
    day %=7;
    
    isoDay = ((day + 5) % 7) + 1;
    printDay(isoDay);
}

void printDay(int isoDay){
    switch(isoDay){
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        case 7:
            printf("Sunday");
            break;
    }
}