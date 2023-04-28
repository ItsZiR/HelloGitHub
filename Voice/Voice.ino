#include <ld3320.h>
#include <LiquidCrystal_I2C.h> 
#include <Wire.h> 

VoiceRecognition Voice;//聲明一個語音辨識對象
LiquidCrystal_I2C lcd(0x27,16,2);  //設定LCD位置0x27,設定LCD大小為16*2

bool pw1, pw2, pw3, pw4; //密碼驗證

void setup(){
  pw1 = pw2 = pw3 = pw4 = false;

  Serial.begin(9600);
  Voice.init();//初始化VoiceRecognition模組 

  //設定關鍵字, 漢語拼音, 最多50個
  Voice.addCommand("guang meng",0);
  Voice.addCommand("kai meng",1);
  Voice.addCommand("ce shi",2);
  Voice.addCommand("hei se gao ji che",3);
  Voice.addCommand("wa lei wa lei wa nuo zou mu",4);
  Voice.addCommand("na na cu no na ge ki wo",5);
  Voice.addCommand("wa lei wa lei wa ou bo ei tie yi lu",6);
  Voice.addCommand("jie li ko nuo ko suo ku wo",7);

  Voice.start();//開始辨識
  Serial.println("I'm Ready.");

  //初始化LCD 
  lcd.init(); 
  lcd.backlight(); //開啟背光
  lcd.print("Tai Ki Chuu"); //只能顯示英數
}
void loop() {
  //判斷辨識
  switch(Voice.read()){
    case 0:
    Serial.println("Close the door.");
    lcd.clear();
    lcd.setCursor(0, 0); // (colum, row)從第1排的第1個位置開始顯示
    lcd.print("Close the door.");
    break;

    case 1:
    Serial.println("Open the door.");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Open the door.");
    break;

    case 2:
    pw1 = pw2 = pw3 = pw4 = false;
    Serial.println("Testing");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Testing");
    break;

    case 3:
    Serial.println("114514");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("114514");
    break;

    case 4:
    Serial.println("我々は望む");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wareware Wa");
    lcd.setCursor(0, 1); // (colum, row)從第2排的第1個位置開始顯示
    lcd.print("Nozomu");
    pw1 = true;
    break;

    case 5:
    Serial.println("七つの嘆きを");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nanatsu no");
    lcd.setCursor(0, 1);
    lcd.print("Nageki wo");
    pw2 = true;
    break;

    case 6:
    Serial.println("我々は覚えている");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wareware Wa");
    lcd.setCursor(0, 1);
    lcd.print("OboeTeiru");
    pw3 = true;
    break;

    case 7:
    Serial.println("ジェリコの古則を");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Jericho no");
    lcd.setCursor(0, 1);
    lcd.print("Kosoku wo");
    pw4 = true;
    break;

    default: //如果都不是
    break;
  }

  if(pw1){
    if(pw2){
      if(pw3){
        if(pw4){
          delay(1000);
          lcd.clear();
          delay(200);
          lcd.setCursor(0, 0);
          lcd.print("Validated! Zir");
          delay(200);
          lcd.setCursor(0, 1);
          lcd.print("Welcome back.");
          delay(5000);
          pw1 = pw2 = pw3 = pw4 = false;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Tai Ki Chuu...");
        }
      }
    }
  }
}
