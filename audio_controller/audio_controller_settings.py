import pyaudio
import serial
import wave


# Arduino connection settings
arduino = serial.Serial(port='COM6')

# Pyaudio settings
audio_wav_file  = wave.open('../test_songs/Galantis - No Money.wav', 'rb')
audio_processor = pyaudio.PyAudio()