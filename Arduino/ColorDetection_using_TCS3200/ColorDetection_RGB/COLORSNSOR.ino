/*
Color Detection With TCS3200/TCS230 Color Sensor Module (Primary RGB Detector)
Released and Licensed under the GNU General Public License v3.0
Written by Prasanna
For More Project Sample Codes ,CHECK OUT https://github.com/Prasanna1717/MicroControllers
© Dated 2022

*/


// Requirements 

// See guide for details on sensor wiring and usage:
// https://www.elprocus.com/tcs3200-pin-diagram-circuit-and-applications/   (NON AFFILIATE LINK)
// Further Development of this projects Are Welcomed ,PR This Repo 


#include <stdio.h>    //Header File for I/O purposes and User-Defined-Functions
#define  S0 8    //Digital_pins_config For Arduino (You can use it,as per your Preference) 
#define  S1 9
#define  S2 10
#define  S3 11
#define  OUT 12

int r = 0; //Variable Denotion For Color Red
int g = 0; //Variable Denotion For Color Green
int b = 0; //Variable Denotion For Color Blue


void MinvalueNeeded()    //U-D Function for Finding Min Value 
{     
    int arr[] = {r,g,b};         
    int length = sizeof(arr)/sizeof(arr[0]);      
    int min = arr[0];    
    for (int i = 0; i < length; i++) {        
       if(arr[i] < min)    
           min = arr[i];    
    }      
       
    if (min == r)
    {
      Serial.println("RED");
      delay(1000);
    }
    else if (min == g)
    {
      Serial.println("Green");
      delay(1000);
    }
    else if (min == b)
    {
      Serial.println("Blue");
      delay(1000);
    }
     
}    

void setup() {
  // I/O Configs
  pinMode (S0,OUTPUT);
  pinMode (S1,OUTPUT);
  pinMode (S2,OUTPUT);
  pinMode (S3,OUTPUT);
  pinMode (OUT,INPUT);

  Serial.begin (9600);  //Kindly set Serial Baud Rate to 9600

  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
}

void loop() {
  
  //Sensor Activation for Color Red
  r = pulseIn(OUT,LOW); 
  delay(100);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Serial.println("Red value = ");
  //Serial.println( r) ;

  //Sensor Activation for Color Green 
  g = pulseIn(OUT,LOW);  
  delay(100);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  //Serial.println("Green value = ");
  //Serial.println(g) ;
  
  //Sensor Activation for Color Blue
  b = pulseIn(OUT,HIGH);
  delay(100);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
 //Serial.println("Blue value = ");
 // Serial.println(b) ;
 
  delay(3000);
 //Serial.println();
  MinvalueNeeded() ; //Call for UD Function
 
}

