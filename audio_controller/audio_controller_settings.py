import pyaudio
import serial
import sys
import wave


# Arduino connection settings
arduino = serial.Serial(port='COM6')

# Pyaudio settings
try:
    audio_wav_file  = wave.open('../test_songs/' + sys.argv[1] + '.wav', 'rb')
except IndexError:
    print('Audio file not found. Defaulting to Galantis - No Money.')
    audio_wav_file = wave.open('../test_songs/Galantis - No Money.wav', 'rb')
finally:
    audio_processor = pyaudio.PyAudio()

# Delay count required to change LED colors
MAX_DELAY = 50

# Sound codes
REALLY_SOFT = 4
SOFT        = 6
MEDIUM      = 8
LOUD        = 10
REALLY_LOUD = LOUD

# Color codes
CYAN   = 0
PURPLE = 1
GREEN  = 2
ORANGE = 3
RED    = 4
OFF    = 5