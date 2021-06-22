#include <CarroRobo.h>

__UltraSom::__UltraSom()
{
    SetaPinoEntrada(EchoPin);
    SetaPinoSaida(TrigPin);
}

__UltraSom::~__UltraSom()
{
    
}

void __UltraSom::Ativar()
{ 
    Active = true;
}

void __UltraSom::Desativar()
{ 
    Active = false;
}

void __UltraSom::SetaPinoEntrada(int echoPin)
{ 
    EchoPin = echoPin;
    pinMode(EchoPin, INPUT); 
}

void __UltraSom::SetaPinoSaida(int trigPin)
{
    TrigPin = trigPin;
    pinMode(TrigPin, OUTPUT);
}

int __UltraSom::PegaPinoEntrada()
{
    return EchoPin;
}

int __UltraSom::PegaPinoSaida()
{
    return TrigPin;
}

double __UltraSom::MedirDistancia()
{
    if (!Active) return 0;

    digitalWrite(TrigPin, LOW);  
    delayMicroseconds(2); 
    digitalWrite(TrigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(TrigPin, LOW);    
    double valor = pulseIn(EchoPin, HIGH); 
    valor = valor / 58;
    return valor;
}