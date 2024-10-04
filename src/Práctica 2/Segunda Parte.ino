/*Variables globales*/
int potadc = 0; /*Esta variable hace referencia al potenciómetro*/

void setup() {
 Serial.begin (9600); // Inicializa la comunicación serie
/*Inicialice los pines 2,3 y 4 como salida*/
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}
void loop() {
  potadc = analogRead(A0);
  potadc = potadc / 10;
/*Leer el valor del potenciómetro y dividir por 10.0 */
/*Sacar por consola el valor leído de la entrada analógica y hacer un retraso de
200 ms*/

  Serial.print(potadc);
  delay(200);
/*Si el valor leído está por debajo de 25 activar salida 4 –color azul-*/
if (potadc < 25){
  digitalWrite(4,HIGH);
  
}
/*Si el valor leído está entre 25 y 27 desactivar salidas 2, 3 y 4 */

if(potadc > 25 and potadc < 27){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  
}
/*Si el valor leído está entre 27 y 30 activar salida 3 –color amarillo- */
if(potadc > 27 and potadc < 30){
  digitalWrite(3, HIGH);
  
}
/*Si el valor leído está por encima de 30 activar salida 2 –color rojo- */

if(potadc > 30){
  digitalWrite(2, HIGH);
  
}
}


