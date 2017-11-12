# E32-TTL-100 Example
Simple implementation for a E32-TTL-100 ReceiveMsg/SendMsg with a Arduino Nano/UNO.

1. Download Arduino IDE 1.8.5.
2. Download and compile E32-TTL-100.ino

| UNO/NANO(5V mode) |           | E32-TTL-100 |
| ------ |:----------------------- |:----:|
| D7     | <---------------------> | M0   |
| D8     | <---------------------> | M1   |
| A0     | <---------------------> | AUX  |
| D10(Rx)| <---> 4.7k Ohm <--->    | Tx   |
| D11(Tx)| <---> 4.7k Ohm <--->    | Rx   |

need series a 4.7k Ohm resistor between Rx-Tx.



![alt text](https://github.com/Bob0505/E32-TTL-100/raw/master/Module.jpg)
