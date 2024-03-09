
#include <LiquidCrystal.h> //Load Liquid Crystal Library

LiquidCrystal LCD(7, 8, 9, 10, 11, 12); //Create Liquid Crystal Object called LCD

int trigPin=2; //Sensor Trip pin connected to Arduino pin 2
int echoPin=3; //Sensor Echo pin connected to Arduino pin 3
int myCounter=0; //declare your variable myCounter and set to 0
float pingTime; //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in inches
float speedOfSound=776.5; //Speed of sound in miles per ho


byte ghost[] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B10101,
  B11111,
  B11111,
  B10101
};


byte pacmanopenR[] = {
  B01110,
  B11111,
  B11110,
  B11100,
  B11000,
  B11111,
  B11111,
  B01110
};

byte pacmancloseR[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B11000,
  B11111,
  B11111,
  B01110
};


byte pacmancloseL[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B00011,
  B11111,
  B11111,
  B01110
};


byte pacmanopenL[] = {
  B01110,
  B11111,
  B01111,
  B00111,
  B00011,
  B11111,
  B11111,
  B01110
};


byte house[] = {
  B00100,
  B01110,
  B11111,
  B11111,
  B11111,
  B11001,
  B11011,
  B11001
};


byte person[] = {
  B00000,
  B01110,
  B01110,
  B00100,
  B01110,
  B00100,
  B00100,
  B01010
};

byte cloud[] = {
  B01110,
  B11111,
  B00001,
  B01000,
  B00010,
  B10000,
  B00100,
  B10001
};


