


#define trigPin 7 //sensor ultrasonik
#define echoPin 6 //sensor ultrasonik
#define led 13 //led hijau
#define led2 12 //led hijau
#define led3 11 //led kuning
#define led4 10 //led kuning
#define led5 9 //led merah
#define led6 8 //led merah
#define buzzer 3 //buzzer

int sound = 250;


void setup() {
  /* SET UP PIN SEBAGAI OUTPUT */
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  /* set up untuk sensor ultrasonik */
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; //jarak dalam cm

/* Pengaturan lampu LED dan durasi buzzer sesuai jarak */
  if (distance <= 30) {
    digitalWrite(led, HIGH);
    sound = 100; 
}
  else {
    digitalWrite(led,LOW);
    
  }
  if (distance < 25) {
      digitalWrite(led2, HIGH);
      sound = 200;
}
  else {
      digitalWrite(led2, LOW);
  }
  if (distance < 20) {
      digitalWrite(led3, HIGH);
      sound = 300;
}
  else {
    digitalWrite(led3, LOW);
  }
  if (distance < 15) {
    digitalWrite(led4, HIGH);
    sound = 400;
}
  else {
    digitalWrite(led4,LOW);
  }
  if (distance < 10) {
    digitalWrite(led5, HIGH);
    sound = 500;
}
  else {
    digitalWrite(led5,LOW);
  }
  if (distance < 5) {
    digitalWrite(led6, HIGH);
    sound = 600;
}
  else {
    digitalWrite(led6,LOW);
  }

  if (distance > 30 || distance <= 0){
    Serial.println("Out of range"); //output pada serial monitor
    noTone(buzzer); //buzzer tidak bunyi
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, 200000, sound);
    //tone(buzzer, sound);
    }

  delay(500);
}
