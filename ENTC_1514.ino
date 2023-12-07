
int m1 = A0;
int m11 = A1;
int m2 = A2;
int m21 = A3;
int flame = A4;

#define relay 8
int state;

void setup() {
  // put your setup code here, to run once:
  pinMode(m1, OUTPUT);
  pinMode(m11, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(flame, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Flame_sensor();
  if (Serial.available() > 0)     // Ckeck for command Recieved
  {
    state = Serial.read();
    if (state == '1')//forward
    {
      digitalWrite(m1, HIGH);
      digitalWrite(m11, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m21, LOW);
    }
    else if (state == '2')//backword
    {
      digitalWrite(m1, LOW);
      digitalWrite(m11, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m21, HIGH);
    }
    else if (state == '3')//left
    {
      digitalWrite(m1, LOW);
      digitalWrite(m11, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m21, LOW);
    }
    else if (state == '4')//right
    {

      digitalWrite(m1, LOW);
      digitalWrite(m11, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m21, HIGH);
    }
    else if (state == '5')//stop
    { 
      digitalWrite(m1, LOW);
      digitalWrite(m11, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m21, LOW);
    }
  }
}

void Flame_sensor()
{
  int flame_detected = digitalRead(flame);
  Serial.println(flame_detected);

  if (flame_detected == 0)
  {
    digitalWrite(relay, HIGH);
    delay(3000);
    digitalWrite(relay, LOW);
  }
  else
  {
    digitalWrite(relay, LOW);
  }
}
