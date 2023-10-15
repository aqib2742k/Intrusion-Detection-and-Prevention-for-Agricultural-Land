#include <Wire.h>
#include <Adafruit_MLX90614.h>

/* Constants for animal classification thresholds
  const float monkeyTempThreshold = 37.5;   // Body temperature threshold for monkey (in Celsius)
  const float cowTempThreshold = 38.5;      // Body temperature threshold for cow (in Celsius)
  const float buffaloTempThreshold = 39.0;  // Body temperature threshold for buffalo (in Celsius)
  const float elephantTempThreshold = 39.5; // Body temperature threshold for elephant (in Celsius)
*/

//body temperature

const float elephantMinTemp = 40.0;
const float elephantMaxTemp = 45.0;
const float monkeyMinTemp = 36.0;
const float monkeyMaxTemp = 38.5;
const float cowMinTemp = 40.0;
const float cowMaxTemp = 42.0;
const float buffaloMinTemp = 40.0;
const float buffaloMaxTemp = 43.0;
const float nilgaiMinTemp = 37.5; //data taken manually from me
const float nilgaiMaxTemp = 40.0; //data taken manually from me

//sound intensity

const int elephantMinSound = 80;
const int elephantMaxSound = 100;
const int monkeyMinSound = 20;
const int monkeyMaxSound = 45;
const int cowMinSound = 50;
const int cowMaxSound = 70;
const int buffaloMinSound = 55;
const int buffaloMaxSound = 75;
const int nilgaiMinSound = 300; //data taken manually from me
const int nilgaiMaxSound = 400; //data taken manually from me

 //pressure exerted
 
const float elephantMinforce = 150.0;
const float elephantMaxforce = 150.0;
const float monkeyMinforce = 20.0;
const float monkeyMaxforce = 50.0;
const float cowMinforce = 150.0;
const float cowMaxforce = 80.0;
const float buffaloMinforce = 150.0;
const float buffaloMaxforce = 100.0;
const float nilgaiMinforce = 1.0; //data taken manually from me
const float nilgaiMaxforce = 5.0; //data taken manually from me

// Pin definitions for the sensors and actuators
const int mlxSensorAddress = 0x5A;    // I2C address of MLX90614 sensor
const int soundSensorPin = A0;        // Analog pin for sound sensor
const int fsrSensorPin = A1;          // Analog pin for FSR sensor
const int relayControlPin = 5;        // Digital pin for relay control
const int buzzerPin = 3;              // Digital pin for buzzer control
const int ledPin = 4;                 // Digital pin for LED control

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  mlx.begin();
  pinMode(soundSensorPin, INPUT);
  pinMode(fsrSensorPin, INPUT);
  pinMode(relayControlPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read sensor values
  float temp = mlx.readObjectTempC();
  int sound = analogRead(soundSensorPin);
  int force = analogRead(fsrSensorPin);
  
  // Animal classification based on temperature threshold
   if (temp >= elephantMinTemp && temp <= elephantMaxTemp) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(2000);
  } else if (temp >= monkeyMinTemp && temp <= monkeyMaxTemp) {
     digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(2000);
  } else if (temp >= cowMinTemp && temp <= cowMaxTemp) {
     digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(2000);
  } else if (temp >= buffaloMinTemp && temp <= buffaloMaxTemp) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(2000);
  } else if (temp >= nilgaiMinTemp && temp <= nilgaiMaxTemp) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayControlPin, HIGH); // Activate the relay for the pump
  } else {
    // No animal detected
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    digitalWrite(relayControlPin, LOW); // Deactivate the relay for the pump
  }

   //Animal classification based on sound threshold
   
   if(sound >= elephantMinSound && sound <= elephantMaxSound){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
   }
   else if(sound >= monkeyMinSound && sound <= monkeyMaxSound){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
   }else if(sound >= cowMinSound && sound <= cowMaxSound){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
   }else if(sound >= buffaloMinSound && sound <= buffaloMaxSound){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
   }else if(sound >= nilgaiMinSound && sound <= nilgaiMaxSound){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayControlPin, HIGH);
    delay(5000);
   }else {
    // No animal detected
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    digitalWrite(relayControlPin, LOW); // Deactivate the relay for the pump
  }

   //Animal classification based on force threshold  
   
   if(force >= elephantMinforce && force <= elephantMaxforce ){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    
   }else if(force >= monkeyMinforce && force <= monkeyMaxforce){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
   }else if(force >= cowMinforce && force <= cowMaxforce){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
   }else if(force >= buffaloMinforce && force <= buffaloMaxforce){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
   }else if(force >= nilgaiMinforce && force <= nilgaiMaxforce){
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayControlPin, HIGH);
    delay(5000);
   }else {
    // No animal detected
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    digitalWrite(relayControlPin, LOW); // Deactivate the relay for the pump
  }

 /* if (bodyTemp >= monkeyMinTemp && bodyTemp <= monkeyMaxTemp ) {
    // Monkey detected
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayControlPin, HIGH); // Activate the relay for the pump
  } else if (bodyTemp > cowTempThreshold) {
    // Cow detected
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayControlPin, HIGH); // Activate the relay for the pump
  } else if (bodyTemp > buffaloTempThreshold) {
    // Buffalo detected
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayControlPin, HIGH); // Activate the relay for the pump
  } else if (bodyTemp > elephantTempThreshold) {
    // Elephant detected
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayControlPin, HIGH); // Activate the relay for the pump
  } else {
    // No animal detected
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    digitalWrite(relayControlPin, LOW); // Deactivate the relay for the pump
  }
  */
  // Print sensor values
  Serial.print("Body Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");
  Serial.print("Sound Intensity: ");
  Serial.println(sound);
  Serial.print("Pressure: ");
  Serial.println(force);
  
  delay(1000);
}
