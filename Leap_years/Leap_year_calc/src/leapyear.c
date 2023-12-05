/*
* Created by drew on 2022-10-19.
*/
#include <stdio.h>
#include "../inc/leapyear.h"

int leapYearChecker(int year) {

    int rem_4, rem_100, rem_400;
    rem_4 = year % 4;
    rem_100 = year % 100;
    rem_400 = year % 400;

    if ((rem_4 == 0 && rem_100 != 0) || rem_400 == 0&&year<9999) {
        return 0;
    } else {
        return 1;
    }
}
