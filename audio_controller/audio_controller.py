"""
    Audio controller -> Run continuously on the computer, determining the pitch
                        of any audio being played and writing a description of it
                        to the Arduino.
"""
import audio_controller_settings as settings


# Perform processing
if __name__ == '__main__':
    settings.stream_out.start_stream()

    while settings.stream_out.is_active():
        testInput = input("Enter Testing String: ")
        settings.arduino.write(bytes(testInput, 'utf-8'))

    settings.stream_out.stop_stream()
    settings.stream_out.close()
    settings.audio_wav_file.close()
    settings.audio_processor.terminate()