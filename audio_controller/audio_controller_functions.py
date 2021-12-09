import audioop
import pyaudio
import numpy as np
import audio_controller_settings as settings


# LED colors should only be changed when the pitch changes 
# significantly. There needs to be a mini delay between calls
# to process the audio to give the arduino time to light the LEDs. 
delay_count = 0
last_color  = settings.OFF

def change_LED_color(color):
    """Tell arduino to change the LED color to the specified color."""
    global last_color
    if last_color != color:
        settings.arduino.write(str(color).encode('utf-8'))
        last_color = color

def process_audio(data):
    """Process audio for the relative loudness to determine the color that should
    be displayed on the LEDs."""
    # Array representation of the audio data
    audio_data = np.frombuffer(data, dtype=np.int16)

    # Root-mean-square of the audio data (power of the audio signal)
    audio_rms  = audioop.rms(audio_data, 2) 
    print(audio_rms)

    # TESTING
    if audio_rms >= 6000:
        change_LED_color(settings.ORANGE)
    else:
        change_LED_color(settings.RED)

def callback(in_data, frame_count, time_info, status):
    """Callback function to allow instant processing of audio. Called continuously 
    during the audio stream."""
    global delay_count

    # Raw audio data
    data = settings.audio_wav_file.readframes(frame_count)

    if delay_count == 50:
        process_audio(data)
        delay_count = 0
    else:
        delay_count += 1

    return (data, pyaudio.paContinue)