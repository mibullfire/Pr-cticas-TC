/*Variables globales*/
int estado = 0; /* Definimos una variable estado y estado anterio para controlar el pulsador*/
int estadoAnterior = 0;
int pulsos = 0; /* La variable pulsos nos indicará cuantas veces hemos pulsado el pulsador, como si fuera una especie de contador*/

void setup () {
 Serial.begin (9600); // Inicializa la comunicación serie
 /*Inicialice el pin 2 como entrada y los pines 3,4 y 5 como salida*/
 pinMode(2,INPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 
}

void loop () {
/*Lea el estado del pin 2, que recogerá el valor del pulsador*/
  estado = digitalRead(2);
  
/*Si el pulsador ha sido accionado y anteriormente no lo estaba, incrementar el
 número de veces que se ha pulsado*/

  if (estado == HIGH and estadoAnterior == LOW){
    pulsos = pulsos+1;
    delay(300);

  }

estadoAnterior = estado;
   
/*Si el pulsador ha sido accionado una vez activar la salida 3 –color rojo-*/
  if (pulsos == 1){
    digitalWrite(3,HIGH);

  }else{
    digitalWrite(3,LOW);
  }
    
/*Si el pulsador ha sido accionado dos veces activar la salida 4 –color azul-*/

  if (pulsos == 2){
    digitalWrite(4,HIGH);

  }else{
    digitalWrite(4,LOW);
  }
/*Si el pulsador ha sido accionado tres veces activar la salida 5 –color verde-*/
  if (pulsos == 3){
    digitalWrite(5,HIGH);

  }else{
    digitalWrite(5,LOW);
  }
/*Si el número de veces pulsado es mayor que tres, reiniciar a uno*/
  if (pulsos > 3){
    pulsos = 0;
  }
}

