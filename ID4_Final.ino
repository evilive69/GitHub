//Initial release for Independence Day 5/22/18.
//Remarked out references for clearing color in loop.
//Being run on stadium style lights.

#include <pinduino.h>

int aLEDNum1 = 54;

pinduino pd (aLEDNum1, "Nano");

int bg_chase_on = 0;
unsigned long timeLastEvent = 0; // time last event was last triggered
int startChaseWaitTime = 20000; //Amount of time to wait before chase lights start up again 1000 == 1 second

void setup() {
  Serial.begin(115200);
  pd.adrLED1()->clear();
  pd.pinState()->reset();
}

void loop(){
  for (int i = 0; i < 500; i = i + 1) { //check pinstates for a while
    pd.pinState()->update();
  }
  checkPinStates();
  if (millis()-timeLastEvent > startChaseWaitTime) { bg_chase_on=1; }
//  if (millis()-timeLastEvent > whiteWaitTime) { pd.adrLED1()->fadeIn("white", 200);}
  if (bg_chase_on){backgroundChase();}
}

void checkPinStates(){
  int trigger =0;
  if ( pd.pinState()->J6(1) ){
    pd.adrLED1()->color("green",255);
    trigger=1;
  }
  if ( pd.pinState()->J6(2) ){
    pd.adrLED1()->bullet2Color("green", "mint", 25, 10, 1);
    pd.adrLED1()->bullet2Color("green", "mint", 25, 10, -1);
    trigger=1;
  }
  if ( pd.pinState()->J6(3) ){
    pd.adrLED1()->color("blue",255);
    delay(20);
    pd.adrLED1()->color("sky",255);
    delay(20);
    pd.adrLED1()->color("blue",255);
    delay(20);
    pd.adrLED1()->color("sky",255);
    trigger=1;
  }
  if ( pd.pinState()->J6(4) ){ 
    pd.adrLED1()->chase2ColorFromPoint(27, "purple", "red", 15, 20);
    pd.adrLED1()->chase2ColorFromPoint(27, "purple", "red", 15, 20);
    pd.adrLED1()->color("red", 255);
    trigger=1;
  }
  if ( pd.pinState()->J6(5) ){ 
    pd.adrLED1()->color("cyan",255);
    trigger=1;
  }
  if ( pd.pinState()->J6(6) ){ 
    pd.adrLED1()->explosion(27, "red", 9);
    pd.adrLED1()->explosion(3, "blue", 9);
    pd.adrLED1()->explosion(35, "red", 9);
    pd.adrLED1()->explosion(27, "white", 9);
    pd.adrLED1()->explosion(3, "red", 9);
    pd.adrLED1()->explosion(35, "blue", 9);
    pd.adrLED1()->explosion(27, "red", 9);
    pd.adrLED1()->explosion(3, "white", 9);
    pd.adrLED1()->explosion(35, "red", 9);
    pd.adrLED1()->explosion(27, "blue", 9);
    pd.adrLED1()->explosion(3, "red", 9);
    pd.adrLED1()->explosion(35, "white", 9);
    pd.adrLED1()->explosion(27, "red", 9);
    pd.adrLED1()->explosion(3, "blue", 9);
    pd.adrLED1()->explosion(35, "red", 9);
    pd.adrLED1()->explosion(27, "white", 9);
    pd.adrLED1()->explosion(3, "red", 9);
    pd.adrLED1()->explosion(35, "blue", 9);
    pd.adrLED1()->color("blue",255);
    trigger=1;
  }
  if ( pd.pinState()->J6(7) ){   
    pd.adrLED1()->spreadInFromPoint2Color(27, "magenta", "sky", 350);
    pd.adrLED1()->color("magenta", 255);
    pd.adrLED1()->spreadInFromPoint2Color(27, "magenta", "sky", 350);
    pd.adrLED1()->color("magenta", 255);
    pd.adrLED1()->spreadInFromPoint2Color(27, "magenta", "sky", 350);
    pd.adrLED1()->color("magenta", 255);
    delay(100);
    trigger=1;
  }
  if ( pd.pinState()->J6(8) ){ 
    pd.adrLED1()->color("sky",255);
    trigger=1;
  }
 if ( pd.pinState()->J7(2) ){ 
   pd.adrLED1()->bullet2Color("blue", "white", 20, 10, -1);
   pd.adrLED1()->bullet2Color("blue", "white", 20, 10, 1);
   pd.adrLED1()->color("sky", 255);
    trigger=1;
  }
 if ( pd.pinState()->J7(3) ){ 
    trigger=1;
  }
 if ( pd.pinState()->J7(4) ){ 
  pd.adrLED1()->fadeIn("lavendar", 50);
  pd.adrLED1()->fadeIn("lavendar", 75);
   trigger=1;
  }
 if ( pd.pinState()->J7(6) ){ 
  pd.adrLED1()->fadeColor2Color("lime", "green", 75);
  pd.adrLED1()->color("green",255);
   trigger=1;
  }
 if ( pd.pinState()->J7(7) ){ 
    trigger=1;
  }
 if ( pd.pinState()->J7(8) ){ 
    trigger=1;
  }
 if ( pd.pinState()->J7(9) ){ 
  pd.adrLED1()->color("white",255);
   trigger=1;
  }
 if ( pd.pinState()->J7(10) ){ 
    trigger=1;
  }

//trigger is to take care of any cleanup after a sequence has been triggered.
  if (trigger) {
//   pd.adrLED1()->clear();
   pd.pinState()->reset();
   trigger =0;
   bg_chase_on = 0;
   timeLastEvent = millis();
  }
//end function checkPinStates
}


