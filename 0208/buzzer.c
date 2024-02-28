#include <stdio.h>
#include <wiringPi.h>
#include <softTone.h>
#include <unistd.h>

#define BUZZER_PIN 1

// 부저 연주에 사용할 음계 배열 설정
float scale[] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88, 523.25};
int melody[] = {0, 0, 4, 4, 5, 5, 4, 3, 3, 2, 2, 1, 1, 0}; // 메리 헬리스 주제곡

int main(void) {
    // WiringPi 초기화
    wiringPiSetup();

    // 부저 핀 설정
    pinMode(BUZZER_PIN, PWM_OUTPUT);

    // PWM 모드와 클럭 설정
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(19);

    printf("==== 동요 : 메리 헬리스 ====\n");  // 동요 제목

    // 노래 연주
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        // 음계 인덱스 확인 후 주파수 변경
        int index = melody[i];
	pwmSetRange(1000000/scale[index]);
	pwmWrite(BUZZER_PIN, 1000000/scale[index]/10);
	delay(1000);
    }

    // 부저 끄기
    pwmWrite(BUZZER_PIN, 0);

    return 0;
}
