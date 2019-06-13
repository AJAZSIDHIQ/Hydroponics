#include <dht.h>
char serialdata;

int dht_pin = A3;
int sprinkler = 3;
int humThresh = 10;

dht DHT;

int LDR = A1;            // LDR input at A1 pin.
int LED = 6;             // LED is connected to PWM Pin 3.
int LDRReading = 0;      // to store input value of LDR
int lEDBrightness = 0;   // to store the value of LED Brightness
int threshold_val = 640; // Check your threshold and modify it.

int PUMP = 8;

int tempSensor = A2;
int fan = 3;
int tempThresh = 50;

int VAL_PROBE = A0;
int MOISTURE_LEVEL = 1000; // the value after the pump goes ON

void setup() {
  Serial.begin(9600);     // initializing serail communication.
  pinMode(LED, OUTPUT);   // Defining LED pin as output.
  pinMode(fan, OUTPUT);   // fan
  pinMode(PUMP, OUTPUT);   // pump
  pinMode(sprinkler, OUTPUT);   // sprinkler
}

void loop() {


 
            
            
            LDRReading = analogRead(LDR);    // Reading LDR Input.
           // Serial.print("LDR reading: ");
            Serial.println(LDRReading);      // Printing LDR input value.
            
            if (serialdata=='4' || LDRReading>870){                   // Condition to make LED ON. // Converting LDR to LED Brightness.
              digitalWrite(LED, HIGH); // Writing Brightness to LED.
              Serial.println(HIGH);

              delay(2000);
              digitalWrite(LED, LOW);
            }
            else{
              Serial.println(LOW);
              digitalWrite(LED, LOW);             // If LDR is below threshold make LED OFF.
            }
       
            int moisture = analogRead(VAL_PROBE);
            Serial.println(moisture);
            if(serialdata=='2' || moisture>908) {
              Serial.println(HIGH);
              digitalWrite(PUMP, HIGH);
              delay(9000);
              digitalWrite(PUMP, LOW);
            }
            else{
              Serial.println(LOW);
              digitalWrite(PUMP, LOW);
            }
        
            int temperature = analogRead(tempSensor);
            //Serial.print("Temperature: ");
            Serial.println(temperature);
            if(serialdata=='1' || temperature>880){
              Serial.println(HIGH);
              digitalWrite(fan, HIGH);
              delay(9000);
              digitalWrite(fan, LOW);
            }
            else{
              Serial.println(LOW);
              digitalWrite(fan, LOW);
            }
          
            DHT.read11(dht_pin);
             int humidity = DHT.humidity;
           // Serial.print("humidity : ");
            Serial.println(humidity);
            if(serialdata=='3' || humidity>770){
              Serial.println(HIGH);
              digitalWrite(PUMP, HIGH);
              delay(9000);
              digitalWrite(sprinkler, LOW);
            }
            else{
              Serial.println(LOW);
              digitalWrite(sprinkler, LOW);
            }
      
      
  delay(10000);                  // delay to make output readable on serial monitor.

}
