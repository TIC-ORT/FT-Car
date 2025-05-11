#include <Servo.h>

// Pin definitions
const int servoPin = 22;
const int throttle1Pin1 = 5; // H-bridge driver 1 direction pin
const int throttle1Pin2 = 6; // H-bridge driver 1 direction pin
const int throttle1EN = 3;   // H-bridge driver 1 enable pin
const int throttle2Pin1 = 9; // H-bridge driver 2 direction pin
const int throttle2Pin2 = 10; // H-bridge driver 2 direction pin
const int throttle2EN = 11;  // H-bridge driver 2 enable pin

// Servo object
Servo myServo;

void setup() {
    Serial.begin(115200);
    Serial.println("Car Wired Test");
    // Initialize servo
    myServo.attach(servoPin);

    // Initialize H-bridge pins
    pinMode(throttle1Pin1, OUTPUT);
    pinMode(throttle1Pin2, OUTPUT);
    pinMode(throttle1EN, OUTPUT);
    pinMode(throttle2Pin1, OUTPUT);
    pinMode(throttle2Pin2, OUTPUT);
    pinMode(throttle2EN, OUTPUT);

    // Set initial states
    myServo.write(90); // Neutral position
    stopThrottle1();
    stopThrottle2();
}

void loop() {
    if (Serial.available() > 0) {
        // Read the incoming angle and throttle values from Serial
        int angle = Serial.parseInt();
        int throttle = Serial.parseInt();
        Seral.printf("Received: Angle=%d, Throttle=%d\n", angle, throttle);

        // Set servo angle
        myServo.write(angle);

        // Control throttle 1
        setThrottle(throttle1Pin1, throttle1Pin2, throttle1EN, throttle);

        // Control throttle 2 (optional)
        setThrottle(throttle2Pin1, throttle2Pin2, throttle2EN, throttle);
    }
    delay(10); // Small delay to avoid flooding the serial output
}

void setThrottle(int pin1, int pin2, int enPin, int value) {
    if (value > 0) {
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        analogWrite(enPin, value);
    } else if (value < 0) {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        analogWrite(enPin, -value);
    } else {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        analogWrite(enPin, 0);
    }
}

void stopThrottle1() {
    digitalWrite(throttle1Pin1, LOW);
    digitalWrite(throttle1Pin2, LOW);
    analogWrite(throttle1EN, 0);
}

void stopThrottle2() {
    digitalWrite(throttle2Pin1, LOW);
    digitalWrite(throttle2Pin2, LOW);
    analogWrite(throttle2EN, 0);
}