import RPi.GPIO as GPIO
import time

# GPIO 핀 설정
led_red = 4
led_green = 5
led_blue = 6

# GPIO 핀 모드 설정
GPIO.setmode(GPIO.BCM)
GPIO.setup(led_red, GPIO.OUT)
GPIO.setup(led_green, GPIO.OUT)
GPIO.setup(led_blue, GPIO.OUT)

# LED를 10번 깜빡이는 함수
def blink_led(led_pin):
    for _ in range(10):
        GPIO.output(led_pin, GPIO.HIGH)  # LED 켜기
        time.sleep(0.5)
        GPIO.output(led_pin, GPIO.LOW)  # LED 끄기
        time.sleep(0.5)

try:
    # 빨간, 초록, 파란 LED 동시에 깜빡이기
    for led_pin in [led_red, led_green, led_blue]:
        blink_led(led_pin)

except KeyboardInterrupt:
    pass

finally:
    # GPIO 설정 초기화
    GPIO.cleanup()
