#include <IRremote.h>

int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  /*if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }*/
  if(IrReceiver.decode())
  {
    Serial.println (IrReceiver.decodedIRData.decodedRawData);
    irrecv.resume();
    delay(100);
  }
}
//1