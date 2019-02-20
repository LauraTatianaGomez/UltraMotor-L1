#include <Servo.h>
#include <SoftwareSerial.h>
#define PINSERVODERECHO 12
#define PINSERVOIZQUIERDO 11
Servo servoizq; //se define servo izquierdo
Servo servoder; //se define servo derecho
char orden;

void setup() {
  pinMode (PINSERVODERECHO, OUTPUT); //Configurar el modo de trabajo de un pin pudiendo ser INPUT (entrada) u OUTPUT (salida).
  pinMode (PINSERVOIZQUIERDO, OUTPUT);
  servoder.attach (PINSERVODERECHO);
  servoizq.attach (PINSERVOIZQUIERDO);
  Serial.begin (9600);
}

void loop() 
{
  if(Serial.available() > 0)
    {
    int orden = Serial.read();
    
    switch(orden)
    {
    case '0': case 'q':
    servoder.write(90);//quieto
    servoizq.write(90);
    break;
    case '8': case 'w':
    servoder.write(0);//adelante
    servoizq.write(180);
    break;
    case '2': case 's':
    servoder.write(180);//atras
    servoizq.write(0);
    break;
    case '4': case 'a':
    servoder.write(90);////derecha
    servoizq.write(180);
    break;
    case '6': case'd':
    servoder.write(0);//izquierda
    servoizq.write(90);
    break;
    }
    Serial.println(orden);
    }
}
