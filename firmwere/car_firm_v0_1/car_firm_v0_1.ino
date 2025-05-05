// Arduino program to control two motors using a single H-bridge
// Speed and direction are controlled by a single function

// Define H-bridge pins
const int EN_PIN = 9;  // PWM pin to control speed
const int IN1_PIN = 7; // Direction pin 1
const int IN2_PIN = 8; // Direction pin 2

void setup() {
    // Set H-bridge pins as outputs
    pinMode(EN_PIN, OUTPUT);
    pinMode(IN1_PIN, OUTPUT);
    pinMode(IN2_PIN, OUTPUT);

    // Initialize pins to LOW
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, LOW);
    analogWrite(EN_PIN, 0);
}

// Function to control motor speed and direction
// speed: positive for forward, negative for reverse, 0 to stop
void controlMotor(int speed) {
    if (speed > 0) {
        // Forward direction
        digitalWrite(IN1_PIN, HIGH);
        digitalWrite(IN2_PIN, LOW);
        analogWrite(EN_PIN, speed);
    } else if (speed < 0) {
        // Reverse direction
        digitalWrite(IN1_PIN, LOW);
        digitalWrite(IN2_PIN, HIGH);
        analogWrite(EN_PIN, -speed); // Use absolute value of speed
    } else {
        // Stop motor
        digitalWrite(IN1_PIN, LOW);
        digitalWrite(IN2_PIN, LOW);
        analogWrite(EN_PIN, 0);
    }
}

void loop() {
    // Example usage of controlMotor function
    controlMotor(150); // Move forward at speed 150
    delay(2000);       // Wait for 2 seconds

    controlMotor(-150); // Move backward at speed 150
    delay(2000);        // Wait for 2 seconds

    controlMotor(0);    // Stop motor
    delay(2000);        // Wait for 2 seconds
}