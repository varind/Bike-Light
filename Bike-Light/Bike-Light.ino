/*
written by varind in 2012
this code is public domain, enjoy!
 */

const int buttonPin = 12;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
int lastButtonState = 0;     // previous state of the button
int programNumber = 7;
int programCount = 8;



int delayTime;
int redValue;
int greenValue;
int blueValue;
int fadeDirection=0;
int programDelay=0;
float fadeSpeed;
int formula;
float x=0;
int y=0;
int cycle;
int rgbSpeed;
int delayT;
float redColor;
float greenColor;
float blueColor;
int faderOne;
int value1;
int value2;
int value3;
int value4;

void setup()  {
  pinMode(buttonPin, INPUT);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(13, OUTPUT);
  digitalWrite(13, 1);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);

//  Serial.begin(9600);
}





void loop(){


//    Serial.println(programNumber);
//    Serial.println(buttonState);
    if (programNumber > programCount){
      programNumber=1;
    }
buttonTest();
if (programNumber ==1){
  flashRGB(1);
};
if (programNumber ==2){
  chaseRedGreen(1,20);
};
if (programNumber ==3){
  chaseRedBlue(1,20);
};
if (programNumber ==4){
  chaseBlueGreen(1,20);
}
if (programNumber ==5){
  chaseBlueRed(1,20);
};
if (programNumber ==6){
  chaseGreenBlue(1,20);
};
if (programNumber ==7){
  chaseGreenRed(1,20);
};
if (programNumber ==8){
    fadeEach();
};

//// various patterns that can be called upon ///

//  flashRGB(20);
//  chaseRedGreen(2,15);
//  chaseRedBlue(2,15);
//  chaseRedGreen(2,15);
//  chaseRedBlue(2,15);
//  chaseBlueGreen(2,15);
//  chaseBlueRed(2,15);
//  chaseBlueGreen(2,15);
//  chaseBlueRed(2,15);
//  chaseGreenBlue(2,15);
//  chaseGreenRed(2,15);
//  chaseGreenBlue(2,15);
//  chaseGreenRed(2,15);
//  colorSpin();
//  fadeEverything();
// chase2();
//  fadeEach();
//  flashRedGreen(5,20);
//  chaseWhiteBlue(10,20);
}


void buttonTest(){

    buttonState = digitalRead(buttonPin);
 //   Serial.println(buttonState);

  if (buttonState != lastButtonState){
    if (buttonState == 1){
      programNumber=programNumber++;
      }

    lastButtonState = buttonState;
  }

}

void colorSpin(){
  y=0;
  while (y<3){
    delayT=20;
    b1(1);
    delay(delayT*5);
    b2(1);
    delay(delayT*5);
    b3(1);
    delay(delayT*5);
    b4(1);
    delay(delayT*5);

    g1(1);
    delay(delayT*5);
    g2(1);
    delay(delayT*5);
    g3(1);
    delay(delayT*5);
    g4(1);
    delay(delayT*5);

    r1(1);
    delay(delayT*5);
    r2(1);
    delay(delayT*5);
    r3(1);
    delay(delayT*5);
    r4(1);
    delay(delayT*5);
    y=y++;
  }
}


void fadeEverything(){
  x=4.71;
  fadeSpeed=0;
  while (x<=1000)
  {
    fadeSpeed = 100*sin(x/1000)+100;
    value1 = 127*sin(x/fadeSpeed)+127;
    value2 = 127*sin(x/fadeSpeed*5)+127;
    value3 = 127*sin(x/fadeSpeed*2)+127;
    value4 = 127*cos(x/fadeSpeed*2)+127;
    superFade(1,0,0,0,value1,0,0);
    superFade(0,1,0,0,0,value2,0);
    superFade(0,0,1,0,value3,0,0);
    superFade(0,0,0,1,0,0,value4);
    x=x++;
  }
  x=0;
  while (x<=1000){
       fadeSpeed = 100*sin(x/1000)+100;
    value1 = 127*sin(x/fadeSpeed)+127;
    value2 = 127*sin(x/fadeSpeed*5)+127;
    value3 = 127*sin(x/fadeSpeed*2)+127;
    value4 = 127*cos(x/fadeSpeed*2)+127;
    superFade(1,0,0,0,0,value1,0);
    superFade(0,1,0,0,0,0,value2);
    superFade(0,0,1,0,0,value3,0);
    superFade(0,0,0,1,value4,0,0);


  x=x++;
  }

}




void fadeEach(){
  y=0;
  while (y<=0){
    fadeRed(.04);
    fadeGreen(.04);
    fadeBlue(.04);
    y=y+1;
  }

}



