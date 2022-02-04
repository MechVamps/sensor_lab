
const int FSRpin = A2;

const float Vin = 5.0; // voltage (in V) from Arduino Uno
const float Rm = 10.0; // constant 10 kilo Ohm measuring resistor in circuit

void setup() 
{
  pinMode(FSRpin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
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
    Serial.print(FSRresistance,4);
    Serial.print("\t");
    Serial.print(FSRconductance,4);
    Serial.print("\t");
    Serial.println(Force,4);
  }
  else{
//    Serial.println("No force detected");
  }
 
  delay(100);
}
