#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "114514";
int pwDigit;
String userEnter;

void setup(){
  Serial.begin(9600);
  pwDigit = 0;
  userEnter = "";
  Serial.println("I'm ready.");
  Serial.print("Please enter the password : ");
}
  
void loop(){
  char key = keypad.getKey();// Read the key
  
  // Print if key pressed
  if (key){
    Serial.print(key);
    userEnter += key;
    pwDigit ++;
    if(pwDigit == password.length()){
      if(userEnter == password){
        Serial.println("\nWelcome!");
      }
      else{
        Serial.println("\nIncorrect Password.");
      }
      pwDigit = 0;
      userEnter = "";
      Serial.print("Please enter the password : ");
    }
  }
}