FROM ubuntu:16.04

ADD *.ino \

# Replace 1000 with your user / group id
RUN export uid=* gid=* && \
    mkdir -p /home/developer && \
    mkdir -p /etc/sudoers.d && \
    echo "developer:x:${uid}:${gid}:Developer,,,:/home/developer:/bin/bash" >> /etc/passwd && \
    echo "developer:x:${uid}:" >> /etc/group && \
    echo "developer ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/developer && \
    java -jar -Djava.awt.headless=true *.jar \
    chmod 0440 /etc/sudoers.d/developer && \
    chown ${uid}:${gid} -R /home/developer && \
    apt-get update \
	&& apt-get install -y \
        software-properties-common \
		wget \
		openjdk-9-jre \
		xvfb \
        xz-utils \
	sudo \
    && add-apt-repository ppa:ubuntuhandbook1/apps \
    && apt-get update \
    && apt-get install -y avrdude avrdude-doc \
	&& apt-get clean \
	&& rm -rf /var/lib/apt/lists/*

# Add developer user to the dialout group to be ale to write the serial USB device
RUN sed "s/^dialout.*/&developer/" /etc/group -i \
    && sed "s/^root.*/&developer/" /etc/group -i

ENV ARDUINO_IDE_VERSION 1.8.5
RUN (wget -q -O- https://downloads.arduino.cc/arduino-${ARDUINO_IDE_VERSION}-linux64.tar.xz \
	| tar xJC /usr/local/share \
	&& ln -s /usr/local/share/arduino-${ARDUINO_IDE_VERSION} /usr/local/share/arduino \
	&& ln -s /usr/local/share/arduino-${ARDUINO_IDE_VERSION}/arduino /usr/local/bin/arduino)



USER developer
