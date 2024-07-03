#define trigpin 3 // digital pin 4 
#define echopin 2 // digital pin 3

//#define IR_Sensor A1 /*D2 IR pin defined*/
//#define LED A2       /*D3 LED Pin defined*/

char t;
int ena = 6; 
int enb = 5; 
//int IR;             /*Variable that will store IR output status*/


int in1 = 8; 
int in2 = 9; 
int in3 = 10; 
int in4 = 11; 

//int sensor = 13;///////////////////////////////////////////

float distancem; 
void setup()
{
Serial.begin(9600);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);

  pinMode(ena, OUTPUT); 
  pinMode(enb, OUTPUT); 

  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(12, OUTPUT);
  
//  pinMode(A0,INPUT);  // 10k Potentiometer

//pinMode(IR_Sensor, INPUT);   /*IR Pin D2 defined as Input*/
//pinMode(LED, OUTPUT);        /*D3 pin for LED is set as Output*/

//  pinMode(sensor,INPUT);////////////////////////////

 analogWrite(ena, 0); 
 analogWrite(enb, 0);
 delay(1000); 
}

void loop()
{
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}

//
 // IR=digitalRead(IR_Sensor);  /*digital read function to check IR pin status*/
  //if(IR==LOW)
  //{  
  
 // delay(5000);            /*If sensor detect any reflected ray*/
 // digitalWrite(LED, HIGH);   /*LED will turn ON*/
  //delay(10000);
//}
//else {
 // IR=digitalRead(IR_Sensor);
 // if(IR<=HIGH){
 // digitalWrite(LED,LOW);  /*if no reflection detected LED will remain OFF*/
 // while(0){   
  //}   
 // }
//}
//}

///////////////////////////
//  {   
 // int s=analogRead(A0); // 10k Potentiometer   
 // int z=map(s,0,1024,0,255);   
 // Serial.println(z);   
//  analogWrite(ConA,z);
 // analogWrite(ConB,z);
//  }   
////////////////////////////////////////
///////////////////////////////////
//if(digitalRead(sensor)==1)
//{
//digitalWrite(ena,HIGH);
//digitalWrite(enb,HIGH);
//}
//else
//{
//delay(1000);
//digitalWrite(ena,LOW);
//digitalWrite(enb,LOW);
//}
/////////////////////////////////
 int duration, distance;
 digitalWrite(trigpin, HIGH);

delayMicroseconds(1000);  
digitalWrite(trigpin, LOW);


duration = pulseIn(echopin,HIGH);

distance = ( duration / 2) / 20.1;
Serial.println("inches:"); 
Serial.println(distance);

distance = map(distance, 0 , 197, 0 , 255 ); 


if(  (distance < 0)   ) 
{
distance = 0; 
} else
if(  (distance >= 0) && (distance <= 40, t == 'X')  ) //Stop
{
  analogWrite(ena, 0); 
 analogWrite(enb, 0);
    digitalWrite(in1, LOW); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

 else

if(  distance > 40,t == 'F'  ) //Forward
{
  analogWrite(ena, distance); 
 analogWrite(enb, distance);
    digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
 else

if(  t == 'B'  ) //Reverce
{
  analogWrite(ena, 197); 
 analogWrite(enb, 197);
    digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
 else

if(  distance > 40,t == 'L'  ) // Left rotate
{
  analogWrite(ena, distance); 
 analogWrite(enb, distance);
    digitalWrite(in1, LOW); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
 else

if(  distance > 40,t == 'R'  ) //Right rotect
{
  analogWrite(ena, distance); 
 analogWrite(enb, distance);
    digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

else if(t == 'W'){    //Front Light turn on or off
digitalWrite(4,HIGH);
}
else if(t == 'w'){
digitalWrite(4,LOW);
}

else if(t ==  'U'){    //Back Light turn on or off
digitalWrite(7,HIGH);
}
else if(t == 'u'){
digitalWrite(7,LOW);
}

else if(t ==  'V'){    //Horn turn on or off
digitalWrite(12,HIGH);
}
else if(t == 'v'){
digitalWrite(12,LOW);
}
}