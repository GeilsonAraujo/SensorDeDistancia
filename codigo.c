#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 14, 21, 19, 18, 5);
float cm = 0;
float cmAnterior = 0;

float readUltrasonicDistance(float triggerPin, float echoPin){
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  lcd.begin(16, 2);
  //Serial.begin(9600);
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(4, OUTPUT); //setLed Pin mode
  delay(10);
  Serial.println("Olá, ESP32!");
}
void loop()
{
  // measure the ping time in cm
  cm = 0.01706 * readUltrasonicDistance(2, 15);

  if (cm != cmAnterior){
    cmAnterior = cm;
    
    Serial.print("Faltam: ");
    Serial.print(cm);
    Serial.print(" cm\n");
    
    lcd.clear();
    lcd.print("Faltam: ");
    lcd.print(cm);
    lcd.print(" cm");
  }else {
    delay(1000); // Delay Wait for SENSOR to reset For Stability
	}
  delay(100); // Wait for 100 millisecond(s)
}
