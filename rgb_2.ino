#include <Adafruit_NeoPixel.h>
#include <Wire.h>
int BRILLO;
int POT = 0;        // potenciometro en pin A0
int ROJO;
int POT1 = 3;        // potenciometro en pin A1
int AZUL;
int POT2 = 2;        // potenciometro en pin A2
int VERDE;
int POT3 = 1;        // potenciometro en pin A3
int parpadeoI = 0;
int parpadeoD = 0;
Adafruit_NeoPixel tira = Adafruit_NeoPixel(64,8,NEO_GRB + NEO_KHZ800);
void setup() {
   // Iniciar comunicación serie
  Serial.begin(9600);
   tira.begin();
    delay(20);
    Serial.print('\n'); 
    Serial.println("Neopixel test"); 
    INICIO(); 
}

void loop() {
  
  if ((analogRead(POT1) / 4) < 5 ){
    Serial.print("Auto ");
    Serial.print('\n');  
    tira.clear();                         // restablece todos los pixeles en apagado
    tira.setBrightness(230); 
    for(int i = 64; i >= 0; i--){         // bucle para recorrer posiciones 64 a 0
      tira.setPixelColor(i, 255,255,255); // cada pixel en color rojo (posicion,R,G,B)
      tira.show();                        // muestra datos en pixel
      delay(40);
    }
  }
  else {
    Serial.print('\n'); 
    Serial.print("Custom "); 
    CUSTOM();
    }

}

void INICIO(){
  Serial.print("INICIO ");
  Serial.print('\n'); 
  tira.setBrightness(20);               // brillo global para toda la tira

  for(int i = 0; i < 64; i++){          // bucle para recorrer posiciones 0 a 64
    tira.setPixelColor(i, 20, 150, 255);   // cada pixel en color azul (posicion,R,G,B)
    tira.show();                        // muestra datos en pixel 
    delay(40);                          // breve demora de medio segundo
  }
  tira.clear();                         // restablece todos los pixeles en apagado
   for(int i = 64; i >= 0; i--){         // bucle para recorrer posiciones 64 a 0
    tira.setPixelColor(i, 255,51,218);   // cada pixel en color rojo (posicion,R,G,B)
    tira.show();                        // muestra datos en pixel
    delay(40);                         // breve demora de medio segundo  
  }

  tira.clear(); 
  Serial.print("END INICIO ");
  Serial.print('\n'); 
}  


void CUSTOM(){
  int j;
  ROJO   = analogRead(POT1) / 4; 
  VERDE  = analogRead(POT2) / 4; 
  AZUL   = analogRead(POT3) / 4; 
  BRILLO = analogRead(POT) / 4; 
  Serial.print('\n');  
  Serial.print("COLORES R: ");
  Serial.print(ROJO);
  Serial.print(" G: ");
  Serial.print(VERDE);
  Serial.print(" B: ");
  Serial.print(AZUL);
  Serial.print(" BRILLO: ");
  Serial.print(BRILLO);
  for (j = 0;j < 64; j++){
    tira.setBrightness(BRILLO);
    tira.setPixelColor(j,ROJO,VERDE,AZUL);
    tira.show();
    delay(20);
  }
}