void chase2(){
  y=0;
  while (y<3){
    x=0;
    while (x <= delayT){
      superFade(0,1,1,1,255,0,0);
      superFade(1,0,0,0,0,0,255);
      x=x++;
    }
    x=0;
    while (x <= delayT){
      superFade(0,0,1,1,255,0,0);
      superFade(1,1,0,0,0,0,255);
      x=x++;
    }
    x=0;
    while (x <= delayT){
      superFade(0,0,0,1,255,0,0);
      superFade(1,1,1,0,0,0,255);
      x=x++;
    }
    x=0;
    while (x <= delayT){
      superFade(1,1,1,1,0,0,255);
      x=x++;
    }


    x=0;
    while (x <= delayT){
      superFade(0,1,1,1,0,0,255);
      superFade(1,0,0,0,0,255,0);
      x=x++;
    }
    x=0;
    while (x <= delayT){
      superFade(0,0,1,1,0,0,255);
      superFade(1,1,0,0,0,255,0);
      x=x++;
    }
    x=0;
    while (x <= delayT){
      superFade(0,0,0,1,0,0,255);
      superFade(1,1,1,0,0,255,0);
      x=x++;
    }
    x=0;
    while (x <= delayT){
      superFade(1,1,1,1,0,255,0);
      x=x++;
    }



    x=0;
    while (x <= delayT){
      superFade(0,1,1,1,0,255,0);
      superFade(1,0,0,0,255,0,0);
      x=x++;
    }

    x=0;
    while (x <= delayT){
      superFade(0,0,1,1,0,255,0);
      superFade(1,1,0,0,255,0,0);
      x=x++;
    }

    x=0;
    while (x <= delayT){
      superFade(0,0,0,1,0,255,0);
      superFade(1,1,1,0,255,0,0);
      x=x++;
    }

    x=0;
    while (x <= delayT){
      superFade(1,1,1,1,255,0,0);
      x=x++;
    }

    y++;
  }
}


void superFade(int ledOne,int ledTwo, int ledThree, int ledFour,float redColor,float greenColor,float blueColor){

  analogWrite(11, LOW);
  analogWrite(11, redColor);
  analogWrite(10, LOW);
  analogWrite(10, greenColor);
  analogWrite(9, LOW);
  analogWrite(9, blueColor);


  if (ledOne==1){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }
  if (ledTwo==1){
    digitalWrite(3, HIGH);
  }
  else{
    digitalWrite(3, LOW);
  }

  if (ledThree==1){
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4, LOW);
  }

  if (ledFour==1){
    digitalWrite(5, HIGH);
  }
  else{
    digitalWrite(5, LOW);
  }
  delay(2);
}

void r1(int cycles){
  x=0;
  while (x<=cycles){
    superFade(1,0,0,0,255,0,0);
    x++;
  }
}

void g1(int cycles){
  x=0;
  while (x<=cycles){
    superFade(1,0,0,0,0,255,0);
    x++;
  }
}

void b1(int cycles){
  x=0;
  while (x<=cycles){
    superFade(1,0,0,0,0,0,255);
    x++;
  }
}

void r2(int cycles){
  x=0;
  while (x<=cycles){
    superFade(0,1,0,0,255,0,0);
    x++;
  }
}


void g2(int cycles){
  x=0;
  while (x<=cycles){
    superFade(0,1,0,0,0,255,0);
    x++;
  }
}
void b2(int cycles){
  x=0;
  while (x<=cycles){
    superFade(0,1,0,0,0,0,255);
    x++;
  }
}

void r3(int cycles){
  x=0;
  while (x<=cycles){
    superFade(0,0,1,0,255,0,0);
    x++;
  }
}

void g3(int cycles){
  x=0;
  while (x<=cycles){
    superFade(0,0,1,0,0,255,0);
    x++;
  }
}

void b3(int cycles){
  x=0;
  while (x<=cycles){
    superFade(0,0,1,0,0,0,255);
    x++;
  }
}



void r4(int cycles){
  x=0;
  while (x<=cycles){
    superFade(0,0,0,1,255,0,0);
    x++;
  }
}

void g4(int cycles){
  x=0;
  while (x<=cycles){
    superFade(0,0,0,1,0,255,0);
    x++;
  }
}


void b4(int cycles){
  x=0;
  while (x<=cycles){
    superFade(0,0,0,1,0,0,255);
    x++;
  }
}






void color (int redValue,int greenValue,int blueValue){
  analogWrite(11, blueValue);
  analogWrite(10, greenValue);
  analogWrite(9, redValue);
}


void red (){
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 255);
}

