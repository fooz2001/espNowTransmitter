// Init ESP Now with fallback
void InitESPNow() {
  WiFi.disconnect();
  if (esp_now_init() == 0) {
    Serial.println("ESPNow Init Success");
  }
  else {
    Serial.println("$*0");
    ESP.restart();
  }
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
}

void SendData() {

  int result = esp_now_send(slave.peer_addr, (uint8_t *) &myData, sizeof(myData));
//  Serial.print("Send Status: ");
//  if (result == 0) {
////    Serial.print(sizeof(myData));
//    Serial.println("$SENDS");
//  } else{
//    Serial.println("$SENDE");
//  }
}

void getData(String msg){
  if((msg[0] == '$')and(msg[1] == '9')){
    myData.fbJoyLValue = msg.substring(2, msg.indexOf("a")).toInt();
    myData.lrJoyLValue = msg.substring(msg.indexOf("a") + 1, msg.indexOf("b")).toInt();
    myData.fbJoyRValue = msg.substring(msg.indexOf("b") + 1, msg.indexOf("c")).toInt();
    myData.lrJoyRValue = msg.substring(msg.indexOf("c") + 1, msg.indexOf("d")).toInt();
    myData.lButton = msg.substring(msg.indexOf("d") + 1, msg.indexOf("e")-1).toInt();
    myData.rButton = msg.substring(msg.indexOf("d") + 2, msg.indexOf("e")).toInt();

//    Serial.print("= ");Serial.print(myData.fbJoyLValue);Serial.print(" ");Serial.print(myData.lrJoyLValue);
//    Serial.print("= ");Serial.print(myData.fbJoyRValue);Serial.print(" ");Serial.print(myData.lrJoyRValue);
//    Serial.print("= ");Serial.print(myData.lButton);Serial.print(" ");Serial.println(myData.rButton);

    SendData();
  }
}
