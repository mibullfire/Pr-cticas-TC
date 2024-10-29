// Código contando con las variables del transitor para ver el consumo y hacer las graficas

onst int motorPin = 9; // Motor conectado al pin 9
const int pulsador = 12;
int marchaParo = LOW;
int eventoPulsacion = LOW;

int Base;
float base;
int Colector;
float colector;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(pulsadorPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("CONTROL MOTOR CC");
  Serial.print("Inicialmente, marchaParo = ");
  Serial.println(marchaParo);
}

void loop() {
  eventoPulsacion = digitalRead(pulsadorPin); //leemos la pulsacion
  if(eventoPulsacion == HIGH) {
    if(marchaParo == HIGH) {
      marchaParo = LOW;
    }else{
      marchaParo = HIGH
    }
    digitalWrite(motorPin, marchaParo);
    Serial.print("marchaParo =");
    Serial.println(marchaParo);
  }

  Base = analogRead(A0);
  base = Base * (5.0/1023);
  Serial.print("Base");
  Serial.println(base);
  Colector = analogRead(A1);
  colector = Colector * (5.0/1023);
  Serial.print("Colector");
  Serial.println(colector);

  
  delay(300);
}

