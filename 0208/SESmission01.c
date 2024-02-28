#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define LED_RED 7
#define LED_GREEN 21
#define LED_BLUE 22

int main() {
    if (wiringPiSetup() == -1) {
        printf("Unable to initialize WiringPi\n");
        return 1;
    }

    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);

    for (int i = 0; i < 10; ++i) {
        printf("Blink %d\n", i + 1);

        digitalWrite(LED_RED, HIGH);
        delay(500);  // 500ms 대기
        digitalWrite(LED_RED, LOW);

        digitalWrite(LED_GREEN, HIGH);
        delay(500);
        digitalWrite(LED_GREEN, LOW);

        digitalWrite(LED_BLUE, HIGH);
        delay(500);
        digitalWrite(LED_BLUE, LOW);

        sleep(1);  // 1초 대기
    }

    return 0;
}
