#!/bin/bash
# Starts the Arduino IDE using the docker image.
# see also: ...

#    -v /dev/ttyACM0:/dev/ttyACM0 \
#    -v /dev/ttyUSB0:/dev/ttyUSB0 \
docker run -it -p 8085:8085 --network=host --privileged --name arduino tombenke/darduino:latest arduino 
