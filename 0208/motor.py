import RPi.GPIO as GPIO
import time
import threading

GPIO.setmode(GPIO.BCM)

motor_pin = [16, 17, 18, 19]
button_pin = [22, 23, 24]
step_delay = 0.01  # Adjust this value to control the speed

GPIO.setwarnings(False)


for i in motor_pin:
    GPIO.setup(i, GPIO.OUT)
    GPIO.output(i, GPIO.LOW)

for i in button_pin:
    GPIO.setup(i, GPIO.IN)

print("Step Motor Control Start !! \n")

steps_45_deg = 45
steps_90_deg = 90
steps_180_deg = 180

def rotate_motor(deg):
    for j in range(deg):  # Rotate specified degrees
        for k in motor_pin:
            GPIO.output(k, GPIO.HIGH)
            time.sleep(step_delay)
            GPIO.output(k, GPIO.LOW)
        time.sleep(step_delay)
    time.sleep(1)  # Pause for stability

def button_callback(channel):
    if channel == button_pin[0]:
        rotate_motor(steps_45_deg)
    elif channel == button_pin[1]:
        rotate_motor(steps_90_deg)
    elif channel == button_pin[2]:
        rotate_motor(steps_180_deg)

for button in button_pin:
    GPIO.add_event_detect(button, GPIO.FALLING, callback=button_callback, bouncetime=200)

try:
    while True:
        time.sleep(0.1)  # Keep main thread alive
except KeyboardInterrupt:
    GPIO.cleanup()