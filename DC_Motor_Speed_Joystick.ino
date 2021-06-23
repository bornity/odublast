/*
 * Save as DC_Motor_Speed_Joystick.ino
 *
 * Uses L293D to control speed and direction of motor
 * follows X-Axis input of joystick
*/


int speedPin = 5;
int dir1 = 4; // motor reverse
int dir2 = 3; // motor forward

int mSpeed = 0;
int xSpeed = 0;
int dirInd = 0;


void setup() {
  pinMode(speedPin,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);

  digitalWrite(speedPin,LOW);
  Serial.begin(9600);
}

void loop() 
{

  int joy_x = analogRead(A0); // Read Joystick X-Axis

  Serial.print("X-axis: ");
  Serial.print(joy_x);
  Serial.print("\n\n");

  if (joy_x < 491) {
  
    digitalWrite(dir1,LOW); 
    digitalWrite(dir2,HIGH);
    dirInd = 1; 
    mSpeed = map(joy_x, 491, 0, 0, 255);
  }
  else if (joy_x > 531) {
    digitalWrite(dir1,HIGH); 
    digitalWrite(dir2,LOW); 
    dirInd = -1;
    mSpeed = map(joy_x, 531, 1023, 0, 255);
  }
else {
    mSpeed = 0;
    dirInd = 0;
  }

  Serial.print("Speed:  ");
  Serial.print(dirInd*mSpeed);
  Serial.print("  ");
  Serial.print(dirInd);
  Serial.print("\n\n");

  analogWrite(speedPin,mSpeed);
  delay(200);
}
