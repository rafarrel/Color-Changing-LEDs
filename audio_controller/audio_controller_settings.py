import pyaudio
import serial
import wave
import audio_controller_functions as functions
import audio_controller_settings  as settings


# Arduino connection settings
arduino = serial.Serial(port='COM6')

# Pyaudio settings -->
# 1) Audio processing
audio_wav_file  = wave.open('../test_songs/Galantis - No Money.wav', 'rb')
audio_processor = pyaudio.PyAudio()

# 2) Audio playback/output stream
stream_out = settings.audio_processor.open(
             format=settings.audio_processor.get_format_from_width(settings.audio_wav_file.getsampwidth()),
           channels=settings.audio_wav_file.getnchannels(),
               rate=settings.audio_wav_file.getframerate(),
              input=False,
             output=True,
    stream_callback=functions.callback
)