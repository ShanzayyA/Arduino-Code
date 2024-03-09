# Arduino Ultrasonic Distance-Based Animation Display

## Introduction
This repository contains the code for an Arduino-powered system that uses an ultrasonic sensor to measure distance and display corresponding animations on an LCD. The system creates an engaging visual interaction as objects move within specific proximity ranges.

## Features
- **Proximity Detection(DistanceSensor)**: Employs an ultrasonic sensor for accurate distance measurements.
- **Animated Characters**: Features custom-designed LCD characters including ghosts, Pac-Man, a house, a person, and clouds.
- **Distance-Responsive Animations**: Animations change based on the distance measured by the sensor, offering real-time visual feedback.
- **Customizable Animation Logic**: Users can adjust the logic to display different animations for various distance thresholds.


## Components
- Arduino board 
- Ultrasonic distance sensor (HC-SR04 or similar)
- LCD display (16x2 character LCD recommended)
- Jumper wires
- Breadboard 


## Setup and Configuration
1. Connect the ultrasonic sensor to the Arduino with the trigger pin on pin 2 and the echo pin on pin 3.
2. Connect the LCD to the Arduino using digital pins 7 through 12.
3. Upload the provided Arduino sketch to your Arduino board using the Arduino IDE.

## Custom Character Creation
The sketch includes byte arrays that define custom characters for the LCD. These are generated using the `createChar()` function and can be displayed with the `write()` function.

## Distance Measurement and Animation Display
The loop function continuously measures the distance in front of the sensor. Depending on the measured distance, it displays a sequence of animations on the LCD, creating a narrative or sequence.

## Code Snippet
Here's a snippet from the `loop()` function demonstrating how the distance measurement controls the LCD animations:

```arduino
if (targetDistance <= 2.50) {
  // Sequence of animations for distance less than 2.5 inches
  // ...
} else if (targetDistance <= 6.50) {
  // Sequence of animations for distance less than 6.5 inches
  // ...
}

