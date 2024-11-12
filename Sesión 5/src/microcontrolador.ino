const int pinMasVelocidad=2;
const int pinMenosVelocidad=3;
const int motorPin=9;
int velocidad=0;
int masVelocidad=0;
int menosVelocidad=0;

void setup() {
  Serial.println("puto");
  pinMode(motorPin, OUTPUT);
  pinMode(pinMasVelocidad, INPUT);
  pinMode(pinMenosVelocidad, INPUT);
  Serial.begin(9600);
}

void loop() {
  masVelocidad=digitalRead(pinMasVelocidad);
  menosVelocidad=digitalRead(pinMenosVelocidad);

  if(masVelocidad==HIGH){
    if(velocidad<255){
      velocidad++;
      }
      Serial.println(velocidad);
    }
    if(menosVelocidad==HIGH){
      if(velocidad>0){
        velocidad--;
      }
      Serial.println(velocidad);
    }
    analogWrite(motorPin,velocidad);
    delay(100);
}
