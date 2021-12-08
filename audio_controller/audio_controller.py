"""
    Audio controller -> Run continuously on the computer, determining the pitch
                        of any audio being played and writing a description of it
                        to the Arduino.
"""
import pyaudio
import serial
import wave
import time


# Basic testing function to play the audio from a wav file.
def play_audio_file(filename):
    try:
        audio_wav   = wave.open(filename, 'rb')
        audio_data  = audio_wav.readframes(audio_wav.getnframes())
        audio_audio = pyaudio.PyAudio()
        
        stream_out = audio_audio.open(
            format=audio_audio.get_format_from_width(audio_wav.getsampwidth()),
            channels=audio_wav.getnchannels(),
            rate=audio_wav.getframerate(),
            input=False,
            output=True
        )

        stream_out.start_stream()
        stream_out.write(audio_data)
        stream_out.stop_stream()
        stream_out.close()
        audio_audio.terminate()
    except:
        print("ERROR: AUDIO FILE NOT FOUND.")

# Arduino connection settings
#arduino = serial.Serial(port='COM6')

# Perform processing
if __name__ == '__main__':
    play_audio_file('../test_songs/Galantis - No Money.wav')
    #while True:
    #    testInput = input("Enter Testing String: ")
    #    arduino.write(bytes(testInput, 'utf-8'))