void setup() {




long duration;
int distance;

   
Serial.begin(9600);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD


  LCD.createChar(1, ghost); 
  // create a new character

LCD.createChar(2, pacmanopenR);

LCD.createChar(3, pacmancloseR);

 LCD.createChar(4, pacmanopenL);

 LCD.createChar(5, pacmancloseL);

 LCD.createChar(6, house);
 
  LCD.createChar(7, person);
 
 LCD.createChar(8, cloud);

}








       void loop() {


// wiring the sensor 
   
Serial.begin(9600);

 digitalWrite(trigPin, LOW); //Set trigger pin low
 delayMicroseconds(2000); //Let signal settle
 digitalWrite(trigPin, HIGH); //Set trigPin high
 delayMicroseconds(15); //Delay in high state
 digitalWrite(trigPin, LOW); //ping has now been sent
 delayMicroseconds(10); //Delay in high state 

 
 pingTime = pulseIn(echoPin, HIGH); //pingTime is presented in microceconds
 pingTime=pingTime/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
 pingTime=pingTime/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
 targetDistance= speedOfSound * pingTime; //This will be in miles, since speed of sound was miles per hour
 targetDistance=targetDistance/2; //Remember ping travels to target and back from target, so you must divide by

 targetDistance= targetDistance*63360; //Convert miles to inches by multipling by 63360 (inches per mile)

      if  (targetDistance <= 2.50) {


  LCD.setCursor(2, 0);
  LCD.write(byte(1));
 
 delay(500);
 
 LCD.setCursor(4,0);
 LCD.write(byte(1));
 
delay(750);

LCD.setCursor(0, 0);
  LCD.write(byte(2));

 delay(750);
  LCD.clear();

  LCD.setCursor(4,0);
  LCD.write(byte(1));
 
 LCD.setCursor(6, 0);
  LCD.write(byte(1));
  
  LCD.setCursor(2, 0);
  LCD.write(byte(3));
 
  delay(750);
 LCD.clear();

 LCD.setCursor(6, 0);
  LCD.write(byte(1));
  
  LCD.setCursor(8, 0);
  LCD.write(byte(1));
  
  LCD.setCursor(4, 0);
  LCD.write(byte(2));
 
   delay(750);
 LCD.clear();

  LCD.setCursor(8, 0);
  LCD.write(byte(1));

LCD.setCursor(10, 0);
  LCD.write(byte(1));
  
  LCD.setCursor(6, 0);
  LCD.write(byte(3));
 
    delay(750);
 LCD.clear();

  LCD.setCursor(10, 0);
  LCD.write(byte(1));

      LCD.setCursor(12, 0);
  LCD.write(byte(1));
  
   LCD.setCursor(8, 0);
  LCD.write(byte(2));
   
  delay(750);
 LCD.clear();

   LCD.setCursor(12, 0);
  LCD.write(byte(1));

 LCD.setCursor(14, 0);
  LCD.write(byte(1));

    LCD.setCursor(10, 0);
  LCD.write(byte(3));

delay(750);
 LCD.clear();
 
 LCD.setCursor(14, 0);
  LCD.write(byte(1));

    LCD.setCursor(12, 0);
  LCD.write(byte(2));

delay(750);
 LCD.clear();

LCD.setCursor(15,1);
LCD.write(byte(1));

LCD.setCursor(13,1);
LCD.write(byte(1));

delay(750);
LCD.clear();

LCD.setCursor(13,1);
LCD.write(byte(1));
delay(500);
LCD.setCursor(9, 1);
  LCD.write(byte(1));
  
delay(250);

LCD.setCursor(15,1);
LCD.write(byte(4));

delay(750);
LCD.clear();

LCD.setCursor(9, 1);
  LCD.write(byte(1));

LCD.setCursor(5, 1);
  LCD.write(byte(1));
  
    LCD.setCursor(13, 1);
  LCD.write(byte(5));

delay(750);
LCD.clear();

LCD.setCursor(5, 1);
  LCD.write(byte(1));
  
LCD.setCursor(2, 1);
  LCD.write(byte(1));

    LCD.setCursor(9, 1);
  LCD.write(byte(4));

  
delay(750);
LCD.clear();

LCD.setCursor(2, 1);
  LCD.write(byte(1));

    LCD.setCursor(5, 1);
  LCD.write(byte(5));

  delay(750);
LCD.clear();

LCD.setCursor(2,1);
LCD.write(byte(4));

LCD.clear();


      } else {LCD.clear();}

   

        if  (targetDistance <= 6.50) {


LCD.setCursor(0, 1);
  LCD.write(byte(7));
  
    LCD.setCursor(14, 1);
  LCD.write(byte(6));

 delay(500);
LCD.clear();

LCD.setCursor(2, 1);
  LCD.write(byte(7));
  
    LCD.setCursor(14, 1);
  LCD.write(byte(6));

 LCD.setCursor(3,0);
 LCD.write(byte(8));

 LCD.setCursor(12,0);
 LCD.write(byte(8));
 
 LCD.setCursor(1,0);
 LCD.write(byte(8));
 
    delay(500);
LCD.clear();

  LCD.setCursor(4, 1);
  LCD.write(byte(7));
  
    LCD.setCursor(14, 1);
  LCD.write(byte(6));

 LCD.setCursor(7,0);
 LCD.write(byte(8));

 
 LCD.setCursor(0,0);
 LCD.write(byte(8));

 LCD.setCursor(4,0);
 LCD.write(byte(8));
   

    delay(500);
LCD.clear();

LCD.setCursor(6, 1);
  LCD.write(byte(7));
  
    LCD.setCursor(14, 1);
  LCD.write(byte(6));

  LCD.setCursor(5,0);
 LCD.write(byte(8));

 LCD.setCursor(7,0);
 LCD.write(byte(8));

 LCD.setCursor(11,0);
 LCD.write(byte(8));
    
    delay(500);
    
LCD.clear();

LCD.setCursor(8, 1);
  LCD.write(byte(7));
  
    LCD.setCursor(14, 1);
  LCD.write(byte(6));

   LCD.setCursor(9,0);
 LCD.write(byte(8));

 LCD.setCursor(2,0);
 LCD.write(byte(8));

 LCD.setCursor(5,0);
 LCD.write(byte(8));
 
  delay(500);
LCD.clear();

LCD.setCursor(10, 1);
  LCD.write(byte(7));
  
    LCD.setCursor(14, 1);
  LCD.write(byte(6));
 
 LCD.setCursor(14,0);
 LCD.write(byte(8));

  LCD.setCursor(14,0);
 LCD.write(byte(8));
   
 
  delay(500);
LCD.clear();


LCD.setCursor(12, 1);
  LCD.write(byte(7));
  
    LCD.setCursor(14, 1);
  LCD.write(byte(6));

 LCD.setCursor(0,0);
 LCD.write(byte(8));

  LCD.setCursor(1,0);
 LCD.write(byte(8));
   
   
  delay(500);
LCD.clear();

 } else {LCD.clear();}

 } 
 
