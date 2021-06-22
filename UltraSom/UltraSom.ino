#include <CarroRobo.h>

CarroRobo meuCarroRobo;

void setup() { 
  meuCarroRobo.SetaMensagemSerial(true);
  meuCarroRobo.MensagemSerial("Início\n");

  // Controle dos Motores e Velocidade
  meuCarroRobo.SetaPinoMotorDireitaRetroceder(2);
  meuCarroRobo.SetaPinoMotorDireitaAvancar(4);
  meuCarroRobo.SetaPinoMotorEsquerdaRetroceder(7);
  meuCarroRobo.SetaPinoMotorEsquerdaAvancar(8);
  meuCarroRobo.SetaPinoVelocidadeEsquerda(5);
  meuCarroRobo.SetaPinoVelocidadeDireita(10);

  // UltraSom
  meuCarroRobo.UltraSom.SetaPinoEntrada(A0);
  meuCarroRobo.UltraSom.SetaPinoSaida(A1);
  meuCarroRobo.UltraSom.Ativar();

  // Servo Motor
  meuCarroRobo.ServoMotor.SetaPinoSaida(3);
  meuCarroRobo.ServoMotor.Ativar();
  meuCarroRobo.ServoMotor.SetaAngulo(90);
  meuCarroRobo.ServoMotor.Ativar();
 
  meuCarroRobo.MudarVelocidade(100, 100);
  meuCarroRobo.LigarMotorAvancar();
}

void loop() {

  double dFrente = meuCarroRobo.UltraSom.MedirDistancia();
  if(dFrente < 30) {
    bool marchaRe = true;
    do {    
      meuCarroRobo.DesligarMotor();
      meuCarroRobo.ServoMotor.SetaAngulo(10);
      delay(50);
      double dDireita = meuCarroRobo.UltraSom.MedirDistancia();
      meuCarroRobo.ServoMotor.SetaAngulo(170);
      delay(50);
      double dEsquerda = meuCarroRobo.UltraSom.MedirDistancia();
      meuCarroRobo.ServoMotor.SetaAngulo(90);
      meuCarroRobo.MudarVelocidade(200, 200);
      if (dDireita < 30 && dEsquerda < 30) {
        meuCarroRobo.LigarMotorRetroceder();
        marchaRe = true;
      } else if (dDireita > dEsquerda) {
        meuCarroRobo.LigarMotorDireitaRetroceder();
        meuCarroRobo.LigarMotorEsquerdaAvancar();
        marchaRe = false;
      } else if (dDireita <= dEsquerda) {
        meuCarroRobo.LigarMotorEsquerdaRetroceder();
        meuCarroRobo.LigarMotorDireitaAvancar();
        marchaRe = false;
      }
      delay(500);
    } while (marchaRe);
    meuCarroRobo.MudarVelocidade(100, 100);
    meuCarroRobo.LigarMotorAvancar();
  } 
}