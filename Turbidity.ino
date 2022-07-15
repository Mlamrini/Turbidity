int sensorPin = A0;
float volt;
float NTU;
void setup() {
Serial.begin(9600); // To use the Serial Monitor that reads NTU (Nephelometric Turbidity Units) of the water
}
void loop()
{
for (int i=0; i<800; i++)
{
int sensorvalue = analogRead(A0);
volt += sensorvalue * (5.0 / 1023.0); //Analog reading is changed to 0-1023 to voltage 0-5v.
}
volt = volt/800;
volt = round_to_dp(volt,1); //Volts are rounded.
if (volt >4.2){
NTU = 0;
}
else if(volt < 2.5){ //Prototype works only with values between 2.5v ~ 4.2v
NTU = 3000; //readings below 2.5v = 3000NTU
}else{
NTU = -1120.4*square(volt)+5742.3*volt-4352.9; // Calculate current NTU
}
Serial.print(volt); //Display voltage and NTU on the Serial Monitor
Serial.print(" v");
Serial.print("\n");
Serial.print(NTU);
Serial.print(" NTU");
Serial.println("\n");
delay(2000);
}
float round_to_dp( float in_value, int decimal_place
)
{
float multiplier = powf( 10.0f, decimal_place );
in_value = roundf( in_value * multiplier ) /
multiplier;
return in_value;
}
