#!/bin/bash
# Starts the Arduino IDE using the docker image.
# see also: ...

#    -v /dev/ttyACM0:/dev/ttyACM0 \
#    -v /dev/ttyUSB0:/dev/ttyUSB0 \
docker run --privileged -v /dev/bus/usb:/dev/bus/usb SpikeDetection.ino ino upload -m mega2560
