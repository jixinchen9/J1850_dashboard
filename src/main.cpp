#include "main.h"

//Global Variables

j1850 vpw_inst;                 //create obj of class j1850
byte rx_buf[MAX_MESSAGE_SIZE];  //buffer for RX messages

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial);       //stick in this loop while serial init works

  Serial.println("Serial init done.");

  vpw_inst.init(J1850_VPW_RX, J1850P_TX, true);

  Serial.println("VPW init done.");

  vpw_inst.easy_send(6, 0x14 , 0x12 ,0x10 , 0xFF , 0x01 , 0x00);
}

void loop() {
  if (vpw_inst.accept (rx_buf)){
    vpw_inst.easy_send(4, 0x01, 0x01, 0x01, 0xFF); //reply if data received
  }
}

// put function definitions here:
