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
      digitalWrite(motorPin, LOW); //Ponemos el pin del motoro en bajo, luego esa corriente entra en el potenciometro y corta al BJT
    }else{
      marchaParo = HIGH;
      digitalWrite(motorPin, HIGH); // Pasamos corriente y luego la ampliamos con el potencioemtro y el BJT
    }
    digitalWrite(motorPin, marchaParo);
    Serial.print("marchaParo =");
    Serial.println(marchaParo);
  }

  // Este código no funciona bien, es para medir las gráficas.
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

