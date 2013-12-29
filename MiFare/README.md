MiFare
======
by Ankit Daftery

## Overview
This library is for communicating with a DT135ICSLI MiFare RFID R/W module.
It has methods to read and write MiFare cards.

The module I used is here : http://www.nskelectronics.com/mifare_rfid_rw_.html

## Download
To download, click the "Download Zip" button to the right. Check that the MiFare folder contains MiFare.cpp and MiFare.h


## Device specific information
Baud Rate : 19200

## Use
This library has been written and tested with an Arduino Leonardo.
Use the appropriate Serial ports available on your board for printing debug information.
The settings are specific to the device I tested with and might vary for your module.
Please refer to the datasheet provided by your OEM provider for specific settings.

## Methods

### void load_key(int sector, int * key) ;
This method loads the key onto the EEPROM to be used for authentication.

### void clear_key(void);
This method clears the key from the EEPROM

### void send_command(char *cmd);
This method sends the specified String as a command to the module. This is a generic function, refer to your datasheet for the specific commands

### void send_command(int param);
This method sends the specified integer to the module, useful when you need to send integer parameters

### void send_endline(void);
This method sends the necessary endline characters to signal end of transmission

### void get_tag(void);
This method returns the ID of the tag. Necessary before performing read / write operations

### String get_response(void);
This method waits for a response from the module and returns it as a string ignoring STX and ETX characters

### void display_response(String response);
This method is just a wrapper to display a string passed to it 

### void read(int sector,int block);
This method sends a command to read the contents of the MiFare card from the specified sector and block

### void write(int sector,int block,char *);
This method writes the specified string to the sector and block on the MiFare card