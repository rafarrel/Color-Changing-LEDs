"""
    Class containing the processing logic for the audio controller.
"""
import audioop
import pyaudio
import serial
import sys
import time
import wave
import numpy as np
import audio_controller_settings as settings


class AudioController:
    def __init__(self):
        # Fields Reference 
        self.arduino         = None
        self.audio_processor = pyaudio.PyAudio()
        self.audio_wav_file  = None
        self.delay_count     = settings.MAX_DELAY
        self.last_color      = settings.OFF

        # Setup 
        self.connect_to_arduino()
        self.get_wav_file()

    def connect_to_arduino(self):
        """
            Connect to the Arduino via serial.
        """
        try:
            # Arduino connection settings
            self.arduino = serial.Serial(port='COM6')

            # Delay so Arduino connection can be established.
            print('Connecting to Arduino...')
            time.sleep(2)
            print('Connection established.')
        except:
            print('ERROR: Connection not established.')

    def get_wav_file(self):
        """
            Get the audio file to process and change LED colors to.
        """
        try:
            self.audio_wav_file = wave.open('SONGS_DIRECTORY_HERE' + sys.argv[1] + '.wav', 'rb')
        except (IndexError, FileNotFoundError):
            print('Audio file not found. Defaulting to DEFAULT_SONG_NAME.')
            self.audio_wav_file = wave.open('SONG_PATH_HERE.wav', 'rb')

    def change_LED_color(self, color):
        """
            Tell arduino to change the LED color to the specified color.
        """
        if self.last_color != color:
            self.arduino.write(str(color).encode('utf-8'))
            self.last_color = color

    def process_audio(self, data):
        """
            Process audio for the relative loudness to determine the color that should
            be displayed on the LEDs.
        """
        # Array representation of the audio data
        audio_data = np.frombuffer(data, dtype=np.int16)

        # Root-mean-square of the audio data (power of the audio signal)
        audio_rms = audioop.rms(audio_data, 2) / 1000

        # Change colors based on audio_rms thresholds.
        if audio_rms <= settings.REALLY_SOFT:
            self.change_LED_color(settings.CYAN)
        elif audio_rms <= settings.SOFT:
            self.change_LED_color(settings.PURPLE)
        elif audio_rms <= settings.MEDIUM:
            self.change_LED_color(settings.GREEN)
        elif audio_rms <= settings.LOUD:
            self.change_LED_color(settings.ORANGE)
        elif audio_rms > settings.REALLY_LOUD:
            self.change_LED_color(settings.RED)         

    def callback(self, in_data, frame_count, time_info, status):
        """
            Callback function to allow instant processing of audio. Called continuously 
            during the audio stream.
        """
        if self.delay_count == settings.MAX_DELAY:
            raw_audio_data = self.audio_wav_file.readframes(frame_count)
            self.process_audio(raw_audio_data)
            self.delay_count = 0
        else:
            self.delay_count += 1

        return (raw_audio_data, pyaudio.paContinue)

    def cleanup(self):
        """
            Perform necessary cleanup when finished.
        """
        self.audio_wav_file.close()
        self.audio_processor.terminate()