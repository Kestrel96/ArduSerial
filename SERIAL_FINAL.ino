#include <Servo.h>


Servo MOT[6];

String RPiString = "";
boolean RPiStringComplete = false;

void setup() {


  Serial.begin(115200);
  //wybrać numery pinów i attach


}




//BA1000A2342A1500A1600A1700A1808EZ

void loop() {

  if ( RPiStringComplete == true) {
    Serial.println(RPiString[0]);
    Serial.println(RPiStringComplete);
    
    if (RPiString[0] == 'B') {
      Serial.println(RPiString);

      int l = 1;
      int tmp = 0;

      for (int i = 0; i < 6; i++) {

        Serial.print("i: ");
        Serial.println(i);
        Serial.println();

        while (RPiString[l + 1] != 'A') {
          
          
          
//          Serial.print("l ");
//          Serial.println(RPiString[l ]);
          l++;
          if (RPiString[l] == 'E') {
            break;
          }
          tmp = tmp * 10;
          tmp = tmp + RPiString[l] - 48;
//          Serial.print("tmp: ");
//          Serial.println(tmp);
//          Serial.print("l: ");
//          Serial.println(l);
//          Serial.println();



        }
        Serial.print("tmp= ");
        Serial.print(tmp);
        Serial.println();
        MOT[i].writeMicroseconds(tmp);       
        l++;
        tmp=0;

      }
      RPiStringComplete = false;
      RPiString = "";
    }
    RPiStringComplete = false;
      RPiString = "";
    

  }
}





void serialEvent() {

  Serial.print("serial\n");

  while (Serial.available()) {

    char inChar = (char)Serial.read();
    RPiString += inChar;


    if (inChar == '\n') {
      RPiStringComplete = true;
    }
  }
}
