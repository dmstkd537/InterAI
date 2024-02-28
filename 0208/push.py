import RPi.GPIO as GPIO
import time

SW1 = 22
SW2 = 23
SW3 = 24
BUZZER_PIN = 18  # 부저에 연결된 GPIO 핀 번호
GPIO.setmode(GPIO.BCM)
GPIO.setup(BUZZER_PIN, GPIO.OUT)
GPIO.setup(SW1, GPIO.IN)
GPIO.setup(SW2, GPIO.IN)
GPIO.setup(SW3, GPIO.IN)

pwm = GPIO.PWM(BUZZER_PIN, 1000)  # PWM 주파수 설정 (1kHz)

melody = [0, 262, 294, 330, 349, 392, 440, 494, 523, 587]

airplane_note = [3, 2, 1, 2, 3, 3, 3, 2, 2, 2, 3, 3, 3, \
            3, 2, 1, 2, 3, 3, 3, 2, 2, 3, 2, 1]

cornhamonica_note = [1, 3, 2, 1, 5, 6, 5, 5, 6, 8, 7, 6, 5, 3, 4, 5, 6, \
                5, 5, 3, 1, 2, 2, 2, 3, 2, 1, 3, 2, 1, 5, 6, 5, 5, 6, 8, 7, 6, 5, \
                8, 9, 8, 6, 5, 6, 5, 3, 2, 2, 5, 5, 3, 1, 2, 3, 4, 5, 6, 7, 8, \
                9, 1, 7, 6, 5, 1, 3, 5, 8, 8, 5, 3, 1, 2, 2, 5, 5, 1]

foxrain_note = [3, 2, 3, 2, 3, 5, 3, 3, 2, 3, 2, 3, 5, 3, 3, 2, 3, 4, 5, 3, 2, 3, 4, 5, 3, 2, 3, 4, 5, 7, 5]


def airplane(melody_notes):
    pwm.start(10)  # 듀티 사이클을 50%로 설정하여 소리 재생
    for note in melody_notes:
        if GPIO.input(SW1) == GPIO.LOW:
            return 
        if GPIO.input(SW3) == GPIO.LOW:
            return# 다른 버튼이 눌렸을 경우 노래 중지
        frequency = melody[note]
        pwm.ChangeFrequency(frequency)
        if note in [6, 9, 12, 19, 24]:
            time.sleep(1.0)
        else:
            time.sleep(0.5)
    pwm.stop()

def cornhamonica(melody_notes):
    pwm.start(10)  # 듀티 사이클을 50%로 설정하여 소리 재생

    for note in melody_notes:
        if GPIO.input(SW2) == GPIO.LOW:
            return 
        if GPIO.input(SW3) == GPIO.LOW:
            return
        frequency = melody[note]
        pwm.ChangeFrequency(frequency)
        if note in [13, 26, 39, 52, 65]:
            time.sleep(1.0)
        else:
            time.sleep(0.5)
    pwm.stop()

def foxrain(melody_notes):
    pwm.start(10)  # 듀티 사이클을 50%로 설정하여 소리 재생
    for note in melody_notes:
        if GPIO.input(SW1) == GPIO.LOW:
            return 
        if GPIO.input(SW2) == GPIO.LOW:
            return
        frequency = melody[note]
        pwm.ChangeFrequency(frequency)
        if note in [6, 13, 18, 23]:
            time.sleep(1.0)
        else:
            time.sleep(0.5)
    pwm.stop()


def main():
    while True:
        if GPIO.input(SW2) == GPIO.LOW:
            print("노래 1 재생")
            airplane(airplane_note)
            time.sleep(0.1)  # 디바운스
        if GPIO.input(SW1) == GPIO.LOW:
            print("노래 2 재생")
            cornhamonica(cornhamonica_note)
            time.sleep(0.1)  # 디바운스
        if GPIO.input(SW3) == GPIO.LOW:
            print("노래 3 재생")
            foxrain(foxrain_note)
            time.sleep(0.1)  # 디바운스



if __name__ == "__main__":
    main()
