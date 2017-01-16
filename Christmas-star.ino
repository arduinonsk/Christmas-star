/*----------------------------------------------------------
    Christmas-star.ino

    A demo lighting composition for a Christmas star design.
    The design uses five RGB LEDs with common anode.
    There are six modes given. Add (almoust) any number 
    of yours as you wish.

    Author: Ilya S. Dubkov
    Date: 23.12.2016
    Free for use
-----------------------------------------------------------*/

// pins for color channels
#define R_PIN 11
#define G_PIN 10
#define B_PIN 9

// pins for Common Anodes
#define PIN_1 2
#define PIN_2 3
#define PIN_3 4
#define PIN_4 5
#define PIN_5 6

// an array for Common Anodes pins
int pins[] = {PIN_1, PIN_2, PIN_3, PIN_4, PIN_5};
// colors enumeration
// you can use any word from below list to set color with setColor() function
enum {red, yellow, green, blue, magenta, violet, white};

void setup(){
  // set all pins as OUTPUTs
  pinMode(R_PIN,OUTPUT);
  pinMode(G_PIN,OUTPUT);
  pinMode(B_PIN,OUTPUT);
  pinMode(PIN_1,OUTPUT);
  pinMode(PIN_2,OUTPUT);
  pinMode(PIN_3,OUTPUT);
  pinMode(PIN_4,OUTPUT);
  pinMode(PIN_5,OUTPUT);
  // set color to nothing
  setColor(-1);
  ledsOff();
  // switch off all leds
}

void loop(){
  // run each mode in sequence
  mode1();
  mode2();
  mode3();
  mode4();
  mode5();
  mode6();
}

// function for setting color for LEDs
void setColor(int c){
  digitalWrite(R_PIN,!((c+1)&B001));
  digitalWrite(G_PIN,!((c+1)&B010));
  digitalWrite(B_PIN,!((c+1)&B100));
}

// function for setting color for LEDs using PWM
void setColorPWM(int r, int g, int b){
  analogWrite(R_PIN,r);
  analogWrite(G_PIN,g);
  analogWrite(B_PIN,b);
}

// function for switching off all LEDs
void ledsOff(){
  for(int lo = 0; lo < 5; lo++){
    digitalWrite(pins[lo],LOW);
  }
}   

// function for switching on all LEDs
void ledsOn(){
  for(int lo = 0; lo < 5; lo++){
    digitalWrite(pins[lo],HIGH);
  }
}  

// mode 1.
// LEDs switch on then off one by one counterclockwise
// after full circle the color is changed
void mode1(){
  for(int j=0; j<7; j++){
    setColor(j);
    for(int i=4; i>=0; i--){
      digitalWrite(pins[i],HIGH);
      delay(100);
      digitalWrite(pins[i],LOW);
      delay(100);
    }
  }
}

// mode 2.
// LEDs switch on one by one then off one by one clockwise
// after full circle the color is changed
void mode2(){
  for(int j=6; j>=0; j--){
    setColor(j);
    for(int i=0; i<5; i++){
      digitalWrite(pins[i],HIGH);
      delay(80);
    }
    for(int i=0; i<5; i++){
      digitalWrite(pins[i],LOW);
      delay(80);
    }
  }
}

// mode 3.
// smooth changing colors for the whole gamma
void mode3(){
  int val = 0;
  ledsOn();
  while(val<255){
    val++;
    setColorPWM(val,0,0);
    delay(10);
  }
  val = 0;
  while(val<255){
    val++;
    setColorPWM(255,val,0);
    delay(10);
  } 
  val = 0;
  while(val<255){
    val++;
    setColorPWM(255-val,255,0);
    delay(10);
  }   
  val = 0;
  while(val<255){
    val++;
    setColorPWM(0,255,val);
    delay(10);
  } 
  val = 0;
  while(val<255){
    val++;
    setColorPWM(0,255-val,255);
    delay(10);
  }
  val = 0;
  while(val<255){
    val++;
    setColorPWM(0,0,255-val);
    delay(10);
  }        
}

// mode 4.
// LEDs switch on then off one by one clockwise
// after full circle the color is changed
void mode4(){
  for(int j=6; j>=0; j--){
    setColor(j);
    for(int i=0; i<5; i++){
      digitalWrite(pins[i],HIGH);
      delay(100);
      digitalWrite(pins[i],LOW);
      delay(100);
    }
  }
}

// mode 5.
// LEDs switch on one by one then off one by one counterclockwise
// after full circle the color is changed
void mode5(){
  for(int j=0; j<7; j++){
    setColor(j);
    for(int i=4; i>=0; i--){
      digitalWrite(pins[i],HIGH);
      delay(80);
    }
    for(int i=4; i>=0; i--){
      digitalWrite(pins[i],LOW);
      delay(80);
    }
  }
}

// mode 6.
// all the LEDs change color from the list simultaniously 
// each color repeats five times
void mode6(){
  int countSix = 0;
  ledsOn();
  while(countSix < 5){
    for(int j=0; j<7; j++){
      setColor(j);
      delay(200);
    }
    countSix++;
  }
}