void backgroundChase() {
 pd.adrLED1()->color("blue",255);
 pd.adrLED1()->rainbow(7);
 pd.adrLED1()->color("green",255);
 pd.adrLED1()->rainbow(7);
 pd.adrLED1()->color("red",255);
 pd.adrLED1()->rainbow(7);
 pd.adrLED1()->color("orange",255);
 pd.adrLED1()->rainbow(7);
 pd.adrLED1()->rainbowCycle(7);
 pd.adrLED1()->rainbowCycle(7);
 pd.adrLED1()->rainbowCycle(7);
 pd.adrLED1()->rainbowCycle(7);
 pd.adrLED1()->fadeIn("red", 300);
 pd.adrLED1()->fadeOut(300);
 pd.adrLED1()->fadeIn("purple", 300);
 pd.adrLED1()->fadeOut(300);
 pd.adrLED1()->fadeIn("lavender", 300);
 pd.adrLED1()->fadeOut(300);
 pd.adrLED1()->fadeIn("lime", 300);
 pd.adrLED1()->fadeOut(300);
 pd.adrLED1()->fadeIn("green", 300);
 pd.adrLED1()->fadeOut(300);
 pd.adrLED1()->fadeIn("cyan", 300);
 pd.adrLED1()->fadeOut(300);
 pd.adrLED1()->fadeIn("blue", 300);
 pd.adrLED1()->fadeOut(300);
 pd.adrLED1()->fadeIn("sky", 300);
 pd.adrLED1()->fadeOut(300);
 pd.adrLED1()->fadeIn("mint", 300);
 pd.adrLED1()->fadeOut(300);
 pd.adrLED1()->fadeColor2Color("red", "purple", 100);
 pd.adrLED1()->fadeColor2Color("green", "blue", 100);
 pd.adrLED1()->fadeColor2Color("blue", "sky", 100);
 pd.adrLED1()->chase2Color("blue", "green", 10, 50, 1);
 pd.adrLED1()->chase2Color("green", "yellow", 10, 50, 1);
 pd.adrLED1()->chase2ColorFromPoint(27, "purple", "red", 15, 20);
 pd.adrLED1()->chase2ColorFromPoint(27, "purple", "red", 15, 20);
 pd.adrLED1()->spreadInFromPoint2Color(27, "magenta", "sky", 350);
 pd.adrLED1()->color("blue", 255);
 pd.adrLED1()->spreadInFromPoint2Color(27, "magenta", "sky", 350);
 pd.adrLED1()->color("blue", 255);
 pd.adrLED1()->spreadInFromPoint2Color(27, "magenta", "sky", 350);
 pd.adrLED1()->color("blue", 255);
 pd.adrLED1()->spreadInFromPoint2Color(27, "magenta", "sky", 350);
 pd.adrLED1()->spreadInFromPoint(27, "yellow", 50);
 pd.adrLED1()->spreadInFromPoint(27, "orange", 50);
 pd.adrLED1()->spreadInFromPoint(27, "red", 50);
 pd.adrLED1()->spreadInFromPoint(27, "purple", 50);
 pd.adrLED1()->spreadInFromPoint(27, "magenta", 50);
 pd.adrLED1()->explosion(27, "red", 9);
 pd.adrLED1()->explosion(3, "blue", 9);
 pd.adrLED1()->explosion(35, "red", 9);
 pd.adrLED1()->explosion(27, "white", 9);
 pd.adrLED1()->explosion(3, "red", 9);
 pd.adrLED1()->explosion(35, "blue", 9);
 pd.adrLED1()->explosion(27, "red", 9);
 pd.adrLED1()->explosion(3, "white", 9);
 pd.adrLED1()->explosion(35, "red", 9);
 pd.adrLED1()->explosion(27, "blue", 9);
 pd.adrLED1()->explosion(3, "red", 9);
 pd.adrLED1()->explosion(35, "white", 9);
 pd.adrLED1()->explosion(27, "red", 9);
 pd.adrLED1()->explosion(3, "blue", 9);
 pd.adrLED1()->explosion(35, "red", 9);
 pd.adrLED1()->explosion(27, "white", 9);
 pd.adrLED1()->explosion(3, "red", 9);
 pd.adrLED1()->explosion(35, "blue", 9);
 pd.adrLED1()->bullet2Color("blue", "white", 20, 5, -1);
 pd.adrLED1()->bullet2Color("green", "mint", 20, 5, 1);
 pd.adrLED1()->bullet2Color("blue", "white", 20, 5, -1);
 pd.adrLED1()->bullet2Color("green", "mint", 20, 5, 1);
 pd.adrLED1()->bullet2Color("blue", "white", 20, 5, -1);
 pd.adrLED1()->bullet2Color("green", "mint", 20, 5, 1);
  }

