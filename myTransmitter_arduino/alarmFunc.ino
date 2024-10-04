void espError(){
  lcd.clear();
  lcd.setCursor(0, 0);
  
  while(true){
    lcd.print("esp error");
    delay(100);
    lcd.clear();
    delay(50);
  }
}

void pairError(){
  lcd.clear();
  lcd.setCursor(0, 0);
  
  while(true){
    lcd.print("pair error");
    delay(100);
    lcd.clear();
    delay(50);
  }
}

void sendState(bool s){
  
  if(s){
    lcd.setCursor(15, 0);
    lcd.write((byte)1);
  }
  else{
    lcd.setCursor(15, 0);
    lcd.write((byte)2);
  }
}

void receverState(bool s){
  if(s){
    lcd.setCursor(11, 0);
    lcd.write((byte)0);
  }
  else{
    lcd.setCursor(11, 0);
    lcd.write((byte)2);
  }
}

void delevState(bool s){
  if(s){
    lcd.setCursor(13, 0);
    lcd.write((byte)1);
  }
  else{
    lcd.setCursor(13, 0);
    lcd.write((byte)2);
  }
}
