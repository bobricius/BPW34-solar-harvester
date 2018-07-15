
#include <Manchester.h>

/*

  Manchester Transmitter example
  
  In this example transmitter will send 10 bytes array  per transmittion

  try different speeds using this constants, your maximum possible speed will 
  depend on various factors like transmitter type, distance, microcontroller speed, ...

  MAN_300 0
  MAN_600 1
  MAN_1200 2
  MAN_2400 3
  MAN_4800 4
  MAN_9600 5
  MAN_19200 6
  MAN_38400 7

*/
//Pin Definitions

#define LED0 0
#define LED1 1
#define LED2 2
#define TXPWR 4
#define TX_PIN  3  //pin where your transmitter is connected

//
//#define TX_PIN  5  //pin where your transmitter is connected
//#define LED_PIN 13 //pin for blinking LED

uint8_t moo = 1; //last led status
uint8_t data[20] = {11, '1','2', '3', '4', '5', '6', '7', '8', '9','1','2','3','4','5','6','7','8','9'};

void setup() 
{
//  pinMode(LED0, OUTPUT);
//  digitalWrite(LED0,LOW);
//  pinMode(LED1, OUTPUT);
//  digitalWrite(LED1,LOW);
//  pinMode(LED2, OUTPUT);
//  digitalWrite(LED2,LOW);
   pinMode(TXPWR, OUTPUT);
//  digitalWrite(TXPWR,LOW);

  man.workAround1MhzTinyCore(1); //add this in order for transmitter to work with 1Mhz Attiny85/84
  man.setupTransmit(TX_PIN, MAN_1200);
}


uint8_t datalength=2;   //at least two data
void loop() 
{

  data[0] = datalength;
  digitalWrite(TXPWR,HIGH);
  man.transmitArray(2, data);
  digitalWrite(TXPWR,LOW);
  moo = ++moo % 2;



  delay(1000);
  datalength++;
  if(datalength>18) datalength=2;
}
