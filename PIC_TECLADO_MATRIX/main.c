#include <main.h>
#define LCD_ENABLE_PIN  PIN_D2                                   ////
#define LCD_RS_PIN      PIN_D0                                 ////
#define LCD_RW_PIN      PIN_D1                                    ////
#define LCD_DATA4       PIN_D4                                    ////
#define LCD_DATA5       PIN_D5                                    ////
#define LCD_DATA6       PIN_D6                                    ////
#define LCD_DATA7       PIN_D7  
#INCLUDE<LCD.C>
#define use_portb_kbd 
#INCLUDE<Kbd4x4.c>
void main()
{
char k;
int x;
lcd_init();
kbd_init();
port_b_pullups(0xff);
lcd_gotoxy(1,1);
lcd_putc("TECLADO CHAR");
lcd_gotoxy(1,2);
   while(TRUE)
   {
   k = kbd_getc();
   x=k-48;
   if(k!=0)
   {
   if(k=='*')
   lcd_putc( "\f" );
   ELSE
   LCD_PUTC(k);
   delay_ms(500);
   }
      
   }

}
////descomentar para programar el pic
/*#use i2c(Master,Fast=100000, sda=PIN_D1, scl=PIN_D0,force_sw) 
#include <i2c_Flex_LCD.c>  
#define use_portb_kbd 
#include <Kbd4x4.c>
INT x;
char k;
float q;
float p;
VOID LEER_A0()
{
set_adc_channel(0);
q=read_adc();
p=(4.9*q)/1023;
LCD_GOTOXY(1,1);
PRINTF(LCD_PUTC,"A0:%4.1f",q);
LCD_GOTOXY(11,1);
PRINTF(LCD_PUTC,"V:%4.2f",p);
}
void caracter()
{
    k = kbd_getc();
   LCD_GOTOXY(1,2);
   x=k-48;
   if(k!=0)
   {
   if(k=='*')
   lcd_putc( "\f" );
   ELSE
   LCD_PUTC(k);
   delay_ms(10);
   }
   }
void main() { 
port_b_pullups(0XFF);
kbd_init();
setup_adc_ports(0);
setup_adc(adc_clock_internal);
lcd_init(0x4E  ,16,2);
lcd_backlight_led(ON); //Enciende la luz de Fondo
while (TRUE) { 
caracter();
}    
} 
*/
