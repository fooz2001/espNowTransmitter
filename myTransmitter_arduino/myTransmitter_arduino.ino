#include <LiquidCrystal.h>

String msg;
char c;

const int rs = 12, en = 13, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int fbJoyR = A1;
const int lrJoyR = A0;

const int fbJoyL = A2;
const int lrJoyL = A3;

const int lButton = 3;
const int rButton = 2;

int fbJoyLValue, lrJoyLValue;
int fbJoyRValue, lrJoyRValue;

unsigned long current_time;
unsigned long previous_time = millis();
float delay_time = 50;

unsigned long click_time;

byte robot[] = {
  B11111,
  B11111,
  B10101,
  B11111,
  B11111,
  B01110,
  B01010,
  B11011
};

byte check[] = {
  B00000,
  B00000,
  B00001,
  B00011,
  B10110,
  B11100,
  B01000,
  B00000
};

byte cross[] = {
  B00000,
  B00000,
  B10001,
  B01010,
  B00100,
  B01010,
  B10001,
  B00000
};

void setup() {
  lcd.begin(16, 2);
  Serial.begin(115200);
  
  pinMode(lButton, OUTPUT);
  pinMode(rButton, OUTPUT);

  lcd.createChar(0, robot);
  lcd.createChar(1, check);
  lcd.createChar(2, cross);

  lcd.setCursor(4, 0);
  lcd.print("BY ALFooZ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(13, 1);
  lcd.print("mFm");
  
  lcd.setCursor(10, 0);
  lcd.print("R");
  lcd.setCursor(12, 0);
  lcd.print("D");
  lcd.setCursor(14, 0);
  lcd.print("S");

  lcd.setCursor(0, 0);
  lcd.print("Mode:");
  
  lcd.setCursor(0, 1);
  lcd.print("B=");
}

void loop() {

  while (Serial.available() > 0)
    {
      c=Serial.read();
      if(c=='\n'){break;}
      else{msg+=c;}
    }
    if(c=='\n'){
      getAlarms(msg);
      Serial.println(msg);
      c=0;
      msg="";
    }

  current_time = millis();
  
  if(current_time - previous_time > delay_time){
    
    sendValues();
    previous_time = current_time;
  }
//  buttonEvents();
  
}
