#define analogPin 0
#define chargePin 13
#define dischargePin 11

unsigned long startTime;
double chargeTime;
double dischargeTime;
unsigned int readSensor;

void setup() {
  // put your setup code here, to run once:
  pinMode (chargePin, OUTPUT);
  digitalWrite (chargePin, LOW);
  Serial.begin(9600);
}

void loop() {
  // Código de la Descarga del Condensador
  digitalWrite (chargePin, LOW);
  pinMode (dischargePin, OUTPUT);
  digitalWrite (dischargePin, LOW);
  readSensor = analogRead (analogPin);

  while (readSensor > 0) {
    readSensor = analogRead (analogPin);
  }

  pinMode (dischargePin, INPUT); // Pone el pin de descarga en alta impedancia
  Serial.println ("-----Carga-----"); // Indica el comienzo de la carga

  // Código de la Carga del Condensador

  digitalWrite (chargePin, HIGH);
  startTime = micros () / 1000000.0;
  readSensor = analogRead (analogPin);

  do {
    chargeTime = (micros () / 1000000.0) - startTime;
    Serial.print (chargeTime);
    Serial.print ("\t");
    Serial.println (readSensor);
    readSensor = analogRead (analogPin);
  } while (chargeTime < 23.5); // Tiempo de carga igual a 2 RC. Nota: se cambia el codigo para que el tiempo sea igual a 5 ciclos de tiempo: 5 x 4.75
  delay (1000);

// Código de la Descagar del Condensador una vez cargado

  Serial.println ("-----Descarga-----"); // Indica el comienzo de la carga
  digitalWrite (chargePin, LOW);
  pinMode (dischargePin, OUTPUT);
  digitalWrite (dischargePin, LOW);

  do {
    dischargeTime = (micros() / 1000000.0) - chargeTime;
    Serial.print (dischargeTime);
    Serial.print("\t");
    Serial.println (readSensor);
    readSensor = analogRead (analogPin); 
  } while (readSensor > 0); // Tiempo de carga igual a 2 RC. Nota: se cambia el codigo para que el tiempo sea igual a 5 ciclos de tiempo: 5 x 4.75
  delay (1000); 

  
  exit(0);

}
