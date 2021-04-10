#include <Servo.h> //incluye libreria de servomotores//
#include <AFMotor.h> //incluye libreria del motorshield de adafruit//

AF_DCMotor motor1(1); //declara el motor 1 en la conexión 1 del motorshield//
AF_DCMotor motor2(3); //declara el motor 2 en la conexión 3 del motorshield//

Servo servarlo;
Servo servasslo;

char comando1;// crea una variable que representa un dato alfanumerico//
void setup()// da lectura al codigo solo una vez//
{
  Serial.begin(9600);//establece la velociada de datos//
  Serial.setTimeout(5);
  servarlo.attach(9);
  servasslo.attach(10);
}

void loop()//da lectura al codigo de forma repetitiva//
{
  String valor = "";
  if (Serial.available() > 0) // si el valor en los puertos serie es mayor a 0 se sigue el programa//
  {
    String linea = Serial.readString();
    for (int i = 0 ; i < linea.length(); i++)
    {
      int caracter = linea[i];
      if (isDigit(caracter))
      {
        valor += (char)caracter;
      }
      else if (caracter != '\n')
      {
        comando1 = caracter;
      }
      else
      {
        break;
      }
      alto();    // inicia con la variable alto //
      switch (comando1) //inicio de la estructura de control de comando//
      {
        case 'F': // en el caso de que sea F//
          adelante();// asignacion del comando adelante//
          break;// fin //
        case 'G': // en el caso de que sea B//
          atras();// asignacion del comando atras//
          break;// fin //
        case 'L': // en el caso de que sea L//
          izquierda();// asignacion del comando izquierda//
          break;// fin //
        case 'R': // en el caso de que sea R//
          derecha();// asignacion del comando derecha//
          break;// fin //
        case 'Q': // en el caso de que sea G//
          adelante_izquierda();// asignacion del comando adelante izquierda//
          break;// fin //
        case 'E': // en el caso de que sea I//
          adelante_derecha();// asignacion del comando adelante derecha//
          break;// fin //
        case 'Z': // en el caso de que sea H//
          atras_izquierda();// asignacion del comando atras izquierda//
          break;// fin //
        case 'C': // en el caso de que sea J//
          atras_derecha();// asignacion del comando atras derecha//
          break;// fin //
        case 'S':
          alto();
          break;
        case 'J':
          if (valor != "")
          {
            arlo(valor.toInt());
          }
          break;
        case 'K':
          if (valor != "")
          {
            asslo(valor.toInt());
          }
          break;
      }
    }
  }
}
void arlo(int grados)//necesita probarse//
{
  servarlo.write(grados);
}
void asslo(int grados)//necesita probarse//
{
  servasslo.write(grados);
}
void adelante()// codigo ejecutado cuando es llamado de la funcion del comando adelante//
{
  motor1.setSpeed(255);//se establece la velocidad maxima del motor1//
  motor1.run(FORWARD); //se establece la direcion adelanre del motor1//
  motor2.setSpeed(255); //se establece la velocidad maxima del motor2//
  motor2.run(FORWARD); //se establece la direcion adelante del motor2//
}

void atras()// funcion del comando atras//
{
  motor1.setSpeed(255); //se establece la velocidad maxima del motor1//
  motor1.run(BACKWARD); //se establece la direcion atras del motor1//
  motor2.setSpeed(255); //se establece la velocidad maxima del motor2//
  motor2.run(BACKWARD); //se establece la direcion atras del motor2//
}

void izquierda()// funcion del comando izquierda//
{
  motor1.setSpeed(255); //se establece la velocidad maxima del motor1//
  motor1.run(BACKWARD); //se establece la direcion aselante del motor1//
  motor2.setSpeed(255); //se establece la velocidad minima del motor2//
  motor2.run(FORWARD); //se establece la liberacion del motor2//
}

void derecha()// funcion del comando derecha//
{
  motor1.setSpeed(255); //se establece la velocidad minima del motor1//
  motor1.run(FORWARD); //se establece la liberacion del motor1//
  motor2.setSpeed(255); //se establece la velocidad maxima del motor2//
  motor2.run(BACKWARD); //se establece la direcion adelante del motor2//
}

void adelante_izquierda()// funcion del comando adelante izquierda//
{
  motor1.setSpeed(77);//se establece la velocidad maxima del motor1//
  motor1.run(FORWARD); //se establece la direcion adelante del motor1//
  motor2.setSpeed(255); //se establece la velocidad media del motor2//
  motor2.run(FORWARD); //se establece la direcion adelante del motor2//
}

void adelante_derecha()// funcion del comando adelante derecha//
{
  motor1.setSpeed(255); //se establece la velocidad media del motor1//
  motor1.run(FORWARD); //se establece la direcion adelante del motor1//
  motor2.setSpeed(77); //se establece la velocidad maxima del motor2//
  motor2.run(FORWARD); //se establece la direcion adelante del motor2//
}

void atras_izquierda()// funcion del comando atras izquierda//
{
  motor1.setSpeed(77); //se establece la velocidad maxima del motor1//
  motor1.run(BACKWARD); //se establece la direcion atras del motor1//
  motor2.setSpeed(255); //se establece la velocidad maxima del motor2//
  motor2.run(BACKWARD); //se establece la direcion atras del motor2//
}

void atras_derecha()// funcion del comando atras derecha//
{
  motor1.setSpeed(255); //se establece la velocidad media del motor1//
  motor1.run(BACKWARD); //se establece la direcion atras del motor1//
  motor2.setSpeed(77); //se establece la velocidad maxima del motor2//
  motor2.run(BACKWARD); //se establece la direcion atras del motor2//
}
void alto()// funcion del comando alto//
{
  motor1.setSpeed(0); //se establece la velocidad minima del motor1//
  motor2.run(RELEASE); //se establece la liberacion del motor1//
  motor2.setSpeed(0); //se establece la velocidad minima del motor2//
  motor2.run(RELEASE); //se establece la liberacion del motor2//
}
