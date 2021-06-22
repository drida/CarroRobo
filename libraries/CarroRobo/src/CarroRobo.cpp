#include <CarroRobo.h>

CarroRobo::CarroRobo()
{
    SetaMensagemSerial(true);
    MensagemSerial("constructor CarroRobo\n");
}

CarroRobo::~CarroRobo()
{
    MensagemSerial("destructor CarroRobo\n");
}

void CarroRobo::SetaMensagemSerial(bool mostra)
{
    MostrarMensagemSerial = mostra;
}

void CarroRobo::MensagemSerial(String mensagem) 
{
    if (MostrarMensagemSerial) {
        Serial.begin(9600);
        Serial.print(mensagem);
        Serial.end();
    }
}

void CarroRobo::MensagemSerial(int mensagem) 
{
    if (MostrarMensagemSerial) {
        Serial.begin(9600);
        Serial.print(mensagem);
        Serial.end();
    }
}

void CarroRobo::SetaPinoMotorEsquerdaAvancar(int meaPin)
{
    MeaPin = meaPin;
    pinMode(MeaPin, OUTPUT);
}

void CarroRobo::SetaPinoMotorDireitaAvancar(int mdaPin)
{
    MdaPin = mdaPin;
    pinMode(MdaPin, OUTPUT);
}

void CarroRobo::SetaPinoMotorEsquerdaRetroceder(int merPin)
{
    MerPin = merPin;
    pinMode(MerPin, OUTPUT);
}

void CarroRobo::SetaPinoMotorDireitaRetroceder(int mdrPin)
{
    MdrPin = mdrPin;
    pinMode(MdrPin, OUTPUT);
}

void CarroRobo::SetaPinoVelocidadeEsquerda(int vePin)
{
    VePin = vePin;
    pinMode(VePin, OUTPUT);
}

void CarroRobo::SetaPinoVelocidadeDireita(int vdPin)
{
    VdPin = vdPin;
    pinMode(VdPin, OUTPUT);
}

int CarroRobo::PegaPinoMotorEsquerdaAvancar()
{
    return MeaPin;
}

int CarroRobo::PegaPinoMotorDireitaAvancar()
{
    return MdaPin;
}

int CarroRobo::PegaPinoMotorEsquerdaRetroceder()
{
    return MerPin;
}

int CarroRobo::PegaPinoMotorDireitaRetroceder()
{
    return MdrPin;
}

int CarroRobo::PegaPinoVelocidadeEsquerda()
{
    return VePin;
}

int CarroRobo::PegaPinoVelocidadeDireita()
{
    return VdPin;
}

void CarroRobo::LigarMotorEsquerdaAvancar()
{
    digitalWrite(MeaPin, HIGH);
}

void CarroRobo::LigarMotorEsquerdaRetroceder()
{
    digitalWrite(MerPin, HIGH);
}

void CarroRobo::DesligarMotorEsquerda()
{
    digitalWrite(MeaPin, LOW);
    digitalWrite(MerPin, LOW);
}

void CarroRobo::LigarMotorDireitaAvancar()
{
    digitalWrite(MdaPin, HIGH);
}

void CarroRobo::LigarMotorDireitaRetroceder()
{
    digitalWrite(MdrPin, HIGH);
}

void CarroRobo::DesligarMotorDireita()
{
    digitalWrite(MdaPin, LOW);
    digitalWrite(MdrPin, LOW);
}

void CarroRobo::DesligarMotor()
{
    DesligarMotorDireita();
    DesligarMotorEsquerda();
}

void CarroRobo::LigarMotorAvancar()
{
    DesligarMotor();
    LigarMotorDireitaAvancar();
    LigarMotorEsquerdaAvancar();
}

void CarroRobo::LigarMotorRetroceder()
{
    DesligarMotor();
    LigarMotorDireitaRetroceder();
    LigarMotorEsquerdaRetroceder();
}

void CarroRobo::MudarVelocidadeEsquerda(int velEsq)
{
    VelocidadeEsquerda = velEsq;
    analogWrite(VePin, VelocidadeEsquerda);
}

void CarroRobo::MudarVelocidadeDireita(int velDir)
{
    VelocidadeDireita = velDir;
    analogWrite(VdPin, VelocidadeDireita);
}

void CarroRobo::MudarVelocidade(int velEsq, int velDir)
{
    MudarVelocidadeEsquerda(velEsq);
    MudarVelocidadeDireita(velDir);
}