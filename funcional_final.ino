// INICIO Scope
#include <Servo.h>

// Fabiano
  Servo servoY;  // Movimenta para cima e para baixo
  Servo servoX; // Movimenta direita esquerda
  Servo servoZ; // Trem de pouso

  // Variáveis Constante
  const int tempo = 2000; // Tempo de esperar para zerar a variável
  const int servoYPin = 8;
  const int servoXPin = 9;
  const int servoZPin = 10;
  const int ledC = 11; // led cabine
  const int ledEmergencia = 12; // led de emergencia
  const int ledFarol = 13; // led acende farol
  const int pinoFalante = 7; // pino para buzzer
  const int tempoBuzzer = 10;
  int IN1 = 4;  // entrada motor 1
  int IN2 = 5;  // entrada motor 2

  // Variáveis
  int y = 84; // valor para centralizar em y o avião
  int x = 105; // valor para centralizar em x o avião
  int z = 30; // valor para centralizar o
  int frequencia = 0; // Inicia o buzzer
 
  char cod [1]; // para receber os dados do XBee e fazer a tratativa
  char recebido; // para receber o char apos a trataiva

  // Variáveis Boleanas
  boolean farolOn = false; // para controle de faróis
// FIM Scope

void setup() {
 Serial.begin(9600);
 // Fabiano
  servoY.attach (servoYPin);
  servoX.attach (servoXPin);
  servoZ.attach (servoZPin);
  servoY.write(y); // inicia o servo Y centralizado
  servoX.write(x); // inicia o servo X centralizado
  servoZ.write(z); // inicia o servo Z abaixado
  
 // Fim Fabiano
 
 // Inicio Led
  pinMode( ledC, OUTPUT );
  pinMode( ledEmergencia, OUTPUT );
  pinMode( ledFarol, OUTPUT );
  pinMode(IN1, OUTPUT); // motor 1
  pinMode(IN2, OUTPUT); // motor 2
 // Fim led
 
 // Inicio Buzzer
  pinMode( pinoFalante, OUTPUT );
 // Fim Buzzer
}

