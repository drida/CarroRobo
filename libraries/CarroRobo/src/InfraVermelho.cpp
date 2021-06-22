#include <CarroRobo.h>

__InfraVermelho::__InfraVermelho()
{
    SetaPino(IrPin);
}

__InfraVermelho::~__InfraVermelho()
{

}

void __InfraVermelho::SetaPino(int irPin)
{
    IrPin = irPin;
    pinMode(IrPin, INPUT);
}

void __InfraVermelho::AtivarReceber()
{
    pinMode(IrPin, INPUT);
}

void __InfraVermelho::AtivarEnviar()
{
    pinMode(IrPin, OUTPUT);
}

void __InfraVermelho::LimparDecodificador()
{

}

int __InfraVermelho::PegaPino()
{
    return IrPin;
}

int __InfraVermelho::Decodificar()
{
    return ;
}
