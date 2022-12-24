# ledshow
## 1. Description
![Demo Gif](https://videoapi-muybridge.vimeocdn.com/animated-thumbnails/image/0732363a-4d78-4cc4-ad03-97fddf72b5ba.gif?ClientID=vimeo-core-prod&Date=1671912150&Signature=a08ed623c397b8eb7cf84847e0591398db7dcd16)
- Demo: Check out [this video](https://vimeo.com/756247601) to see how it works.
## 2. Features
- Serial communication when keypressed, oF --writeByte--> Arduino
- Get X, Y axis data from joystick(thumbslide)
- Get flex sensor angle value
- Switch/case
- Multiple LED control - sequential, dimming
## 3. Specimen
### Hardware
Circuit Design: Check out [servobtn.fzz](https://github.com/chanulee/ledShow/blob/main/led-flex-joystick.fzz).
- Arduino Uno
- 5 leds (with 220 ohm)
- Flex Sensor (with 47k ohm)
- Thumbslide
### Add-ons & Libraries
- Qwiic 6DoF LSM6DSO Library [Hookup Guide](https://learn.sparkfun.com/tutorials/qwiic-6dof-lsm6dso-breakout-hookup-guide)
---
Physical Computing, Fall 2022     
Advisor Prof. Sangwook Lee  
Dept. of Art & Technology, Sogang University

