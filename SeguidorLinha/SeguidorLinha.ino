#include <CarroRobo.h>

CarroRobo meuCarroRobo;

int sEsquerda;
int sCentro;
int sDireita;
bool ligado;

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

  // Sensor de Linha
  meuCarroRobo.SensorLinha.SetaPinoEsquerda(6);
  meuCarroRobo.SensorLinha.SetaPinoCentro(9);
  meuCarroRobo.SensorLinha.SetaPinoDireita(11);
  meuCarroRobo.SensorLinha.Ativar();

  meuCarroRobo.MudarVelocidade(200, 200);
  meuCarroRobo.LigarMotorAvancar();
}

void loop() {

  meuCarroRobo.SensorLinha.LerPinos(sEsquerda, sCentro, sDireita);
  int binarySensor = (sEsquerda*100) + (sCentro*10) + sDireita;
  //meuCarroRobo.MensagemSerial(binarySensor);
  //meuCarroRobo.MensagemSerial("\n");

  switch (binarySensor) {
      case  000 : meuCarroRobo.DesligarMotor(); ligado = false; break;
      case  101 : meuCarroRobo.LigarMotorAvancar(); ligado = true; break;
      case  001 :
      case  011 : meuCarroRobo.LigarMotorEsquerdaRetroceder();
                  meuCarroRobo.LigarMotorDireitaAvancar(); break;
      case  100 :
      case  110 : meuCarroRobo.LigarMotorDireitaRetroceder();
                  meuCarroRobo.LigarMotorEsquerdaAvancar(); break;
      case  111 : if(ligado){meuCarroRobo.LigarMotorAvancar();} break;
  }
  delay(100);
}
