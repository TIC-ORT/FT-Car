#include <WiFi.h>
#include <esp_now.h>

// ESP-NOW peer address
uint8_t peerAddress[] = {0x24, 0x6F, 0x28, 0xFF, 0xFF, 0xFF}; // Replace with receiver MAC

// Structure to hold control data
typedef struct struct_message {
    int angle;
    int throttle;
} struct_message;

struct_message controlData;

// Sending data
void sendControlData(int angle, int throttle) {
    controlData.angle = angle;
    controlData.throttle = throttle;
    esp_now_send(peerAddress, (uint8_t *) &controlData, sizeof(controlData));
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, peerAddress, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed to add peer");
        return;
    }
    Serial.println("Controller ready");
}

void loop() {
    if (Serial.available() > 0) {
        angle = Serial.parseInt();
        throttle = Serial.parseInt();
        sendControlData(angle, throttle);
        Serial.printf("Sent: Angle=%d, Throttle=%d\n", angle, throttle);
    }
}