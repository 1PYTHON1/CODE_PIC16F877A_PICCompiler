#include <LCD_PICC.h>
#include <lcd.c>
ENUM FUNCIONES{MED,CAL,INI};
VOID MEDIR()
{
output_toggle(PIN_C0);
}
VOID CALIBRAR()
{
output_toggle(PIN_C1);
}
VOID INICIALIZACION()
{
output_toggle(PIN_C2);
}
VOID RUN_FUN(INT NUMFUNC)
{
SWITCH(NUMFUNC)
{
CASE MED:
MEDIR();
BREAK;
CASE CAL:
CALIBRAR();
BREAK;
CASE INI:
INICIALIZACION();
BREAK;
}
}


void main()
{
   CHAR ITEM;
   CHAR N_MENUS=3;
   lcd_init();

   while(TRUE)
   {
   IF(INPUT(PIN_B0))
   {
   ITEM++;
   DELAY_MS(300);
   LCD_PUTC('\f');
   }
   IF(ITEM>(N_MENUS-1))
   ITEM=0;
   
   SWITCH(ITEM)
   {
   CASE 0:
   LCD_GOTOXY(1,1);
   PRINTF(LCD_PUTC,"MEDIR");
   LCD_GOTOXY(1,1);
   BREAK;
   CASE 1:
   PRINTF(LCD_PUTC,"CALIBRAR");
   LCD_GOTOXY(1,1);
   BREAK;
   CASE 2:
   PRINTF(LCD_PUTC,"INICIALIZAR");
   LCD_GOTOXY(1,1);
   BREAK;
   }
   IF(INPUT(PIN_B1))
   {
   DELAY_MS(300);
   RUN_FUN(ITEM);
   }
   

   }

}
