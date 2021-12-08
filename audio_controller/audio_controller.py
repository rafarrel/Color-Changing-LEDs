"""
    Audio controller -> Run continuously on the computer, determining the pitch
                        of any audio being played and writing a description of it
                        to the Arduino.
"""
import serial


# Arduino connection settings
arduino = serial.Serial(port='COM6')

# Perform processing
if __name__ == '__main__':
    while True:
        testInput = input("Enter Testing String: ")
        arduino.write(bytes(testInput, 'utf-8'))