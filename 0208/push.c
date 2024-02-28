#include <stdio.h>
#include <wiringPi.h>

#define SW1 3
#define SW2 4
#define SW3 5
#define BUZZER_PIN 1

const int melody[] = {0, 262, 294, 330, 349, 392, 440, 494, 523, 587};

int airplane[] = {3, 2, 1, 2, 3, 3, 3, 2, 2, 2, 3, 3, 3, \
                  3, 2, 1, 2, 3, 3, 3, 2, 2, 3, 2, 1};

int cornhamonica[] = {1, 3, 2, 1, 5, 6, 5, 5, 6, 8, 7, 6, 5, 3, 4, 5, 6, \
                  5, 5, 3, 1, 2, 2, 2, 3, 2, 1, 3, 2, 1, 5, 6, 5, 5, 6, 8, 7, 6, 5, \
                  8, 9, 8, 6, 5, 6, 5, 3, 2, 2, 5, 5, 3, 1, 2, 3, 4, 5, 6, 7, 8, \
                  9, 1, 7, 6, 5, 1, 3, 5, 8, 8, 5, 3, 1, 2, 2, 5, 5, 1};

int foxrain[] = {3,2,3,2,3,5,3,3,2,3,2,3,5,3,3,2,3,4,5,3,2,3,4,5,3,2,3,4,5,7,5};
void playMelody(int length);
void playMelody2(int length);
void playMelody3(int length);
void stop_song();

int main(void){
    if (wiringPiSetup() == -1)
        return 1;
    
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);
    pinMode(BUZZER_PIN, PWM_OUTPUT);
    pwmSetClock(19);
    pwmSetMode(PWM_MODE_MS);

    while (1) {
        // 버튼이 눌리면 노래를 재생
        if (digitalRead(SW2) == LOW) {
            printf("노래 1 재생");
            playMelody(sizeof(airplane) / sizeof(airplane[0]));
            // 버튼이 떼질 때까지 대기
            //while (digitalRead(SW2) == LOW);
        }
         if (digitalRead(SW1) == LOW) {
            printf("노래 1 재생");
            playMelody2(sizeof(cornhamonica) / sizeof(cornhamonica[0]));
            // 버튼이 떼질 때까지 대기
            //while (digitalRead(SW1) == LOW);
         }
         if (digitalRead(SW3) == LOW) {
            printf("노래 1 재생");
            playMelody3(sizeof(foxrain) / sizeof(foxrain[0]));
            // 버튼이 떼질 때까지 대기
            //while (digitalRead(SW3) == LOW);
         }
    }

    return 0;
}
void playMelody(int length) {
    int i;
    for(i=0;i<length;i++) {
        if(digitalRead(SW1) == 0) {
			stop_song();
			playMelody2(sizeof(cornhamonica) / sizeof(cornhamonica[0]));
			break;
		}
		else if(digitalRead(SW3) == 0) {
			stop_song();
			playMelody3(sizeof(foxrain) / sizeof(foxrain[0]));
			break;
		}
        pwmSetRange(1000000/melody[airplane[i]]);   
        pwmWrite(BUZZER_PIN, 1000000/melody[airplane[i]]/20);
        if(i==6 || i==9 || i==12 || i==19 || i==24)delay(1000);
        else delay(500); // 각 음을 0.5초 동안 재생
    }
    pwmWrite(BUZZER_PIN, 0);
}

void playMelody2(int length) {
    int i;
    for(i=0;i<length;i++) {
        if(digitalRead(SW2) == 0) {
			stop_song();
			playMelody(sizeof(airplane) / sizeof(airplane[0]));
			break;
		}
		else if(digitalRead(SW3) == 0) {
			stop_song();
			playMelody3(sizeof(foxrain) / sizeof(foxrain[0]));
			break;
		}
        pwmSetRange(1000000/melody[cornhamonica[i]]);
        pwmWrite(BUZZER_PIN, 1000000/melody[cornhamonica[i]]/20);
        if(i==13 || i==26 || i==39 || i==52 || i==65)delay(1000);
        else delay(500); // 각 음을 0.5초 동안 재생
    }
    pwmWrite(BUZZER_PIN, 0);
}

void playMelody3(int length) {
    int i;
    for(i=0;i<length;i++) {
        if(digitalRead(SW1) == 0) {
			stop_song();
			playMelody2(sizeof(cornhamonica) / sizeof(cornhamonica[0]));
			break;
		}
		else if(digitalRead(SW2) == 0) {
			stop_song();
			playMelody(sizeof(airplane) / sizeof(airplane[0]));
			break;
		}
        pwmSetRange(1000000/melody[foxrain[i]]);
        pwmWrite(BUZZER_PIN, 1000000/melody[foxrain[i]]/20);
        if(i==3 || i==10) delay(400);
		else if(i==6 || i==13 || i==18 || i==23) delay(800);
        else delay(500); // 각 음을 0.5초 동안 재생
    }
    pwmWrite(BUZZER_PIN, 0);
}

void stop_song(){
    pwmWrite(BUZZER_PIN, 0);
}