void green (){
  analogWrite(9, 0);
  analogWrite(10, 255);
  analogWrite(11, 0);
}

void blue (){
  analogWrite(9, 255);
  analogWrite(10, 0);
  analogWrite(11, 0);
}

void led1 (int delayTime){
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay (delayTime);
}
void led2(int delayTime){
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  delay (delayTime);
}
void led3(int delayTime){
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  digitalWrite(5, LOW);
  delay (delayTime);
}
void led4(int delayTime){
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  delay (delayTime);
}
void off(){

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
}



void fadeRed(float fadeSpeed){
  x=4.71;
  while (x<=10.99)
  {
    led1(1);
    color(127*sin(x)+127,0,0);
    led2(1);
    color(127*sin(x)+127,0,0);
    led3(1);
    color(127*sin(x)+127,0,0);
    led4(1);
    color(127*sin(x)+127,0,0);
    x=x+fadeSpeed;
  }
}

void fadeGreen(float fadeSpeed){
  x=4.71;
  while (x<=10.99)
  {
    led1(1);
    color(0,127*sin(x)+127,0);
    led2(1);
    color(0,127*sin(x)+127,0);
    led3(1);
    color(0,127*sin(x)+127,0);
    led4(1);
    color(0,127*sin(x)+127,0);
    x=x+fadeSpeed;
  }
}

void fadeBlue(float fadeSpeed){
  x=4.71;
  while (x<=10.99)
  {
    led1(1);
    color(0,0,127*sin(x)+127);
    led2(1);
    color(0,0,127*sin(x)+127);
    led3(1);
    color(0,0,127*sin(x)+127);
    led4(1);
    color(0,0,127*sin(x)+127);
    x=x+fadeSpeed;
  }
}


void flashRGB(int repeat){

  cycle =0;
  while (cycle <= repeat){
    x=1;
    rgbSpeed=20;
    while (x<=rgbSpeed){
      led1(1);
      color(255,0,0);
      led2(1);
      color(255,0,0);
      led3(1);
      color(255,0,0);
      led4(1);
      color(255,0,0);
      x=x+1;
    }
    x=1;
    while (x<=rgbSpeed){
      led1(1);
      color(0,255,0);
      led2(1);
      color(0,255,0);
      led3(1);
      color(0,255,0);
      led4(1);
      color(0,255,0);
      x=x+1;
    }
    x=1;
    while (x<=rgbSpeed){
      led1(1);
      color(0,0,255);
      led2(1);
      color(0,0,255);
      led3(1);
      color(0,0,255);
      led4(1);
      color(0,0,255);
      x=x+1;
    }
    cycle=cycle+1;
  }
}


