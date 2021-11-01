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

//https://naylampmechatronics.com/blog/25_tutorial-trasmisor-de-celda-de-carga-hx711-scale-digital.html
// hacerlo fisico
//https://www.taloselectronics.com/blogs/tutoriales/celda-de-carga-hx711


//-----------------------------------------------------------------------------
//Prototipo de funciones
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//Variabls Globales
//-----------------------------------------------------------------------------
// para sensor de peso
const int LOADCELL_DOUT_PIN = 23; // cambiar pines !!!
const int LOADCELL_SCK_PIN = 22;
HX711 scale;

//-----------------------------------------------------------------------------
//ISR
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Configuracion
//-----------------------------------------------------------------------------
void setup()
{
  // para modulo de peso
  Serial.begin(115200);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);


  Serial.print("Lectura del valor del ADC:  ");
  Serial.println(scale.read());
  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");
  scale.set_scale(439430.25); // Establecemos la escala
  scale.tare(20);  //El peso actual es considerado Tara.

  Serial.println("Listo para pesar");

}

//-----------------------------------------------------------------------------
//loop principal
//-----------------------------------------------------------------------------
void loop()
{
  Serial.print("Peso: ");
  Serial.print(scale.get_units(20), 3);
  Serial.println(" kg");
  delay(500);
}
//-----------------------------------------------------------------------------
//configuracion
//-----------------------------------------------------------------------------