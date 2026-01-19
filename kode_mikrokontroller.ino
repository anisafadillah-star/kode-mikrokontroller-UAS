#define in1 7
#define in2 6
#define in3 5
#define in4 4
#define enA 9
#define enB 10

#define trigPin 13
#define echoPin 12
#define buzzer 2

int motorSpeedA = 160;
int motorSpeedB = 160;

long duration;
int distance;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // ULTRASONIC
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    distance = 999;
  } else {
    distance = duration * 0.034 / 2;
  }

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // set kecepatan motor (PWM)
  analogWrite(enA, motorSpeedA);
  analogWrite(enB, motorSpeedB);

  // LOGIKANYA
  if (distance <= 30) {
    stopMotor();
    digitalWrite(buzzer, HIGH);
    Serial.println("STOP");
    delay(300);

    digitalWrite(buzzer, LOW);
    belokKanan();
    Serial.println("BELOK KANAN");
    delay(600);

  } else {
    maju();
    digitalWrite(buzzer, LOW);
    Serial.println("MAJU LURUS");
  }

  delay(100);
}

// GERAK MAJU
void maju() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void belokKanan() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void stopMotor() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
