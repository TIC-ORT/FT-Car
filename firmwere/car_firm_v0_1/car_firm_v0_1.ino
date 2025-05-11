// Raspberry Pi Pico W - Controller and Receiver using ESP-NOW
#include <WiFi.h>
#include <esp_now.h>
#include <Servo.h>

// Servo and Motor Pins (Receiver)
#define SERVO_PIN 22
#define MOTOR_L1 2
#define MOTOR_L2 3
#define MOTOR_R1 4
#define MOTOR_R2 5

// Control values
int angle = 90;      // Default angle for the servo
int throttle = 0;    // Default throttle value

Servo servo;

// Structure to hold control data
typedef struct struct_message {
    int angle;
    int throttle;
} struct_message;

struct_message controlData;

// Callback for receiving data
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
    memcpy(&controlData, incomingData, sizeof(controlData));
    angle = controlData.angle;
    throttle = controlData.throttle;
    servo.write(angle);
    analogWrite(MOTOR_L1, throttle);
    analogWrite(MOTOR_R1, throttle);
    Serial.printf("Received: Angle=%d, Throttle=%d\n", angle, throttle);
}



void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    esp_now_register_recv_cb(OnDataRecv);

    servo.attach(SERVO_PIN);
    pinMode(MOTOR_L1, OUTPUT);
    pinMode(MOTOR_L2, OUTPUT);
    pinMode(MOTOR_R1, OUTPUT);
    pinMode(MOTOR_R2, OUTPUT);
    Serial.println("Receiver ready");
    
}

void loop() {
}