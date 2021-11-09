//-----------------------------------------------------------------------------
//Universidad del Valle de Guatemala
//BE3015 Electronica Digital 2
//Karen Joachin
// Proyecto 2
//-----------------------------------------------------------------------------
//Librerias
//-----------------------------------------------------------------------------
#include <Arduino.h>
#include <HX711.h> //libreria ya esta en Arduino para pesa

//-----------------------------------------------------------------------------
//Definiciond de etiquetas
//-----------------------------------------------------------------------------
// https://naylampmechatronics.com/blog/25_tutorial-trasmisor-de-celda-de-carga-hx711-balanza-digital.html
//https://www.youtube.com/watch?v=WVNsZeqL81E&t=75s
//https://electronoobs.com/eng_arduino_tut115_code1.php


//-----------------------------------------------------------------------------
//Prototipo de funciones
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//Variabls Globales
//-----------------------------------------------------------------------------
// para sensor de peso
const int DOUT = 19;
const int CLK = 23;
HX711 balanza(DOUT, CLK);
//--------------------------

float pesoR = 0;// para variable que lee sensor y manda a tiva


//-----------------------------------------------------------------------------
//ISR
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Configuracion
//-----------------------------------------------------------------------------
void setup()
{
  // para modulo de peso
  Serial.begin(115200);  //  serial para monitor
  Serial2.begin(115200); // con TIVA

  Serial.print("Lectura del valor del ADC:t");
  Serial.println(balanza.read());
  Serial.println("No ponga ningún objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");

  balanza.set_scale(-182993.3962); // Establecemos el factor de calibracion. este fue el que funciono. se calibro con 4.75 kg
  balanza.tare(20);  //El peso actual es considerado Tara.

  Serial.println("Listo para pesar");

  // CON ESTA PARTE SE CALIBRA LA BALANZA ANTES DE USARLA
//  balanza.set_scale(); //La escala por defecto es 1
//  balanza.tare(20);  //El peso actual es considerado Tara.
//  Serial.println("Coloque un peso conocido:"); //*/
}

//-----------------------------------------------------------------------------
//loop principal
//-----------------------------------------------------------------------------
void loop()
{
  //Serial.print("Peso: ");
  // Serial.print(balanza.get_units(20), 3);
  pesoR = balanza.get_units(20), 3 ;
    
  //Serial.println(" kilogramos");
  // delay(500);
  //Serial.print(pesoR);
  //------------------------------------------
  // ESTA PARTE ES PARA CALIBRAR ANTES DE USAR
//  Serial.print("Valor de lectura: t");
//  Serial.println(balanza.get_value(10), 0);
//  delay(100);
  //-----------------------------------------

  // *************************UART de esp32******************************

  Serial2.println(pesoR); // envio datos como bytes este lo puedo cambiar a float despues

  //*********************************************************************

  // *************************UART de esp32******************************
  if (Serial2.available() > 0) {
    if (Serial2.read() == 1) {
      Serial.print("Peso recibido es: ");
      Serial.println(pesoR);
      Serial.println(" kilogramos");
    }
  }
  //*********************************************************************

}