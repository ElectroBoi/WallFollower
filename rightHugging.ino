#include <NewPing.h>


// Motor control pins
#define IN4 7
#define IN3 2
#define IN2 4
#define IN1 3
#define ENA 5
#define ENB 6

// Ultrasonic sensor pins
#define TRIGGER_PINF  10 
#define ECHO_PINF     11  
#define TRIGGER_PINL  8
#define ECHO_PINL     9 
#define TRIGGER_PINR  12 
#define ECHO_PINR     13  
#define MAX_DISTANCE  200 

// Wall Follower Parameters
#define MaxFront      8
#define FrontSlow     13
#define sideDistance   7
#define oppSDistance   9
#define defRSpeed   80
#define defLSpeed   80
#define slowRSpeed   80
#define slowLSpeed   80

int leftSpeed = defLSpeed;
int rightSpeed = defRSpeed;

NewPing sonarF(TRIGGER_PINF, ECHO_PINF, MAX_DISTANCE);
NewPing sonarL(TRIGGER_PINL, ECHO_PINL, MAX_DISTANCE);
NewPing sonarR(TRIGGER_PINR, ECHO_PINR, MAX_DISTANCE);

int distanceF, distanceR, distanceL, currentOrient;
void setup() {
  
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(13, INPUT);
 
}


void loop() {
  //Membaca Sensor Ultrasonik Depan
  distanceF = sonarF.ping_cm();
  //Membaca Sensor Ultrasonik Kiri (Gunakan apabila menggunakan Logika Left Wall Hugging)
  //distanceL = sonarL.ping_cm();
  //Membaca Sensor Ultrasonik Kanan (Gunakan apabila menggunakan Logika Right Wall Hugging)
  distanceR = sonarR.ping_cm();
  Serial.print(distanceF);
  Serial.print(", ");
  Serial.println(distanceR);

  if(distanceF < FrontSlow){
    leftSpeed = slowLSpeed;
    rightSpeed = slowRSpeed;
  }else {
    leftSpeed = defLSpeed;
    rightSpeed = defRSpeed;
  }

  //Logika Left Wall Hugging
  if(distanceF < MaxFront){
    //Belok ke Kanan apabila depan Robot terdapat tembok
    if (distanceR > MaxFront){
      motorControl(1,0,0,0, defLSpeed, defRSpeed);
    }else {
      motorControl(0,0,1,0, defLSpeed, defRSpeed);
    }
  }

  //Ganti variable distanceL ke variable distanceR apabila menggunakan logkia Right Wall Hugging
  else if (distanceR > sideDistance + 2){
    //Belok ke kiri untuk mendekati tembok kiri apabila jarak robot terlalu jajuh dari tembok  
    motorControl(1,0,0,0, leftSpeed, rightSpeed);
  }

  else if (distanceR < sideDistance - 2){
    //Belok ke Kanan apabila jarak robot terlalu dekat dengan tembok untuk menjauh
    motorControl(0,0,1,0, leftSpeed, rightSpeed);
  }
 
  else {
    //Apabila tidak terdeteksi apapun pada decision diatas robot akan maju
    motorControl(1,0,1,0, leftSpeed, rightSpeed);
  }
}


void motorControl(int In1, int In2, int In3, int In4, int SpeedL, int SpeedR){
  digitalWrite(IN1, In1);
  digitalWrite(IN2, In2);
  digitalWrite(IN3, In3);
  digitalWrite(IN4, In4);
  analogWrite(ENA, SpeedL);
  analogWrite(ENB, SpeedR);
}
