/*
 * MiFare Library 1K Card Reading Sketch
 * Ankit Daftery 2013
 * Reads Sector 5,Block 1 from a MiFare 1K Card
 * Generates Keyboard events on the Leonardo if the data read from the card matches specified string
 */


#include "MiFare.h"

MiFare mf;

void setup()
{
  Keyboard.begin();
  Serial.begin(19200);
  Serial1.begin(19200);
  while (!Serial) {
    ; // wait for Serial1 port to connect. Needed for Leonardo only
  }
  int key[6]= {
    0xff,0xff,0xff,0xff,0xff,0xff              };
  mf.load_key(0x05,key);

}


void loop()
{
  mf.get_tag();
  String response = mf.get_response(); 
  mf.display_response(response);
  mf.read(0x05,0x01);
  response = mf.get_response();
  if(response.startsWith("WIFI")) {
    Keyboard.write('W');
  }
  else if(response.startsWith("CAM")) {
    Keyboard.write('C');
  }
  else Serial.println(response);
}






