/*
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
*/
const int buzzer = 8;
int freq[] = {131,139,147,156,165,175,185,196,208,220,233,247,262,277,294,311,330,349,370,392,415,440,466,494,0};

int melody[] = {10,13,16,17,25,9,10,13,15,13,16,16,17,25,20,19,18,17,15,13,12,11,12,13,15,16,17,5,10,13,16,17,25,9,10,13,15,13,16,16,17,25,20,19,18,16,17,18,19,20,21,21,22,22,24,25};
//(10,13,16,17,25,9,10,13,15,13,16,16,17,25)|(,20,19,18,17,15,13,12,11,12,13,15,16,17,5)|(,10,13,16,17,25,9,10,13,15,13,16,16,17,25)|(,20,19,18,16,17,18,19,20,21,21,22,22,24,25)
float beat[] = {2,2,2,0.5,0.5,1,1,1,1,1,1,0.5,1.5,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,0.5,0.5,1,1,1,1,1,1,0.5,1.5,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2};
//(2,2,2,0.5,0.5,1,1,1,1,1,1,0.5,1.5,1)|(,1,1,1,1,1,1,1,1,1,1,1,1,2,2)|(,2,2,2,0.5,0.5,1,1,1,1,1,1,0.5,1.5,1)|(,1,1,1,1,1,1,1,1,1,1,1,1,2,2)

int tempPitch = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int i = 0 ; i < 56 ; i++){

    tone(buzzer, freq[melody[i]-1]);
    delay(beat[i]*1000/6);

    noTone(buzzer);
    if(melody[i] == tempPitch){
      delay(1);
    }
    else{
      delay(0);
    }
    tempPitch = melody[i];
  }
}
