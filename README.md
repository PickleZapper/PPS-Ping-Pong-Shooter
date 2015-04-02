# Ping-Pong-Shooter-PPS
RobotC Code to operate a VEX ping pong ball shooter


Project Title: Catapulter
Team Members: Vickie Chew, Richard Tang, Victor Tang, Anderson Ye
Date: 25 March 2015

Task Description: Improve an existing design, then build and test a device that
will launch a projectile varying distances with precision and accuracy.


Pseudocode:
motors - elevation motor, firing motor
sensors - elevation bumper, firing bumper

while true
if elevation bumper up
start elevation motor 127
if elevation bumper down
start elevation motor -127

stop elevation motor

if firing bumper
fire thing
reset thing
