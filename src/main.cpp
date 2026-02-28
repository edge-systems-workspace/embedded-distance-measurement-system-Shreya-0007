#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded Distance Measurement using Ultrasonic Sensor
 * @author Shreya Sharma
 * @date 2026-02-20
 *
 * @details
 * Measures distance using HC-SR04 ultrasonic sensor
 * and displays structured output via Serial Monitor.
 */

// Commit 1: Define pin constants
// TODO 1:
// Define TRIG pin (Use pin 9)
#define TRIG_PIN 9

// TODO 2:
// Define ECHO pin (Use pin 10)
#define ECHO_PIN 10

// Commit 2: Create variables for duration and distance
// TODO 3:
// Create variable to store duration
long duration = 0;

// TODO 4:
// Create variable to store calculated distance
float distance = 0.0;

/**
 * @brief Initialize serial communication and sensor pins
 */
void setup() {
  // Commit 3: Initialize Serial communication and pins
  // TODO 5:
  // Initialize Serial communication at 9600 baud
  Serial.begin(9600);

  // TODO 6:
  // Set TRIG pin as OUTPUT
  pinMode(TRIG_PIN, OUTPUT);

  // TODO 7:
  // Set ECHO pin as INPUT
  pinMode(ECHO_PIN, INPUT);

  // TODO 8:
  // Print initialization message
  Serial.println("=== Ultrasonic Distance Sensor Initialized ===");
  Serial.println("Sensor ready to measure distance...");
  Serial.println();
}

/**
 * @brief Main program loop - measure distance and display output
 */
void loop() {
  // Commit 4: Generate ultrasonic pulse
  // TODO 9:
  // Set TRIG pin LOW for 2 microseconds
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // TODO 10:
  // Set TRIG pin HIGH for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  // TODO 11:
  // Set TRIG pin LOW to complete the pulse
  digitalWrite(TRIG_PIN, LOW);

  // Commit 5: Measure echo duration
  // TODO 12:
  // Measure the duration of the echo pulse (pulseIn returns duration in microseconds)
  duration = pulseIn(ECHO_PIN, HIGH);

  // Commit 6: Calculate distance and display output
  // TODO 13:
  // Calculate distance using formula: distance = (duration * 0.0343) / 2
  // 0.0343 cm/microsecond is the speed of sound in air (343 m/s)
  distance = (duration * 0.0343) / 2;

  // TODO 14:
  // Display structured output with distance measurement
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.println(" µs");

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // TODO 15:
  // Add separator for readability
  Serial.println("---");

  // TODO 16:
  // Delay for 500ms before next measurement
  delay(600);
}