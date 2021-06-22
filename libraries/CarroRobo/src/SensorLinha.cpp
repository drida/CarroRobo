#include <CarroRobo.h>

__SensorLinha::__SensorLinha()
{
    SetaPinoEsquerda(LeftPin);
    SetaPinoCentro(MiddlePin);
    SetaPinoDireita(RightPin);
}

__SensorLinha::~__SensorLinha()
{

}

void __SensorLinha::Ativar()
{ 
    Active = true;
}

void __SensorLinha::Desativar()
{ 
    Active = false;
}

void __SensorLinha::SetaPinoEsquerda(int leftPin)
{
    LeftPin = leftPin;
    pinMode(LeftPin, INPUT);
}

void __SensorLinha::SetaPinoCentro(int middlePin)
{
    MiddlePin = middlePin;
    pinMode(MiddlePin, INPUT);
}

void __SensorLinha::SetaPinoDireita(int rightPin)
{
    RightPin = rightPin;
    pinMode(RightPin, INPUT);
}

int __SensorLinha::PegaPinoEsquerda()
{
    return LeftPin;
}

int __SensorLinha::PegaPinoCentro()
{
    return MiddlePin;
}

int __SensorLinha::PegaPinoDireita()
{
    return RightPin;
}

int __SensorLinha::LerPinoEsquerda()
{
    return (Active)?digitalRead(PegaPinoEsquerda()):-1;
}

int __SensorLinha::LerPinoCentro() 
{
    return (Active)?digitalRead(PegaPinoCentro()):-1;
}

int __SensorLinha::LerPinoDireita()
{
    return (Active)?digitalRead(PegaPinoDireita()):-1;
}

void __SensorLinha::LerPinos(int& left, int& middle, int& right)
{
        left = LerPinoEsquerda();
        middle = LerPinoCentro();
        right = LerPinoDireita();
}