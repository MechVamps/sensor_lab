// Code Source: https://www.tutorialspoint.com/arduino/arduino_temperature_sensor.htm
// Code Source: https://osoyoo.com/2017/07/22/arduino-lesson-tmp36/
// Info: https://www.maximintegrated.com/en/products/sensors/MAX31820.html

float temp;
int tempPin = 1; // dibs on pin A1

void setup() {
   Serial.begin(9600);
}

void loop() {
   // Call function to read temperature
   temp = read_temperature(tempPin);

   // Print temp data
   Serial.print("Temperature [C]: ");
   Serial.print(temp); // display temperature value
   Serial.println();
   delay(1000); // update every 1 sec

}

double read_temperature(int pin){
   // convert raw reading to voltage
   float volt = analogRead(pin) * 5.0;
   volt /= 1024.0; 

   // converting from 10 mv per degree wit 500 mV offset
   float temp = (volt - 0.5) * 100;
   
   return temp;
}
