#include <DISPLAY_7_SEG_PICC.h>
///contador de 0 a 99
byte CONST DISPLAY[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};


void main()
{
byte un=0, dec=0;
output_b(0);
   while(TRUE)
   {
    for(dec=0;dec<10;dec++)
    {
    for(un=0;un<10;un++)
    { 
    output_a(0x02);
    output_b(DISPLAY[un]);
    delay_ms(50);
    //if(dec==0)
    //output_a(0x03);
    //else
    output_a(0x01);
    output_b(DISPLAY[dec]);
    delay_ms(50);
    }
    }
   }

}
