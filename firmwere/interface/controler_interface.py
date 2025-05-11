import pygame
import serial
import time

# Initialize Pygame for controller input
pygame.init()
pygame.joystick.init()

# Initialize serial communication
arduino_port = 'COM7'  # Replace with your Arduino's serial port
baud_rate = 115200  # Common baud rate for Arduino
ser = serial.Serial(arduino_port, baud_rate, timeout=1)
time.sleep(2)  # Allow time for the connection to establish

def main():
    try:
        joystick = pygame.joystick.Joystick(0)
        joystick.init()
        print(f"Controller connected: {joystick.get_name()}")
    except pygame.error:
        print("No controller found.")
        return

    try:
        while True:
            pygame.event.pump()

            # Read axis values (e.g., axis 0 and axis 1)
            axis_x = joystick.get_axis(0)  # Left stick horizontal
            axis_y = joystick.get_axis(1)  # Left stick vertical

            # Scale values to a range Arduino can handle (e.g., 0-255)
            x_value = int((axis_x + 1) * 127.5)
            y_value = int((axis_y + 1) * 127.5)

            # Send values over serial
            data = f"{x_value},{y_value}\n"
            ser.write(data.encode('utf-8'))

            print(f"Sent: {data.strip()}")
            time.sleep(0.1)  # Adjust delay as needed

    except KeyboardInterrupt:
        print("Exiting program.")
    finally:
        ser.close()
        pygame.quit()

if __name__ == "__main__":
    main()