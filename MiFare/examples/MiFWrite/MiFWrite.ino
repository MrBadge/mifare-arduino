/*
 * MiFare Library 1K Card Writing Sketch
 * Ankit Daftery 2013
 * Writes Sector 5,Block 1 to a MiFare 1K Card
 * Complements the MiFRead sketch
 * Connect a switch to Digital Pin 7 to write only when switch is pressed
 */

#include "MiFare.h"

MiFare mf;

void setup()
{
  pinMode(7,INPUT_PULLUP);
  Serial.begin(19200);
  Serial1.begin(19200);
  while (!Serial) {
    ; // wait for Serial1 port to connect. Needed for Leonardo only
  }
  int key[6]= {
    0xff,0xff,0xff,0xff,0xff,0xff                }; // Default access key for MiFare Cards
  mf.load_key(0x05,key);

}


void loop()
{
  if(digitalRead(7)==LOW) {
    mf.get_tag();
    String response=mf.get_response();
    mf.display_response(response);
    delay(2000);
    mf.write(0x05,0x01,"CAMERA          "); // Write data in blocks of 16 bytes to avoid junk
    response=mf.get_response();
    mf.display_response(response);
    delay(2000);
  }
}





