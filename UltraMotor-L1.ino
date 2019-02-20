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

void loop() {
  
}
