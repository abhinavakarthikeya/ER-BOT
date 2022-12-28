int verylessdanger=8;
int lessdanger=7;
int moredanger=6;
int sensePin = A0; //This is the Arduino Pin that will read the sensor output
int sensorInput; //The variable we will use to store the sensor input
double temp; //The variable we will use to store temperature in degrees.
char mystr[6];
void setup() {
// put your setup code here, to run once:
   //Start the Serial Port at 9600 baud (default)
pinMode(lessdanger,OUTPUT);
pinMode(verylessdanger,OUTPUT);
pinMode(moredanger,OUTPUT);
Serial.begin(9600);
}
void loop() {
// put your main code here, to run repeatedly:
sensorInput = analogRead(A0); //read the analog sensor and store it
temp = (double)sensorInput / 1024; //find percentage of input reading
temp = temp * 5; //multiply by 5V to get voltage
temp = temp-0.5; //Subtract the offset
temp = temp * 100; //Convert to degrees
Serial.println(temp);
delay(1000);

if (temp>100){
  digitalWrite(moredanger,HIGH);
  digitalWrite(lessdanger,LOW);
  digitalWrite(verylessdanger,LOW);
  delay(1000);
}
else if (0<temp<100){
  digitalWrite(lessdanger,HIGH);
  digitalWrite(verylessdanger,LOW);
  digitalWrite(moredanger,LOW);
  delay(1000);
}
else{
  digitalWrite(verylessdanger,HIGH);
  digitalWrite(moredanger,LOW);
  digitalWrite(lessdanger,LOW);
  delay(1000);
}
}
