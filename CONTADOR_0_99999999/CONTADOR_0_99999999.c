#include <CONTADOR_0_99999999.h>
byte CONST DISPLAY[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};

void main()
{
byte DIG1=0, DIG2=0,DIG3=0, DIG4=0,DIG5=0, DIG6=0,DIG7=0, DIG8=0;
output_C(0);
INT TIEMPO=1;
   while(TRUE)
   {
    for(DIG8=0;DIG8<10;DIG8++)
    {
    for(DIG7=0;DIG7<10;DIG7++)
    { 
     for(DIG6=0;DIG6<10;DIG6++)
    { 
     for(DIG5=0;DIG5<10;DIG5++)
    { 
     for(DIG4=0;DIG4<10;DIG4++)
    { 
     for(DIG3=0;DIG3<10;DIG3++)
    { 
     for(DIG2=0;DIG2<10;DIG2++)
    { 
     for(DIG1=0;DIG1<10;DIG1++)
    { 
    output_D(0x01);
    output_C(DISPLAY[DIG1]);
    delay_ms(TIEMPO);
    
    output_D(0x02);
    output_C(DISPLAY[DIG2]);
    delay_ms(TIEMPO);
    
    output_D(0x04);
    output_C(DISPLAY[DIG3]);
    delay_ms(TIEMPO);
    
    output_D(0x08);
    output_C(DISPLAY[DIG4]);
    delay_ms(TIEMPO);
    
    output_D(16);
    output_C(DISPLAY[DIG5]);
    delay_ms(TIEMPO);
    
    output_D(32);
    output_C(DISPLAY[DIG6]);
    delay_ms(TIEMPO);
    
    output_D(64);
    output_C(DISPLAY[DIG7]);
    delay_ms(TIEMPO);
    
    output_D(128);
    output_C(DISPLAY[DIG8]);
    delay_ms(50);
    }
    }
    }
    }
    }
    }
    }
    }
   }

}
