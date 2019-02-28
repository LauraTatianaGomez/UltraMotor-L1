#include <Servo.h>
#include <SoftwareSerial.h>
#define PINSERVODERECHO 7
#define PINSERVOIZQUIERDO 6
Servo servoizq; //se define servo izquierdo
Servo servoder; //se define servo derecho
SoftwareSerial BT(3,2);// rx tx 
char orden;

void setup()
{
  pinMode (PINSERVODERECHO, OUTPUT); //Configurar el modo de trabajo de un pin pudiendo ser INPUT (entrada) u OUTPUT (salida).
  pinMode (PINSERVOIZQUIERDO, OUTPUT);
  servoder.attach (PINSERVODERECHO);
  servoizq.attach (PINSERVOIZQUIERDO);
  Serial.begin (9600);
  BT.begin (9600);
}

void loop() 
{
  if(BT.available() > 0)
  {
    orden = BT.read();
  }
  if(Serial.available() > 0)
    {
    orden = Serial.read();
    }
    switch(orden)
    {
    case '0': case 'q':
    servoder.write(90);//quieto
    servoizq.write(90);
    break;
    case '1': case 'w':
    servoder.write(0);//adelante
    servoizq.write(180);
    break;
    case '2': case 's':
    servoder.write(180);//atras
    servoizq.write(0);
    break;
    case '3': case 'd':
    servoder.write(90);////derecha
    servoizq.write(180);
    break;
    case '4': case'a':
    servoder.write(0);//izquierda
    servoizq.write(90);
    break;
     case '5': 
    servoder.write(0);
    servoizq.write(180);
    delay(1000);
    servoder.write(180);
    servoizq.write(0);
    delay(1000); 
    servoder.write(90);//quieto
    servoizq.write(90);
    break;
    case'6':
    servoder.write(0);
    servoizq.write(90);
    delay(500); 
    servoder.write(90);
    servoizq.write(180);
    delay(500); 
    break;
    }
   
    }
