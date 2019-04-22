# Plant Monitoring System

Simple Plant Monitoring System based on a Wemos D1 mini microcontroller. The system measures Temperature, Humidity, Moisture and Light and sends it to a Blync app.

# List of components

- WeMos D1 mini board
- Light sensor: https://www.amazon.com/Gowoops-Digital-Intensity-Detection-Photosensitive/dp/B01N1FKS4L/ref=sr_1_1_sspa?keywords=light+sensor+arduino&qid=1555928778&s=gateway&sr=8-1-spons&psc=1
- Moisture sensor: https://www.amazon.com/HUABAN-Hygrometer-Humidity-Detection-Moisture/dp/B077PW1VW5/ref=sr_1_1_sspa?keywords=moisture+sensor+arduino&qid=1555928812&s=gateway&sr=8-1-spons&psc=1
- Temperature and Humidity sensor: https://www.amazon.com/HiLetgo-Temperature-Humidity-Arduino-Raspberry/dp/B01DKC2GQ0/ref=sr_1_3?keywords=Temperature+and+Humidity+sensor+arduino&qid=1555928841&s=gateway&sr=8-3
- 2 10k resistors, 2 diodes
- 1 Wemos prototipe board: https://www.amazon.com/WeMos-Prototype-Shield-Double-Arduino/dp/B07QMQPNB6/ref=sr_1_1?keywords=wemos+prototipe+board&qid=1555928921&s=gateway&sr=8-1-spell
- Screws & Nuts

# 3D printed files

The shells holding the sensors and microcontroller can be found here: https://www.thingiverse.com/thing:3580574

# Circuitry

The temperature and humidity sensor is connected to a digital pin (A 10K Ohm pull-up resistor is needed between the signal line and 5V line to make sure the signal level stays high by default). More info about how to connect this sensor: http://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/

As the Wemos D1 mini has only one analog pin, a simple multiplexer connects the Light and Moisutre sensor to the analog pin. here you can find how this is done: https://www.instructables.com/id/Multiple-Analog-Inputs-on-Only-One-Analoge-Pin/

# App

Blynk was used to create the app. There is a screenshoot of the user interface. 

