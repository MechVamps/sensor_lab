// IR VARIABLE DEFINE:=
/*SHARP GP2Y0A21YK0F IR distance sensor with Arduino and SharpIR library example code. More info: https://www.makerguides.com */
// Include the library:
#include <SharpIR.h>
// Define model and input pin:
#define IRPin A3
#define model 1080
// Create variable to store the distance:
int distance_cm = 0;
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
int temp = 0;
int tempPin = 1; // dibs on pin A1

<<<<<<< HEAD
<<<<<<< HEAD


//// FSR VARIABLE DEFINE:=
int fsrPin = 2;     // the FSR and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the FSR resistor divider
int fsrVoltage;     // the analog reading converted to voltage
unsigned long fsrResistance;  // The voltage converted to resistance, can be very big so make "long"
unsigned long fsrConductance; 
long fsrForce;       // Finally, the resistance converted to force

//const int FSRpin = A2;
//
//const float Vin = 5.0; // voltage (in V) from Arduino Uno
//const float Rm = 5.1; // constant 1 kilo Ohm measuring resistor in circuit



void setup() 
{
  //pinMode(FSRpin, INPUT);
=======
//// FSR VARIABLE DEFINE:=
int fsrPin = 2;     // the FSR and 10K pulldown are connected to a0
long force = 0; 

void setup() 
{
>>>>>>> main
=======
//// FSR VARIABLE DEFINE:=
int fsrPin = 2;     // the FSR and 10K pulldown are connected to a0
long force = 0; 

void setup() 
{
>>>>>>> main
  // Begin serial communication at a baudrate of 9600:
  Serial.begin(9600);
}


//AMBIENT TEMP FUNCTION CODE:=
double read_temperature(int pin)
{
  // convert raw reading to voltage
  float volt = analogRead(pin) * 5.0;
  volt /= 1024.0; 

<<<<<<< HEAD
<<<<<<< HEAD
  //IR LOOP CODE:=
  // Get a distance measurement and store it as distance_cm:
  distance_cm = mySensor.distance();
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


//   //FSR LOOP CODE:=
fsrReading = analogRead(fsrPin);  // get raw counts from FSR
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
 
  // analog voltage reading ranges from about 0 to 1023 which maps to 0V to 5V (= 5000mV)
  fsrVoltage = map(fsrReading, 0, 1023, 0, 5000);
  Serial.print("Voltage reading in mV = ");
  Serial.println(fsrVoltage);  
 
  if (fsrVoltage == 0) {
    Serial.println("No pressure");  
=======
  // converting from 10 mv per degree wit 500 mV offset
  int temp = (volt - 0.5) * 100;
   
  return temp;
}

=======
  // converting from 10 mv per degree wit 500 mV offset
  int temp = (volt - 0.5) * 100;
   
  return temp;
}

>>>>>>> main
long read_force(int pin)
{
  int fsrReading;     // the analog reading from the FSR resistor divider
  int fsrVoltage;     // the analog reading converted to voltage
  unsigned long fsrResistance;  // The voltage converted to resistance, can be very big so make "long"
  unsigned long fsrConductance; 
  long fsrForce;       // Finally, the resistance converted to force

  fsrReading = analogRead(pin);  // get raw counts from FSR
  // Serial.print("Analog reading = ");
  // Serial.println(fsrReading);
 
  // analog voltage reading ranges from about 0 to 1023 which maps to 0V to 5V (= 5000mV)
  fsrVoltage = map(fsrReading, 0, 1023, 0, 5000);
  // Serial.print("Voltage reading in mV = ");
  // Serial.println(fsrVoltage);  
 
  if (fsrVoltage == 0) {
    // Serial.println("No pressure");  
    fsrForce = 0;
<<<<<<< HEAD
>>>>>>> main
=======
>>>>>>> main
  } else {
    // The voltage = Vcc * R / (R + FSR) where R = 10K and Vcc = 5V
    // so FSR = ((Vcc - V) * R) / V        yay math!
    fsrResistance = 5000 - fsrVoltage;     // fsrVoltage is in millivolts so 5V = 5000mV
    fsrResistance *= 10000;                // 10K resistor
    fsrResistance /= fsrVoltage;
<<<<<<< HEAD
<<<<<<< HEAD
    Serial.print("FSR resistance in ohms = ");
    Serial.println(fsrResistance, 4);
 
    fsrConductance = 1000000;           // we measure in micromhos so 
    fsrConductance /= fsrResistance;
    Serial.print("Conductance in microMhos: ");
    Serial.println(fsrConductance, 4);
 
    // Use the two FSR guide graphs to approximate the force
    if (fsrConductance <= 1000) {
      fsrForce = fsrConductance / 80;
      Serial.print("Force in Newtons: ");
      Serial.println(fsrForce, 4);      
    } else {
      fsrForce = fsrConductance - 1000;
      fsrForce /= 30;
      Serial.print("Force in Newtons: ");
      Serial.println(fsrForce, 4);            
    }
  }
  Serial.println("--------------------");
  delay(1000);
  
//  int FSRcounts = analogRead(FSRpin); // get raw counts from FSR
////  Serial.println(FSRcounts);
//  if (FSRcounts != 0){
//    float FSRvoltage = FSRcounts*Vin/1023.0; // [V] maps raw analog output to a voltage from 0 to 5V
//    float FSRresistance = Rm*(Vin/FSRvoltage - 1.0); // [kOhms] solve for FSR resistance from output voltage
//    float FSRconductance = 1.0 / FSRresistance; //[1/kOhms] conductance is inverse of resistance
//    float Force; 
//    // 4 Force-Conductance relationships derived from plots in specs.
//    // Different relationship for different conductance ranges.
//    if (FSRconductance <= 0.0025) {
//      Force = 80000*FSRconductance; // [g]
//    }
//    else if  (0.0025<FSRconductance<=0.008) {
//      Force =  145454*FSRconductance - 163.64; // [g]
//    }
//    else if (0.008<FSRconductance<=0.026) {
//      Force = 222222.22*FSRconductance - 777.78; // [g]
//    }
//    else if (0.026<FSRconductance) { // <=0.041
//      Force = 333333.33*FSRconductance - 3666.67; // [g]
//    }
//    else {
//    }
//    //Force = 9.81*Force/1000.0; // [N] convert force to Newtons
//    Serial.print("Resistance: ");
//    Serial.print(FSRresistance, 4);
//    Serial.print("\t");
//    Serial.print("Conductance: ");
//    Serial.print(FSRconductance, 4);
//    Serial.print("\t");
//    Serial.print("Force: ");
//    Serial.println(Force, 4);
//  }
//  else{
//    Serial.println("No force detected");
//  }
//    delay(100);
}
=======
    // Serial.print("FSR resistance in ohms = ");
    // Serial.println(fsrResistance, 4);
 
    fsrConductance = 1000000;           // we measure in micromhos so 
    fsrConductance /= fsrResistance;
    // Serial.print("Conductance in microMhos: ");
    // Serial.println(fsrConductance, 4);
 
    // Use the two FSR guide graphs to approximate the force
    if (fsrConductance <= 1000) {
      fsrForce = fsrConductance / 80;  
    } else {
      fsrForce = fsrConductance - 1000;
      fsrForce /= 30;          
    }
  }
>>>>>>> main
=======
    // Serial.print("FSR resistance in ohms = ");
    // Serial.println(fsrResistance, 4);
 
    fsrConductance = 1000000;           // we measure in micromhos so 
    fsrConductance /= fsrResistance;
    // Serial.print("Conductance in microMhos: ");
    // Serial.println(fsrConductance, 4);
 
    // Use the two FSR guide graphs to approximate the force
    if (fsrConductance <= 1000) {
      fsrForce = fsrConductance / 80;  
    } else {
      fsrForce = fsrConductance - 1000;
      fsrForce /= 30;          
    }
  }
>>>>>>> main

  return fsrForce; 
}


void loop() 
{
  //IR LOOP CODE:=
  // Get a distance measurement and store it as distance_cm:
  distance_cm = mySensor.distance();
  // Print the measured distance to the serial monitor:
  // Serial.print("Mean distance: ");
  // Serial.print(distance_cm);
  // Serial.println(" cm");
  // delay(1000);

  //AMBIENT TEMPERATURE LOOP CODE:=
  // Call function to read temperature
  temp = read_temperature(tempPin);
  // Print temp data
  // Serial.print("Temperature [C]: ");
  // Serial.print(temp); // display temperature value
  // Serial.println();
  // delay(1000); // update every 1 sec
  
  //FSR LOOP CODE:=
  force = read_force(fsrPin);
  // Serial.print("Force in Newtons: ");
  // Serial.println(force, 4);    

  // Serial.println("--------------------");
  // delay(1000);
  
  char buffer[100];
  sprintf(buffer, "<sensor(T%d;I%d;F%ld)>", temp, distance_cm, force);
  Serial.println(buffer);
}


