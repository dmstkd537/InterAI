#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MOTOR_PINS_NUM 4
#define BUTTON_PINS_NUM 3
#define sw1 3
#define sw2 4
#define sw3 5
#define sw4 6
#define step_outa 27
#define step_outb 0
#define step_out2a 1
#define step_out2b 24

void step_degree45();
void step_degree90();
void step_degree180();
void system_down();

int main(){
    wiringPiSetup();

    pinMode(sw1, INPUT);
    pinMode(sw2, INPUT);
    pinMode(sw3, INPUT);
    pinMode(sw4, INPUT);

    pinMode(step_outa, OUTPUT);
    pinMode(step_outb, OUTPUT);
    pinMode(step_out2a, OUTPUT);
    pinMode(step_out2b, OUTPUT);

    digitalWrite(step_outa, 0);
    digitalWrite(step_outb, 0);
    digitalWrite(step_out2a, 0);
    digitalWrite(step_out2b, 0);

    printf("Step Motor Control Start !! \n");

    while(1){
        if(digitalRead(sw1) == 0) step_degree45();
        else if(digitalRead(sw2) == 0) step_degree90();
        else if(digitalRead(sw3) == 0) step_degree180();
    }
    return 0;
}

void step_degree45(){
    for (int i = 0; i < 60; i++)
    {
        digitalWrite(step_outa, 1);
        usleep(2000);
        digitalWrite(step_outa, 0);
        digitalWrite(step_outb, 1);
        usleep(2000);
        digitalWrite(step_outb, 1);
        usleep(2000);
        digitalWrite(step_outb, 0);
        digitalWrite(step_out2a, 1);
        usleep(2000);
        digitalWrite(step_out2a, 1);
        usleep(2000);
        digitalWrite(step_out2a, 0);
        digitalWrite(step_out2b, 1);
        usleep(2000);
        digitalWrite(step_out2b, 0);
    }   
}

void step_degree90(){
    for (int i = 0; i < 120; i++)
    {
        digitalWrite(step_outa, 1);
        usleep(2000);
        digitalWrite(step_outa, 0);
        digitalWrite(step_outb, 1);
        usleep(2000);
        digitalWrite(step_outb, 1);
        usleep(2000);
        digitalWrite(step_outb, 0);
        digitalWrite(step_out2a, 1);
        usleep(2000);
        digitalWrite(step_out2a, 1);
        usleep(2000);
        digitalWrite(step_out2a, 0);
        digitalWrite(step_out2b, 1);
        usleep(2000);
        digitalWrite(step_out2b, 0);
    }   
}

void step_degree180(){
    for (int i = 0; i < 240; i++)
    {
        digitalWrite(step_outa, 1);
        usleep(2000);
        digitalWrite(step_outa, 0);
        digitalWrite(step_outb, 1);
        usleep(2000);
        digitalWrite(step_outb, 1);
        usleep(2000);
        digitalWrite(step_outb, 0);
        digitalWrite(step_out2a, 1);
        usleep(2000);
        digitalWrite(step_out2a, 1);
        usleep(2000);
        digitalWrite(step_out2a, 0);
        digitalWrite(step_out2b, 1);
        usleep(2000);
        digitalWrite(step_out2b, 0);
    }
}