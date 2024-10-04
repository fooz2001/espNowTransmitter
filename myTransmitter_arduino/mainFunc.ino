void sendValues(){
  //data shape $0000a0000b0000c00000d00e
  
  fbJoyLValue = calibration(analogRead(fbJoyL));
  lrJoyLValue = calibration(analogRead(lrJoyL));

  fbJoyRValue = calibration(analogRead(fbJoyR));
  lrJoyRValue = calibration(analogRead(lrJoyR));
  
  Serial.print("$9");Serial.print(fbJoyLValue);Serial.print("a");Serial.print(lrJoyLValue);Serial.print("b");
                    Serial.print(fbJoyRValue);Serial.print("c");Serial.print(lrJoyRValue);Serial.print("d");
                    Serial.print(digitalRead(lButton));Serial.print(digitalRead(rButton));Serial.println("e");
}

void getAlarms(String msg){
  if((msg[0] == '$')and(msg[1] == '*')){
    if(msg[2] == '0'){//once
      espError();}
    if(msg[2] == '1'){//once
      pairError();}
    if(msg[2] == '2'){//many send error 2
      sendState(0);}
    if(msg[2] == '3'){//many send secsses 3
      sendState(1);}
    if(msg[2] == '4'){//many rec not avelable 4
      receverState(0);}
    if(msg[2] == '5'){//many rec avelable 5
      receverState(1);}
    if(msg[2] == '6'){//many delevery done 6
      delevState(1);}
    if(msg[2] == '7'){//many delevery fail 7
      delevState(0);}
//    Serial.println(msg);
  }
}

int calibration(int v){
  if(v <= 60){
    v = 61;
  }
  else if(v >= 963){
    v = 962;
  }
  else{
    v = v;
  }

  if((v < 963)and(v > 572)){
     v = (v-571)/1.5333;
     return v;
  }
  else if((v > 60)and(v < 452)){
    v = (v-451)/1.5333;
     return v;
  }
  else{
    v = 0;
    return v;
  }
}

void buttonEvents(){
  
  if(digitalRead(rButton)){
    click_time = millis();
    while(digitalRead(rButton)){
      Serial.print("time");Serial.println(click_time);
      if(click_time >= 3000){
        Serial.println("3000");
      }
    }
  }
  else{
    click_time = 0;
  }
  Serial.print("time");Serial.println(click_time);
}
