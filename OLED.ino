#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>

#include<Wire.h>
#include<SPI.h>

#define OLED_MOSI 11 //D1
#define OLED_CLK 12 //D0
#define OLED_DC 9
#define OLED_CS 8
#define OLED_RESET 10

const int buttonPinUp = 2;
const int buttonPinMiddle = 3;
const int buttonPinBottom = 4;
const int buttonPinStart = 5;

int buttonU  = 0;
int buttonM = 0;
int buttonB = 0;
int buttonS = 0;

Adafruit_SSD1306 display(OLED_MOSI,OLED_CLK,OLED_DC,OLED_RESET,OLED_CS);

//int t=0;

unsigned long time;

void setup(){
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC,0x3D);
  display.clearDisplay();
  display.setTextWrap(false);

  
  pinMode(buttonPinUp,INPUT);
  pinMode(buttonPinMiddle,INPUT);
  pinMode(buttonPinBottom,INPUT);

/*  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(35,10);
  display.print("START");
  display.display();
  delay(400);*/
}

int game(int s){
  int x,y;
  display.clearDisplay();
  display.setTextColor(WHITE);
  y=random(3);
  if(y==0){y=-8;}
  else if(y==1){y=4;}
  else {y=16;}
    for(x=0;x<128;x++){
      display.clearDisplay();
      display.setTextColor(WHITE);
      display.setCursor(x,y);
      display.print(".");
      display.setCursor(100,-8);
      display.print("|");
      display.setCursor(100,4);
      display.print("|");  
      display.setCursor(100,16);
      display.print("|");
      display.display();
      if(x<95 || x>105){
        buttonU=digitalRead(buttonPinUp);
        if(buttonU==1){
          s--;
        }
        buttonM=digitalRead(buttonPinMiddle);
        if(buttonM==1){
          s--;
        }
        buttonB=digitalRead(buttonPinBottom);
        if(buttonB==1){
          s--;
      }
      }
      if((x>95 && x<105) && y==-8){
        buttonU=digitalRead(buttonPinUp);
        if(buttonU==1){
          s++;
      }
      buttonM=digitalRead(buttonPinMiddle);
        if(buttonM==1){
          s--;
      }
      buttonB=digitalRead(buttonPinBottom);
        if(buttonB==1){
          s--;
      }
      }
      if((x>95 && x<105) && y==4){
        buttonU=digitalRead(buttonPinUp);
        if(buttonU==1){
          s--;
      }
        buttonM=digitalRead(buttonPinMiddle);
        if(buttonM==1){
          s++;
      }
      buttonB=digitalRead(buttonPinBottom);
        if(buttonB==1){
          s--;
      }
      }
      if((x>95 && x<105) && y==16){
        buttonU=digitalRead(buttonPinUp);
        if(buttonU==1){
          s--;
      }
      buttonM=digitalRead(buttonPinMiddle);
        if(buttonM==1){
          s--;
      }
        buttonB=digitalRead(buttonPinBottom);
        if(buttonB==1){
          s++;
      }
      }
      }
      display.setCursor(0,0);
      display.print(s);
      display.display();
      return(s);
}

int timer(int t){
  delay(1000);
  t++;
  return(t);
}

int s=0;

void loop(){  
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(35,10);
    display.print("START");
    display.display();
    delay(400);
    int t,score=0;
    while((t=timer(t))<10){
    score = game(score);
    }
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0,10);
    display.print("Score:");
    display.print(score);
    display.display();
    delay(600);
  }

