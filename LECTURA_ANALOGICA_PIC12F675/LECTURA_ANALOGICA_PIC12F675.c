#include <LECTURA_ANALOGICA_PIC12F675.h>
#use i2c(Master,Fast=100000, sda=PIN_A1, scl=PIN_A0,force_sw)
#include <i2c_Flex_LCD.c>

void main()
{
 lcd_init(0X4E,20,4);
 setup_adc_ports(sAN2);
 setup_adc(ADC_CLOCK_INTERNAL);
 INT16 analogico; 
 int8  temperatura;
   while(TRUE)
   {
      set_adc_channel(2);
      delay_ms(20);
      analogico = read_adc();
      temperatura = analogico * 5 * 100 / 1024;
      delay_ms(100);
      lcd_gotoxy(1,1);
      lcd_putc("JOSE ID 16/04/22");
      lcd_gotoxy(1,2);
      lcd_putc("TEMPERATURA:");
      delay_ms(200);
      printf(lcd_putc," %u ", temperatura);
      delay_ms(1000);

   }

}
