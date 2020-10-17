#!/bin/bash
# Starts the Arduino IDE using the docker image.
# see also: ...

#    -v /dev/ttyACM0:/dev/ttyACM0 \
#    -v /dev/ttyUSB0:/dev/ttyUSB0 \
docker run \
    --network=host \
    --privileged \
    -v /dev:/dev \
    -v $HOME/topics:/topics \
    -v $HOME/topics/arduino:/home/developer/Arduino \
    --name arduino \
    tombenke/darduino:latest \
    arduino \
