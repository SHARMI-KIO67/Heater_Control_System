#include <OneWire.h>
#include <DallasTemperature.h>

// Pin definitions
#define ONE_WIRE_BUS 4     // DS18B20 data pin
#define RELAY_PIN 16       // Relay control pin
#define LED_PIN 17         // Heater status LED

// Create objects
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Temperature thresholds (in Celsius)
float lowerThreshold = 30.0;
float targetTemp = 65.0;
float overheatThreshold = 70.0;

// State enum
enum State {
  IDLE,
  HEATING,
  STABILIZING,
  TARGET_REACHED,
  OVERHEAT
};

State currentState = IDLE;

void setup() {
  Serial.begin(115200);
  sensors.begin();
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Heater OFF initially
  digitalWrite(LED_PIN, LOW);
  Serial.println("Heater control system initialized.");
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  // Determine state
  if (tempC < lowerThreshold) {
    currentState = HEATING;
  } else if (tempC >= lowerThreshold && tempC < targetTemp - 3) {
    currentState = STABILIZING;
  } else if (tempC >= targetTemp && tempC <= overheatThreshold) {
    currentState = TARGET_REACHED;
  } else if (tempC > overheatThreshold) {
    currentState = OVERHEAT;
  }

  // Perform actions based on state
  switch (currentState) {
    case IDLE:
      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      break;

    case HEATING:
      digitalWrite(RELAY_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      break;

    case STABILIZING:
      digitalWrite(RELAY_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      break;

    case TARGET_REACHED:
      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      break;

    case OVERHEAT:
      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      Serial.println("WARNING: Overheat detected!");
      break;
  }

  // Log status
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" °C | State: ");
  printState(currentState);

  delay(1000); // Wait 1 second
}

void printState(State s) {
  switch (s) {
    case IDLE: Serial.println("IDLE"); break;
    case HEATING: Serial.println("HEATING"); break;
    case STABILIZING: Serial.println("STABILIZING"); break;
    case TARGET_REACHED: Serial.println("TARGET_REACHED"); break;
    case OVERHEAT: Serial.println("OVERHEAT"); break;
  }
}
