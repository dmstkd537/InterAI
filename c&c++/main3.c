#include <stdio.h>

int main(void){

    int income = 0; // 소득액 초기화
    double tax; // 세금
    const double tax_rate = 0.15; // 세율 초기화

    income = 456; // 소득액 저장
    tax = income * tax_rate;
    printf("세금은 : %.1lf입니다.", tax);

    return 0;

}