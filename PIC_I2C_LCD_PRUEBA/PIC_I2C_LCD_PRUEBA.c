#include <PIC_I2C_LCD_PRUEBA.h>
#byte porta = 0xf80 // Identificador para el puerto A. 
#byte portb = 0xf81 // Identificador para el puerto B. 
#byte portc = 0xf82 // Identificador para el puerto C. 
#byte portd = 0xf83 // Identificador para el puerto D. 
#byte porte = 0xf84 // Identificador para el puerto E.
#use i2c(Master,Fast=100000, sda=PIN_D1, scl=PIN_D0,force_sw) 
#include <i2c_Flex_LCD.c>  
#include <Kbd.c>
INT X;
char k;
VOID LEER_A0()
{
float q;
float p;
set_adc_channel(0);
q=read_adc();
p=(4.9*q)/1023;
delay_ms(5);
LCD_GOTOXY(1,1);
PRINTF(LCD_PUTC,"A0:%4.1f",q);
LCD_GOTOXY(11,1);
PRINTF(LCD_PUTC,"V:%4.2f",p);
}
void main() { 
kbd_init();
portb_pullups(true);
setup_adc_ports(0);
setup_adc(adc_clock_internal);
lcd_init(0x4E  ,16,2);
lcd_backlight_led(ON); //Enciende la luz de Fondo
while (TRUE) { 
FOR( X=1;X<=10;X++)
{
LCD_GOTOXY(X-1,2);
LCD_PUTC("_");
LCD_GOTOXY(X,2);
LCD_PUTC("JOSE_ID");
DELAY_MS(250);
LEER_A0();
}

FOR( X=10;X>=1;X--)
{
LCD_GOTOXY(X+7,2);
LCD_PUTC("_");
LCD_GOTOXY(X,2);
LCD_PUTC("JOSE_ID");
DELAY_MS(250);
LEER_A0();
}

}    
} 
