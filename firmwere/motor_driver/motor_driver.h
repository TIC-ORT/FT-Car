#ifndef motor_driver_h
#define motor_driver_h

#include <Arduino.h>

class Motor {
    public:
        Motor(int enPin, int in1Pin, int in2Pin);
        void setSpeed(int speed);
        int getData();
        int speed;
    private:
        int _enPin;
        int _in1Pin;
        int _in2Pin;
}

class controledMotor {
    public:
        controledMotor(int enPin, int in1Pin, int in2Pin, int autotrack = false);
        void setupMotor();
        void controlMotor(int speed);
        void stopMotor();
        void setSpeed(int speed);
        int getData();
    private:
        int _enPin;
        int _in1Pin;
        int _in2Pin;
        int _speed;
}

#endif