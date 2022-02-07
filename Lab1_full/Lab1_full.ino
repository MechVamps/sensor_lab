

// IR VARIABLE DEFINE:=
/*SHARP GP2Y0A21YK0F IR distance sensor with Arduino and SharpIR library example code. More info: https://www.makerguides.com */
// Include the library:
#include <SharpIR.h>
// Define model and input pin:
#define IRPin A3
#define model 1080
// Create variable to store the distance:
int distance_cm;
/* Model :
  GP2Y0A02YK0F --> 20150
  GP2Y0A21YK0F --> 1080
  GP2Y0A710K0F --> 100500
  GP2YA41SK0F --> 430
*/
// Create a new instance of the SharpIR class:
SharpIR mySensor = SharpIR(IRPin, model);



// AMBIENT TEMPERATURE VARIABLE DEFINE:=
// Code Source: https://www.tutorialspoint.com/arduino/arduino_temperature_sensor.htm
// Code Source: https://osoyoo.com/2017/07/22/arduino-lesson-tmp36/
// Info: https://www.maximintegrated.com/en/products/sensors/MAX31820.html
float temp;
int tempPin = 1; // dibs on pin A1



// FSR VARIABLE DEFINE:=
const int FSRpin = A2;

const float Vin = 5.0; // voltage (in V) from Arduino Uno
const float Rm = 10.0; // constant 10 kilo Ohm measuring resistor in circuit



void setup() 
{
  pinMode(FSRpin, INPUT);
  // Begin serial communication at a baudrate of 9600:
  Serial.begin(9600);
}



void loop() 
{

  //IR LOOP CODE:=
  // Get a distance measurement and store it as distance_cm:
  distance_cm = mySensor.getDistance();
  // Print the measured distance to the serial monitor:
  Serial.print("Mean distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(1000);


  //AMBIENT TEMPERATURE LOOP CODE:=
   // Call function to read temperature
   temp = read_temperature(tempPin);
   // Print temp data
   Serial.print("Temperature [C]: ");
   Serial.print(temp); // display temperature value
   Serial.println();
   delay(1000); // update every 1 sec


   //FSR LOOP CODE:=
  int FSRcounts = analogRead(FSRpin); // get raw counts from FSR
//  Serial.println(FSRcounts);
  if (FSRcounts != 0){
    float FSRvoltage = FSRcounts*Vin/1023.0; // [V] maps raw analog output to a voltage from 0 to 5V
    float FSRresistance = Rm*(Vin/FSRvoltage - 1.0); // [kOhms] solve for FSR resistance from output voltage
    float FSRconductance = 1.0 / FSRresistance; //[1/kOhms] conductance is inverse of resistance
    float Force; 
    // 4 Force-Conductance relationships derived from plots in specs.
    // Different relationship for different conductance ranges.
    if (FSRconductance <= 0.0025) {
      Force = 80000*FSRconductance; // [g]
    }
    else if  (0.0025<FSRconductance<=0.008) {
      Force =  145454*FSRconductance - 163.64; // [g]
    }
    else if (0.008<FSRconductance<=0.026) {
      Force = 222222.22*FSRconductance - 777.78; // [g]
    }
    else if (0.026<FSRconductance) { // <=0.041
      Force = 333333.33*FSRconductance - 3666.67; // [g]
    }
    else {
    }
    Force = 9.81*Force/1000.0; // [N] convert force to Newtons
    Serial.print("Resistance: ");
    Serial.print(FSRresistance,4);
    Serial.print("\t");
    Serial.print("Conductance: ");
    Serial.print(FSRconductance,4);
    Serial.print("\t");
    Serial.print("Force: ");
    Serial.println(Force,4);
  }
  else{
    Serial.println("No force detected");
  }
    delay(100);
 
}



//AMBIENT TEMP FUNCTION CODE:=
double read_temperature(int pin)
{
   // convert raw reading to voltage
   float volt = analogRead(pin) * 5.0;
   volt /= 1024.0; 

   // converting from 10 mv per degree wit 500 mV offset
   float temp = (volt - 0.5) * 100;
   
   return temp;
}
