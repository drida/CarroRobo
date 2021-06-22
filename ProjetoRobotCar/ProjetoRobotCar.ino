#include <CarroRobo.h>

CarroRobo meuCarroRobo;

int sensorEsquerda;
int sensorCentro;
int sensorDireita;

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

  // Servo Motor
  meuCarroRobo.ServoMotor.SetaPinoSaida(3);
  meuCarroRobo.ServoMotor.Ativar();
  meuCarroRobo.ServoMotor.SetaAngulo(90);

  // Sensor de Linha
  meuCarroRobo.SensorLinha.SetaPinoEsquerda(6);
  meuCarroRobo.SensorLinha.SetaPinoCentro(9);
  meuCarroRobo.SensorLinha.SetaPinoDireita(11);

  // Sensor Infra Vermelho
  meuCarroRobo.InfraVermelho.SetaPino(12);

  meuCarroRobo.UltraSom.Ativar();
  meuCarroRobo.ServoMotor.Ativar();
  meuCarroRobo.SensorLinha.Ativar();
  meuCarroRobo.InfraVermelho.AtivarReceber();
  //meuCarroRobo.InfraVermelho.AtivarEnviar();
  
}

void loop() {

/*
  if (meuCarroRobo.InfraVermelho.Decodificar(&Resultado)){
    //Serial.println(Resultado.value, HEX);
    meuCarroRobo.MensagemSerial(Resultado.value);
    meuCarroRobo.InfraVermelho.LimparDecodificador();
  }

 
  meuCarroRobo.MudarVelocidade(150, 150);
  for (int i=0; i<5; i++) {
    meuCarroRobo.LigarMotorEsquerdaAvancar();
    delay(1000);
    meuCarroRobo.DesligarMotorEsquerda();
    meuCarroRobo.LigarMotorEsquerdaRetroceder();
    delay(500);
    meuCarroRobo.DesligarMotorEsquerda();
    meuCarroRobo.LigarMotorDireitaAvancar();
    delay(1000);
    meuCarroRobo.DesligarMotorDireita();
    meuCarroRobo.LigarMotorDireitaRetroceder();
    delay(1500);
    meuCarroRobo.DesligarMotorDireita();
  }
  meuCarroRobo.LigarMotorAvancar();
  delay(1000);
  meuCarroRobo.LigarMotorRetroceder();
  delay(1000);
  meuCarroRobo.DesligarMotor();
*/
  // Teste do Servo Motor atuando com o Ultra Som.
  for (int i=80;i<=100;i=i+10) {
    meuCarroRobo.MensagemSerial(i);
    meuCarroRobo.MensagemSerial("° de angulo.\n");
    meuCarroRobo.ServoMotor.SetaAngulo(i);
    double d = meuCarroRobo.UltraSom.MedirDistancia();
    meuCarroRobo.MensagemSerial(d);
    meuCarroRobo.MensagemSerial("cm de distancia.\n\n");
    delay(300);
  }
  //exit(0);
  
  // Teste dos sensores de Seguir Linha
  sensorEsquerda =  meuCarroRobo.SensorLinha.LerPinoEsquerda();
  meuCarroRobo.MensagemSerial(sensorEsquerda);
  meuCarroRobo.MensagemSerial(" esquerda.\n");
  sensorCentro =  meuCarroRobo.SensorLinha.LerPinoCentro();
  meuCarroRobo.MensagemSerial(sensorCentro);
  meuCarroRobo.MensagemSerial(" centro.\n");
  sensorDireita =  meuCarroRobo.SensorLinha.LerPinoDireita();
  meuCarroRobo.MensagemSerial(sensorDireita);
  meuCarroRobo.MensagemSerial(" direita.\n");
  delay(1000);
  
  meuCarroRobo.SensorLinha.LerPinos(sensorEsquerda, sensorCentro, sensorDireita);
  meuCarroRobo.MensagemSerial(sensorEsquerda);
  meuCarroRobo.MensagemSerial(" esquerda.\n");
  meuCarroRobo.MensagemSerial(sensorCentro);
  meuCarroRobo.MensagemSerial(" centro.\n");
  meuCarroRobo.MensagemSerial(sensorDireita);
  meuCarroRobo.MensagemSerial(" direita.\n");
  delay(1000);

 //exit(0);
}
