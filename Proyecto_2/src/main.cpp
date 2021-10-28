//-----------------------------------------------------------------------------
//Universidad del Valle de Guatemala
//BE3015 Electronica Digital 2
//Karen Joachin
// Proyecto 2
//-----------------------------------------------------------------------------
//Librerias
//-----------------------------------------------------------------------------
#include <Arduino.h>
#include "HX711.h" //libreria ya esta en Arduino 
//-----------------------------------------------------------------------------
//Definiciond de etiquetas
//-----------------------------------------------------------------------------
//variables para modulo de peso 

//https://naylampmechatronics.com/blog/25_tutorial-trasmisor-de-celda-de-carga-hx711-balanza-digital.html


//-----------------------------------------------------------------------------
//Prototipo de funciones
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//Variabls Globales
//-----------------------------------------------------------------------------
// para sensor de peso 
const int LOADCELL_DOUT_PIN = 25; // cambiar pines !!! 
const int LOADCELL_SCK_PIN = 26;

//-----------------------------------------------------------------------------
//ISR
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Configuracion
//-----------------------------------------------------------------------------
void setup()
{
// para modulo de peso 
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);


}

//-----------------------------------------------------------------------------
//loop principal
//-----------------------------------------------------------------------------
void loop()
{
  //configuracion para sensor 
  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }

  delay(1000);

}
//-----------------------------------------------------------------------------
//configuracion 
//-----------------------------------------------------------------------------

