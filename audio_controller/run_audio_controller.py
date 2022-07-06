"""
    Audio controller -> Run continuously on the computer, determining the pitch
                        of any audio being played and writing a description of it
                        to the Arduino.
"""
from audio_controller import AudioController


if __name__ == '__main__':
    controller = AudioController()

    # Audio playback/output stream
    stream_out = controller.audio_processor.open(
                 format=controller.audio_processor.get_format_from_width(controller.audio_wav_file.getsampwidth()),
               channels=controller.audio_wav_file.getnchannels(),
                   rate=controller.audio_wav_file.getframerate(),
                  input=False,
                 output=True,
        stream_callback=controller.callback
    )
    
    # Start stream
    stream_out.start_stream()

    ## Runs audio processing in the callback function ##
    while stream_out.is_active():
        pass

    # Cleanup
    stream_out.stop_stream()
    stream_out.close()
    controller.cleanup()