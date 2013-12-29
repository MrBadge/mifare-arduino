/*
  MiFare - Library for controlling a MiFare 13.56 MhZ reader/writer
  Created by Ankit Daftery, December 28, 2013
*/


#include "MiFare.h"

void MiFare::load_key(int sector, int * key) {
  if(sector <= 0x0f) {  // Only 16 sectors in 1K card
    send_command("DTLK");
    send_command(sector);
    for(int i=0;i<6;i++)  send_command(key[i]);
    send_endline();
  }
}

void MiFare::clear_key() {
    send_command("DTCK");
    send_endline();
    delay(50);
}

void MiFare::send_command(char *cmd) {

  for (;*cmd != '\0' ; ++cmd) {
    Serial1.write(*cmd);
  }
}

void MiFare::send_command(int param) {
  Serial1.write(param);
}

void MiFare::send_endline() {
  Serial1.write(0x0A);
  Serial1.write(0x0D);
}

void MiFare::get_tag(void) {
  send_command("DTGU");
  send_endline();
  delay(50);
}

String MiFare::get_response() {
  String response="";
  while (Serial1.available()) {
    char inChar = (char)Serial1.read();
    if(inChar == 0x03) response += ',';
    else if(inChar != 0x02) response +=  inChar;
  }
  return response;
}

void MiFare::display_response(String response) {
    Serial.print(response);
    Serial.println();
}

void MiFare::read(int sector,int block) {
  send_command("DTRD");
  send_command(sector);
  send_command(block);
  send_endline();
  delay(50);
}

void MiFare::write(int sector,int block,char * data) {
  send_command("DTWR");
  send_command(sector);
  send_command(block);
  // TODO: Add padding for 16 byte size?
  send_command(data);
  send_endline();
  delay(50);
}
