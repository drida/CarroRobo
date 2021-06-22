#include <CarroRobo.h>

__ServoMotor::__ServoMotor()
{
    SetaPinoSaida(ServoPin);
}

__ServoMotor::~__ServoMotor()
{

}

void __ServoMotor::Ativar()
{ 
    Active = true;
}

void __ServoMotor::Desativar()
{ 
    Active = false;
}

void __ServoMotor::SetaPinoSaida(int servoPin)
{
    ServoPin = servoPin;
    pinMode(ServoPin, OUTPUT);
}

void __ServoMotor::SetaAngulo(int angulo)
{
    if (!Active) return;

    for(int i=0;i<=10;i++) {
        int pulsewidth = (angulo*11)+500;
        digitalWrite(ServoPin, HIGH);
        delayMicroseconds(pulsewidth);
        digitalWrite(ServoPin, LOW);
        delay(20-pulsewidth/1000);        
    }
}

int __ServoMotor::PegaPinoSaida()
{
    return ServoPin;
}

int __ServoMotor::PegaAngulo()
{
    return EchoPin;
}