#include <HOLA_MUNDO_PICC_.h>   ///CABECERA DONDE SE CONFIGURA EL PIC 

void LEE_B0()
{
 IF(INPUT(PIN_B0))  ///LEE EL PIN B0, SI ESTA EN 1 ENTRA EN LA FUNCION
 OUTPUT_HIGH(PIN_B1);  //// PRENDE EL LED EN EL PIN B1
 ELSE                  //// SI IF ES FALSO HACE ESTA FUNCION
 OUTPUT_LOW(PIN_B1);    ////APAGA EL LED 
 }
void J_LUCES_1()
{
OUTPUT_D(0B01010101);
delay_ms(200);
OUTPUT_D(0B10101010);
delay_ms(200);
}
void J_LUCES_2()
{
OUTPUT_D(0B11110000);
delay_ms(200);
OUTPUT_D(0B00001111);
delay_ms(200);
}
void main()
{
   while(TRUE)
   {
   for(int x=0;x<10;x++)
   J_LUCES_1 ();
   for( x=0;x<10;x++)
   J_LUCES_2 ();
   }
}