void loop() {
  if (Serial.available() > 0){
    for (int i = 0; i < 1; i++){
        cod [i] = Serial.read();
      }
   //INICIO Tratar o char recebido pelo XBee   
    for (int i = 0; i < 1; i++){
        if (cod [i] == 'd'){ // Recebe d => Para Decolar
            recebido = cod [i];
        }else if ( cod [i] == 'p'){ // Recebe p => Para Pousar
            recebido = cod [i];
        }else if ( cod [i] == 'c'){ // Recebe c => Centraliza o motor Y
            recebido = cod [i];
        }else if ( cod [i] == 'q' ) {// Recebe q => baixa o trem de pouso
          recebido = cod [i];
        }else if ( cod [i] == 'a' ) {// Recebe a => levanta o trem de pouso
          recebido = cod [i];
        }else if ( cod [i] == 'z' ) {// Recebe z => inclinar para direita o avião
          recebido = cod [i];
        }else if ( cod [i] == 'x' ) {// Recebe x => Inclinar para esquerda o avião
          recebido = cod [i];
        }else if ( cod [i] == 'w' ) {// Recebe w => Centraliza o motor X
          recebido = cod [i];
        }else if ( cod [i] == 'e' ) {// Recebe e => Para Acende led de emergencia
          recebido = cod [i];
        }else if ( cod [i] == 'b' ) {// Recebe b => Para ligar o buzzer
          recebido = cod [i];
        }else if ( cod [i] == 'f' ) {// Recebe f => Acende o led farol
          recebido = cod [i];
        }else if ( cod [i] == 'g' ) {// Recebe g => hélice sentido horário
          recebido = cod [i];
        }else if ( cod [i] == 'h' ) {// Recebe h => hélice sentido anti-horário
          recebido = cod [i];
        }else if ( cod [i] == 'j' ) {// Recebe j => desliga hélice 
          recebido = cod [i];   
         
    }}//FIM Tratar o char recebido pelo XBee   
   
  }
  // Executa os comando dependendo o que ele recebe enviado do XBee
  if ( recebido == 'p' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );
        servoYPousa ();
        y = 65;
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'd' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );  
        servoYDecola ();
        y = 103;
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'c' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );  
        servoYCentraliza(y);
        y = 84;
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'w' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );  
        servoXCentraliza(x);
        x = 105;
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'x' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );  
        servoXEsquerda();
        x = 80;
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'z' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );  
        servoXDireita();
        x = 135;
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'q' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );  
        servoZBaixaTrem();
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'a' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );  
        servoZLevantaTrem();
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'e' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );  
        emergengia(ledEmergencia);
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'f' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );  
        farol(ledFarol);
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'b' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );  
        buzzer(pinoFalante);
        delay ( tempo );
        recebido = ' ';
    }else if ( recebido == 'g' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );
        heliceHorario();
        recebido = ' ';
    }else if ( recebido == 'h' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );
        heliceAntiHorario();
        recebido = ' ';
    }else if ( recebido == 'j' ){
        Serial.print("Recebido: ");
        Serial.println( recebido );
        desligaHelice();
        recebido = ' ';
    }
    // Executa os comando dependendo o que ele recebe enviado do XBee

}
//INICIO Declara as funções

 // INICIO Função que pousa o avião
  void servoYPousa (){
  for (int pos = 84; pos > 65; pos--){
      servoY.write(pos);
      delay(30);
  }  
  }// FIM Função que pousa o avião
 
  //INICIO servoYDecola -> Para decolar o avião
  void servoYDecola (){
  for (int pos = 84; pos < 103; pos++){
    servoY.write(pos);
    delay(30);
  }  
  }//FIM servoYDecola -> Para decolar o avião

  //INICIO servoYCentraliza -> Centraliza o motor em Y dependete da posição dele
  void servoYCentraliza( int y ){
  int pos  = y;
  if (pos == 65){
      for (int i = pos; i < 84; i++){
        servoY.write(i);
        delay(30);
      }  
  }else if (pos == 103){
      for (int i = pos; i > 84; i--){
        servoY.write(i);
        delay(30);
      }  
  }else {
      Serial.println("Avião já esta centralizado em Y");
    }
     
  }//FIM servoYCentraliza -> Centraliza o motor em Y dependete da posição dele

  //INICIO servoXCentraliza -> Centraliza o motor em X dependete da posição dele
  void servoXCentraliza( int x ){
      int pos  = x;
      if (pos == 135){
          for (int i = pos; i > 105; i--){
            servoX.write(i);
            delay(30);
          }  
      }else if (pos == 80){
          for (int i = pos; i < 105; i++){
            servoX.write(i);
            delay(30);
          }  
      }else {
          Serial.println("Avião já esta centralizado em X");
        }
         
  }//FIM servoXCentraliza -> Centraliza o motor em X dependete da posição dele

  //INICIO Função que Incliniar o avião para Direita
    void servoXDireita ( ){
        for (int pos = 105; pos < 135; pos++){
          servoX.write(pos);
          delay(30);
        }    
    }//FIM Função que Incliniar o avião para Direita

  //INICIO Função que Incliniar o avião para Esquerda
    void servoXEsquerda ( ){
      for (int pos = 105; pos > 80; pos--){
          servoX.write(pos);
          delay(30);
        }    
    }//FIM Função que Incliniar o avião para Direita

    //INICIO Função que Levanta o trem de pouso do avião
      void servoZLevantaTrem(){
        for (int pos = 30 ; pos < 130; pos++){
            servoZ.write(pos);
            delay(30);  
          }
      }//FIM Função que Levanta o trem de pouso do avião

    //INICIO Função que Baixa o trem de pouso do avião
        void servoZBaixaTrem(){
          for (int pos = 130; pos > 30; pos--){
              servoZ.write(pos);
              delay(30);     
          }
        }//FIM Função que Baixa o trem de pouso do avião

    //INICIO Função luz de emergencia
        void emergengia( int ledEmergencia){
            Serial.println("Não entre em pânico");
            for (int i = 0; i < 30; i++){
              Serial.println("Estado de emergencia");
              digitalWrite( ledEmergencia, HIGH );
              delay ( 200 );
              digitalWrite( ledEmergencia, LOW );
              delay ( 200 );  
            }
        }//FIM Função luz de emergencia   

    //INICIO Função Liga Faróis
        void farol( int ledFarol ){
          if( farolOn == false){
              digitalWrite ( ledFarol, HIGH );
              farolOn = true;
          }else if (farolOn == true){
              digitalWrite ( ledFarol, LOW );
              farolOn = false;
          }
        }//Fim Função liga Faróis
                     
    //INCIO Função liga Buzzer
        void buzzer( int pinoFalante){
          for (frequencia = 150; frequencia < 5000; frequencia++ ){
              tone( pinoFalante, frequencia, tempoBuzzer );
              delay(1);
            }
            for ( frequencia = 5000; frequencia > 150; frequencia-- ){
              tone( pinoFalante, frequencia, tempoBuzzer );
              delay(1);
            }
           
        }//FINAL Função liga Buzzer
     //INCIO Função Helice sentido horario
     void heliceHorario(){
     //Gira o Motor A no sentido horario
       digitalWrite(IN1, HIGH); // 5vcc
       digitalWrite(IN2, LOW); //  0vcc
       delay(5000);
     } // FIM Helice sentido horario
     
     //INCIO Função Helice sentido anti-horario
     void heliceAntiHorario(){
     //Gira o Motor A no sentido anti-horario
       digitalWrite(IN1, LOW); // 0vcc
       digitalWrite(IN2, HIGH);  //5vcc
       delay(5000);
     } // FIM Helice sentido horario

        //INCIO Função Desliga Helice
     void desligaHelice(){
     //Para o motor A
       digitalWrite(IN1, HIGH);  //5vcc
       digitalWrite(IN2, HIGH);  //5vcc
       delay(5000);
     } // FIM Desliga Helice 
//FIM Declara as funções
