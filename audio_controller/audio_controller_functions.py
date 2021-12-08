import pyaudio
import audio_controller_settings as settings


def callback(in_data, frame_count, time_info, status):
    """Callback function to allow instant processing of audio."""
    data = settings.audio_wav_file.readframes(frame_count)
    return (data, pyaudio.paContinue)