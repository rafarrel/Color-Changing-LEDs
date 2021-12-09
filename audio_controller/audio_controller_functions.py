import pyaudio
import audio_controller_settings as settings


# LED colors should only be changed when the pitch changes 
# significantly. 
last_color = settings.OFF

def change_LED_color(color):
    """Tell arduino to change the LED color to the specified color."""
    global last_color
    if last_color != color:
        settings.arduino.write(str(color).encode('utf-8'))
        last_color = color

def process_audio(data):
    """Process audio for the relative loudness to determine the color that should
    be displayed on the LEDs."""
    change_LED_color(settings.ORANGE)

def callback(in_data, frame_count, time_info, status):
    """Callback function to allow instant processing of audio."""
    data = settings.audio_wav_file.readframes(frame_count)
    process_audio(data)

    return (data, pyaudio.paContinue)