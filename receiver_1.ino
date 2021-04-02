#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
int LED = 3;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(LED, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
}
void loop() {
  if (radio.available()) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
