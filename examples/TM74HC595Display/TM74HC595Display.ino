#include <TM74HC595Display.h>
#include <TimerOne.h>

//Pinos de conexao ao modulo
int PINO_SCLK = 7;
int PINO_RCLK = 6;
int PINO_DIO = 5;

int i = 0, j = 1, k = 2, l = 3;

TM74HC595Display disp(PINO_SCLK, PINO_RCLK, PINO_DIO);
unsigned char LED_0F[16];


void setup() {
  //Definicao dos digitos de 0 a 9
  LED_0F[0] = 0xC0; //0
  LED_0F[1] = 0xF9; //1
  LED_0F[2] = 0xA4; //2
  LED_0F[3] = 0xB0; //3
  LED_0F[4] = 0x99; //4
  LED_0F[5] = 0x92; //5
  LED_0F[6] = 0x82; //6
  LED_0F[7] = 0xF8; //7
  LED_0F[8] = 0x80; //8
  LED_0F[9] = 0x90; //9
  LED_0F[10] = 0x88; //A
  LED_0F[11] = 0x83; //b
  LED_0F[12] = 0xC6; //C
  LED_0F[13] = 0xA1; //d
  LED_0F[14] = 0x86; //E
  LED_0F[15] = 0x8E; //F
  

  Timer1.initialize(1500); // set a timer of length 1500
  Timer1.attachInterrupt(timerIsr); // attach the service routine here

  //Testes iniciais
  //Envia o numero 1 para o primeiro digito
  disp.set(LED_0F[1], 3);
  delay(1000);
  //Apaga o display
  disp.clearAll();

  //Envia o numero 2 para o primeiro digito
  disp.set(LED_0F[2], 2);
  delay(1000);
  disp.clearAll();

  //Envia o numero 3 para o primeiro digito
  disp.set(LED_0F[3], 1);
  delay(1000);
  disp.clearAll();

  //Envia o numero 4 para o primeiro digito
  disp.set(LED_0F[4], 0);
  delay(1000);
  disp.clearAll();
}

void loop(){
  //Mostra o valor do contador no display
  Serial.println(i);
  disp.digit(3, LED_0F[i++%16]);
  disp.digit(2, LED_0F[j++%16]);
  disp.digit(1, LED_0F[k++%16]);
  disp.digit(0, LED_0F[l++%16]);
  delay(1000);
}

void timerIsr() {
  disp.timerIsr();
}
