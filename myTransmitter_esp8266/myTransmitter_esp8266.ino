
#include <espnow.h>
#include <ESP8266WiFi.h>

String msg;
char c;

int counter = 0;

typedef struct esp_now_peer_info{
  
  u8 peer_addr[6];
  uint8_t channel;
  uint8_t encrypt;
}esp_now_peer_info_t;

typedef struct Data {
  
  int fbJoyLValue;
  int lrJoyLValue;
  int fbJoyRValue;
  int lrJoyRValue;

  bool lButton;
  bool rButton;
  
} Data;

esp_now_peer_info_t slave;
Data myData;

#define CHANNEL 9

// callback when data is sent from Master to Slave
esp_now_send_cb_t OnDataSent([](uint8_t *mac_addr, uint8_t status){
//  Serial.print("Last Packet Send Status: ");
  Serial.println(status == 0 ? "$*6" : "$*7");
  if(status == 0){
    counter++;
    }
  else{
    if(counter >= -1)
      counter--;
  }
  
  if(counter >= 5){
      Serial.println("$*5");
      counter = 5;
    }
  if(counter == -1){
    Serial.println("$*4");
  }
});

void setup() {

  slave.peer_addr[0] = 224;
  slave.peer_addr[1] = 226;
  slave.peer_addr[2] = 230;
  slave.peer_addr[3] = 208;
  slave.peer_addr[4] = 44;
  slave.peer_addr[5] = 201;
  
  slave.channel = CHANNEL; // pick a channel
  slave.encrypt = 0;       // no encryption
  
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  delay(2000);
  InitESPNow();
  esp_now_register_send_cb(OnDataSent);

  int addStatus = esp_now_add_peer(slave.peer_addr, ESP_NOW_ROLE_CONTROLLER, CHANNEL, NULL, 0);
      if (addStatus == 0) {
        Serial.println("pairSucsses");
      } else{
        Serial.println("$*1");
      }
      
//  delay(1200);
}

void loop() {
  
  while (Serial.available() > 0)
    {
      c=Serial.read();
      if(c=='\n'){break;}
      else{msg+=c;}
    }
    if(c=='\n'){
      getData(msg);
      c=0;
      msg="";
    }

}
