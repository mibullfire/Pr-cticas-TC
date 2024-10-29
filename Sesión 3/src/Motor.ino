// Código para la primera parte de la práctica.

const int motorPin = 9; // Motor conectado al pin 9
const int pulsadorPin = 2;
int marchaParo = LOW;
int eventoPulsacion = LOW;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(pulsadorPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("CONTROL MOTOR CC");
  Serial.print("Inicialmente, marchaParo = ");
  Serial.println(marchaParo);
}

void loop() {
  eventoPulsacion = digitalRead(pulsadorPin); //Leemos la pulsacion
  if(eventoPulsacion == HIGH) {
    if(marchaParo == HIGH) {
      marchaParo = LOW;
    }else{
      marchaParo = HIGH;
    }
    digitalWrite(motorPin, marchaParo);
    Serial.print("marchaParo =");
    Serial.println(marchaParo);
  }
  
  delay(300);
}