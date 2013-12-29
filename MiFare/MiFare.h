/*
  MiFare - Library for controlling a MiFare 13.56 MhZ reader/writer
  Created by Ankit Daftery, December 28, 2013
*/


#ifndef MIFARE_H
#define MIFARE_H

#include <Arduino.h>

class MiFare {
public:
  void display_response(String);
  void load_key(int sector, int * key) ;
  void clear_key(void);
  void read(int sector,int block);
  void send_command(char *);
  void send_command(int);
  void send_endline(void);
  void get_tag(void);
  String get_response(void);
  void write(int,int,char *);
};
#endif



