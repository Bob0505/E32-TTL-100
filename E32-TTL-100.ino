/**
 * E32-TTL Transceiver Interface
 *
 * @author Bob Chen
 * @date 1 November 2017
 *
 */
#include <SoftwareSerial.h>

#define M0_PIN      7
#define M1_PIN      8
#define AUX_PIN     A0

/*
 need series a 4.7k Ohm resistor between .
 UNO/NANO(5V mode)             E32-TTL-100
    *--------*                      *------*
    | D7     | <------------------> | M0   |
    | D8     | <------------------> | M1   |
    | A0     | <------------------> | AUX  |
    | D10(Rx)| <---> 4.7k Ohm <---> | Tx   |
    | D11(Tx)| <---> 4.7k Ohm <---> | Rx   |
    *--------*                      *------*
*/
#define SOFT_RX 10
#define SOFT_TX 11

SoftwareSerial softSerial(SOFT_RX, SOFT_TX);  // RX, TX

#define MAX_TX_SIZE 58

// The setup function runs once when you press reset or power the board
void setup()
{
  pinMode(M0_PIN, OUTPUT);
  pinMode(M1_PIN, OUTPUT);
  pinMode(AUX_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  softSerial.begin(9600);

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

#ifdef Device_A
	Serial.println("[10-A] ");
#else
	Serial.println("[10-B] ");
#endif
}

// The loop function runs over and over again forever
void loop()
{

  delay(random(400, 600));
}
