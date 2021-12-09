import pyaudio
import audio_controller_settings as settings


# LED colors should only be changed when the pitch changes 
# significantly. 
pitchChanged = True

def callback(in_data, frame_count, time_info, status):
    """Callback function to allow instant processing of audio."""
    global pitchChanged
    data = settings.audio_wav_file.readframes(frame_count)

    if pitchChanged:
        settings.arduino.write('Medium'.encode('utf-8'))
        pitchChanged = False

    return (data, pyaudio.paContinue)