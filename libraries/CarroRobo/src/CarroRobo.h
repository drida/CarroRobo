#ifndef CarroRobo_h
#define CarroRobo_h

#include <Arduino.h>

enum pino {
    EchoPin = A0,
    TrigPin = A1,
    Vazio1 = 1,
    MDRPin = 2,
    ServoPin = 3,
    MDAPin = 4,
    VEPin = 5,
    SLLeftPin = 6,
    MERPin = 7,
    MEAPin = 8,
    SLMiddlePin = 9,
    VDPin = 10,
    SLRightPin = 11,
    IRPin = 12
};

class __InfraVermelho
{
    public:
        __InfraVermelho();
        ~__InfraVermelho();    
        void SetaPino(int irPin);
        void AtivarReceber();
        void AtivarEnviar();
        void LimparDecodificador();
        int PegaPino();
        int Decodificar();
        int Decodificar(int& valor); 
    private:
        int IrPin = pino::IRPin;
        int IrKHz = 36;
};

class __UltraSom
{
    public:
        __UltraSom();
        ~__UltraSom();
        void Ativar();
        void Desativar();
        void SetaPinoEntrada(int echoPin);
        void SetaPinoSaida(int trigPin);
        int PegaPinoEntrada();
        int PegaPinoSaida();
        double MedirDistancia(); 
    private:
        int EchoPin = pino::EchoPin;
        int TrigPin = pino::TrigPin;
        bool Active = false;
};

class __ServoMotor
{
    public:
        __ServoMotor();
        ~__ServoMotor();
        void Ativar();
        void Desativar();        
        void SetaPinoSaida(int servoPin);
        void SetaAngulo(int angulo);
        int PegaPinoSaida();
        int PegaAngulo();
    private:
        int ServoPin = pino::ServoPin;
        bool Active = false;
};

class __SensorLinha
{
    public:
        __SensorLinha();
        ~__SensorLinha();
        void Ativar();
        void Desativar(); 
        void SetaPinoEsquerda(int leftPin);
        void SetaPinoCentro(int middlePin);
        void SetaPinoDireita(int rightPin);
        int PegaPinoEsquerda();
        int PegaPinoCentro();
        int PegaPinoDireita();
        int LerPinoEsquerda();
        int LerPinoCentro();
        int LerPinoDireita();
        void LerPinos(int& left, int& middle, int& right);
    private:
        int LeftPin = pino::SLLeftPin; 
        int MiddlePin = pino::SLMiddlePin; 
        int RightPin = pino::SLRightPin;
        bool Active = false;
};

class CarroRobo
{
    public:
        CarroRobo();
        ~CarroRobo();
        void SetaMensagemSerial(bool mostra);
        void MensagemSerial(String message);
        void MensagemSerial(int message);
        void SetaPinoMotorEsquerdaAvancar(int meaPin);
        void SetaPinoMotorDireitaAvancar(int mdaPin);
        void SetaPinoMotorEsquerdaRetroceder(int merPin);
        void SetaPinoMotorDireitaRetroceder(int mdrPin);
        void SetaPinoVelocidadeEsquerda(int vePin);
        void SetaPinoVelocidadeDireita(int vdPin);
        int PegaPinoMotorEsquerdaAvancar();
        int PegaPinoMotorEsquerdaRetroceder();
        int PegaPinoMotorDireitaAvancar();
        int PegaPinoMotorDireitaRetroceder();
        int PegaPinoVelocidadeEsquerda();
        int PegaPinoVelocidadeDireita();
        void LigarMotorEsquerdaAvancar();
        void LigarMotorEsquerdaRetroceder();
        void DesligarMotorEsquerda();
        void LigarMotorDireitaAvancar();
        void LigarMotorDireitaRetroceder();
        void DesligarMotorDireita();
        void LigarMotorAvancar();
        void LigarMotorRetroceder();
        void DesligarMotor();
        void MudarVelocidadeEsquerda(int velEsq);
        void MudarVelocidadeDireita(int velDir);
        void MudarVelocidade(int velEsq, int velDir);
        __UltraSom UltraSom;
        __ServoMotor ServoMotor;
        __SensorLinha SensorLinha;
        __InfraVermelho InfraVermelho;
    private:
        int MeaPin = pino::MEAPin; 
        int MdaPin = pino::MDAPin; 
        int MerPin = pino::MERPin;
        int MdrPin = pino::MDRPin;
        int VePin = pino::VEPin;
        int VdPin = pino::VDPin;
        int VelocidadeEsquerda;
        int VelocidadeDireita;
        bool MostrarMensagemSerial;
};

#endif