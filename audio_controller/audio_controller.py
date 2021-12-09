"""
    Audio controller -> Run continuously on the computer, determining the pitch
                        of any audio being played and writing a description of it
                        to the Arduino.
"""
import time
import audio_controller_functions as functions
import audio_controller_settings  as settings


# Perform processing
if __name__ == '__main__':
    # Delay so Arduino connection can be established.
    print('Connecting to Arduino...')
    time.sleep(2)
    print('Connection established.')

    # Audio playback/output stream
    stream_out = settings.audio_processor.open(
                 format=settings.audio_processor.get_format_from_width(settings.audio_wav_file.getsampwidth()),
               channels=settings.audio_wav_file.getnchannels(),
                   rate=settings.audio_wav_file.getframerate(),
                  input=False,
                 output=True,
        stream_callback=functions.callback
    )

    # Start stream
    stream_out.start_stream()

    ## Runs audio processing in the callback function ##
    while stream_out.is_active():
        pass

    # Cleanup
    stream_out.stop_stream()
    stream_out.close()
    settings.audio_wav_file.close()
    settings.audio_processor.terminate()