void flashRedGreen(int repeat, int rgSpeed){
  x=1;
  cycle =0;
  while (cycle <= repeat){
    while (x<=rgSpeed){
      led1(1);
      color(0,255,0);
      led2(1);
      color(255,0,0);
      led3(1);
      color(0,255,0);
      led4(1);
      color(255,0,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(255,0,0);
      led2(1);
      color(0,255,0);
      led3(1);
      color(255,0,0);
      led4(1);
      color(0,255,0);
      x=x+1;
    }
    x=1;

    cycle=cycle+1;
  }
}


// chase using color routine

void chaseRedGreen(int repeat, int rgSpeed){
  x=1;
  cycle =0;
  while (cycle <= repeat){
    while (x<=rgSpeed){
      led1(1);
      color(0,255,0);
      led2(1);
      color(255,0,0);
      led3(1);
      color(255,0,0);
      led4(1);
      color(255,0,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(255,0,0);
      led2(1);
      color(0,255,0);
      led3(1);
      color(255,0,0);
      led4(1);
      color(255,0,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(255,0,0);
      led2(1);
      color(255,0,0);
      led3(1);
      color(0,255,0);
      led4(1);
      color(255,0,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(255,0,0);
      led2(1);
      color(255,0,0);
      led3(1);
      color(255,0,0);
      led4(1);
      color(0,255,0);
      x=x+1;
    }
    x=1;
    cycle=cycle+1;
  }
}

void chaseRedBlue(int repeat, int rgSpeed){
  x=1;
  cycle =0;
  while (cycle <= repeat){
    while (x<=rgSpeed){
      led1(1);
      color(0,0,255);
      led2(1);
      color(255,0,0);
      led3(1);
      color(255,0,0);
      led4(1);
      color(255,0,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(255,0,0);
      led2(1);
      color(0,0,255);
      led3(1);
      color(255,0,0);
      led4(1);
      color(255,0,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(255,0,0);
      led2(1);
      color(255,0,0);
      led3(1);
      color(0,0,255);
      led4(1);
      color(255,0,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(255,0,0);
      led2(1);
      color(255,0,0);
      led3(1);
      color(255,0,0);
      led4(1);
      color(0,0,255);
      x=x+1;
    }
    x=1;
    cycle=cycle+1;
  }
}




void chaseBlueGreen(int repeat, int rgSpeed){
  x=1;
  cycle =0;
  while (cycle <= repeat){
    while (x<=rgSpeed){
      led1(1);
      color(0,255,0);
      led2(1);
      color(0,0,255);
      led3(1);
      color(0,0,255);
      led4(1);
      color(0,0,255);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,0,255);
      led2(1);
      color(0,255,0);
      led3(1);
      color(0,0,255);
      led4(1);
      color(0,0,255);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,0,255);
      led2(1);
      color(0,0,255);
      led3(1);
      color(0,255,0);
      led4(1);
      color(0,0,255);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,0,255);
      led2(1);
      color(0,0,255);
      led3(1);
      color(0,0,255);
      led4(1);
      color(0,255,0);
      x=x+1;
    }
    x=1;
    cycle=cycle+1;
  }
}

void chaseBlueRed(int repeat, int rgSpeed){
  x=1;
  cycle =0;
  while (cycle <= repeat){
    while (x<=rgSpeed){
      led1(1);
      color(255,0,0);
      led2(1);
      color(0,0,255);
      led3(1);
      color(0,0,255);
      led4(1);
      color(0,0,255);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,0,255);
      led2(1);
      color(255,0,0);
      led3(1);
      color(0,0,255);
      led4(1);
      color(0,0,255);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,0,255);
      led2(1);
      color(0,0,255);
      led3(1);
      color(255,0,0);
      led4(1);
      color(0,0,255);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,0,255);
      led2(1);
      color(0,0,255);
      led3(1);
      color(0,0,255);
      led4(1);
      color(255,0,0);
      x=x+1;
    }
    x=1;
    cycle=cycle+1;
  }
}

void chaseGreenBlue(int repeat, int rgSpeed){
  x=1;
  cycle =0;
  while (cycle <= repeat){
    while (x<=rgSpeed){
      led1(1);
      color(0,0,255);
      led2(1);
      color(0,255,0);
      led3(1);
      color(0,255,0);
      led4(1);
      color(0,255,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,255,0);
      led2(1);
      color(0,0,255);
      led3(1);
      color(0,255,0);
      led4(1);
      color(0,255,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,255,0);
      led2(1);
      color(0,255,0);
      led3(1);
      color(0,0,255);
      led4(1);
      color(0,255,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,255,0);
      led2(1);
      color(0,255,0);
      led3(1);
      color(0,255,0);
      led4(1);
      color(0,0,255);
      x=x+1;
    }
    x=1;
    cycle=cycle+1;
  }
}

void chaseGreenRed(int repeat, int rgSpeed){
  x=1;
  cycle =0;
  while (cycle <= repeat){
    while (x<=rgSpeed){
      led1(1);
      color(255,0,0);
      led2(1);
      color(0,255,0);
      led3(1);
      color(0,255,0);
      led4(1);
      color(0,255,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,255,0);
      led2(1);
      color(255,0,0);
      led3(1);
      color(0,255,0);
      led4(1);
      color(0,255,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,255,0);
      led2(1);
      color(0,255,0);
      led3(1);
      color(255,0,0);
      led4(1);
      color(0,255,0);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(0,255,0);
      led2(1);
      color(0,255,0);
      led3(1);
      color(0,255,0);
      led4(1);
      color(255,0,0);
      x=x+1;
    }
    x=1;
    cycle=cycle+1;
  }
}





void chaseWhiteBlue(int repeat, int rgSpeed){
  x=1;
  cycle =0;
  while (cycle <= repeat){
    while (x<=rgSpeed){
      led1(1);
      color(0,0,255);
      led2(1);
      color(75,75,75);
      led3(1);
      color(75,75,75);
      led4(1);
      color(75,75,75);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(75,75,75);
      led2(1);
      color(0,0,255);
      led3(1);
      color(75,75,75);
      led4(1);
      color(75,75,75);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(75,75,75);
      led2(1);
      color(75,75,75);
      led3(1);
      color(0,0,255);
      led4(1);
      color(75,75,75);
      x=x+1;
    }
    x=1;
    while (x<=rgSpeed){
      led1(1);
      color(75,75,75);
      led2(1);
      color(75,75,75);
      led3(1);
      color(75,75,75);
      led4(1);
      color(0,0,255);
      x=x+1;
    }
    x=1;
    cycle=cycle+1;
  }
}
