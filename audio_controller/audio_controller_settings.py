"""
    Settings for the audio controller.
"""

# LED colors should only be changed when the pitch changes 
# significantly. There needs to be a mini delay between calls
# to process the audio to give the arduino time to light the LEDs. 
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