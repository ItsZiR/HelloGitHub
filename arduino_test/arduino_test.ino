#include <IRremote.h>
//設定紅外線接收頭的PIN腳
int RECV_PIN = 7;
IRrecv recv(RECV_PIN);

//接收訊號後會把結果存在results
decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  recv.enableIRIn(); // 開始接收訊號！
  Serial.println("Enabled IRin");
}

void loop() {
  /*
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); //接收訊號，以16進位型式輸出到監控視窗
    irrecv.resume(); // 接著接收下一個訊號
  }
  */
  if (recv.decode(&results)) {
    Serial.print("get:");
    Serial.println(results.value);
    Serial.println(results.value, HEX);
    delay(100);
    recv.resume();
  }
}
//1