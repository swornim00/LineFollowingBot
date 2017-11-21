/*
  @Author Swornim Shrestha
  @Author Email <srestaswrnm@gmail.com>
  Nov 21, 2017
*/

// Assigning Variables

int RM_F = 8; //Right Motor Forward
int RM_B = 9; //Right Motor Backward
int LM_F = 10; //Left Motor Forward
int LM_B = 11; //Left Motor Backward

int _rs = 6; //Right IR Sensor
int _ls = 7; //Left IR Sensor

void setup() {
  // Setting Pin Mode to OUTPUT MODE
  pinMode(RM_F, OUTPUT);
  pinMode(RM_B, OUTPUT);
  pinMode(LM_F, OUTPUT);
  pinMode(LM_B, OUTPUT);

  // Setting Pin Mode of IR Sensor to INPUT MODE
  pinMode(_rs, INPUT);
  pinMode(_ls, INPUT);
}

void loop() {
  // Reading Digital States of Sensors
  bool RS = digitalRead(_rs);
  bool LS = digitalRead(_ls);

  if(RS && LS){ // Move Forward
    digitalWrite(RM_F, HIGH);
    digitalWrite(RM_B, LOW);
    digitalWrite(LM_F, HIGH);
    digitalWrite(LM_B, LOW);

  }else if(!RS && LS){ // Move Right
    digitalWrite(RM_F, HIGH);
    digitalWrite(RM_B, LOW);
    digitalWrite(LM_F, LOW);
    digitalWrite(LM_B, HIGH);  
  
  }else if(RS && !LS){ // Move Left
    digitalWrite(RM_F, LOW);
    digitalWrite(RM_B, HIGH);
    digitalWrite(LM_F, HIGH);
    digitalWrite(LM_B, LOW);
  
  }else if(!RS && !LS){// Stop
    digitalWrite(RM_F, LOW);
    digitalWrite(RM_B, LOW);
    digitalWrite(LM_F, LOW);
    digitalWrite(LM_B, LOW);
  }else{
    //NOthing
  }
  delay(5); // Just for my heart
}
