/*
   Autor: Freddy Quispe Tello.
   Fecha: 25-07-2015
*/
/*
//directivas 
#define PCF_SDA  PIN_C2
#define PCF_SCL  PIN_C1
#use i2c(master, sda=PCF_SDA, scl=PCF_SCL)
#define PCF_ID   7
#define PCF      64  // Puede ser 112 ó 64 (PCF8574T=64, PCF8574A=112, PCF8574=64)
#define blacking  P3
#define LCD_RS    P0
#define LCD_RW    P1 
#define LCD_E     P2
#define LCD_DB4   P4
#define LCD_DB5   P5
#define LCD_DB6   P6
#define LCD_DB7   P7
///////////////

......................................
*******************************************************************************
*******************************************************************************
Const char Letra1[8]={0b11011,0b11011,0b00000,0b11111,0b10001,0b10001,0b01110,0b00000};
      lcd_init();   // Para iniciar el LCD, se declara antes de su utilizacion
      lcd_gotoxy(columna, fila) // lcd_gotoxy(1,1); primera posicion de la fila 1, lcd_gotoxy(2,1) segunda posicion de la fila 2
      lcd_putc("Mensaje");
      Claer_LCD();         // Borra la LCD
      ////////////////////////////CGRAM
      CGRAM_x(n);         // Donde n es la posicion en donde se escribiran los caracteres, va de 0 a 7
      for(i=0;i<=7 ;i++) lcd_send_byte(1,Letra1[i]);  // E una vez definido la funcion, envia lo 8bytes,
       CGRAM(0); // Muestra el caracter especial almacenado en la posicion 0;
*/
#define P0   1
#define P1   2
#define P2   4
#define P3   8
#define P4   16
#define P5   32
#define P6   64
#define P7   128
#define LCD_LINE_1_ADDRESS 0x00 
#define LCD_LINE_2_ADDRESS 0x40 
#define LCD_LINE_3_ADDRESS 0x14 
#define LCD_LINE_4_ADDRESS 0x54 
void Write_PCF(char dato){
  
   i2c_start();
   i2c_write((PCF_ID<<1)|PCF);
   i2c_write(dato|blacking );
   i2c_stop();
      
}
void Send_D7_D4(int8 address,int8 nibble)
{  
   char datos;

  if((nibble & 1)==1) datos= datos|LCD_DB4; else datos = datos&~LCD_DB4;
  if((nibble & 2)==2) datos= datos|LCD_DB5; else datos = datos&~LCD_DB5;
  if((nibble & 4)==4) datos= datos|LCD_DB6; else datos = datos&~LCD_DB6;
  if((nibble & 8)==8) datos= datos|LCD_DB7; else datos = datos&~LCD_DB7;
   delay_us(60);
   if(address)
      datos= datos |LCD_RS;
      
   else
     datos = datos &~LCD_RS; 
      

Write_PCF( datos | LCD_E);
 delay_us(2);
 Write_PCF( datos & ~LCD_E);
}
void lcd_send_byte(int8 address, int8 n)
{
   Send_D7_D4(address,n >> 4);
   Send_D7_D4(address,n & 0xf);
}
void lcd_init(void)
{
int8 i;
i2c_start();
   i2c_write((PCF_ID<<1)|PCF);
   i2c_write(0x00);
   i2c_stop();
delay_ms(15);

for(i=0 ;i < 3; i++)
   {
    Send_D7_D4(0,0x03);
    delay_ms(5);
   }
    Send_D7_D4(0,0x02);
    lcd_send_byte(0, 0x28);
    delay_ms(5);
    lcd_send_byte(0, 0x08);
    delay_ms(5);
    lcd_send_byte(0, 0x01);
    delay_ms(5);
    lcd_send_byte(0, 0x06);
    delay_ms(5);
    lcd_send_byte(0, 0x0C);
}
void lcd_gotoxy(int8 x, int16 y)
{
int16 address;

switch(y) 
  { 
   case 1: 
     address = LCD_LINE_1_ADDRESS; 
     break; 

   case 2: 
     address = LCD_LINE_2_ADDRESS; 
     break; 

   case 3: 
     address = LCD_LINE_3_ADDRESS; 
     break; 

   case 4: 
     address = LCD_LINE_4_ADDRESS; 
     break; 

   default: 
     address = LCD_LINE_1_ADDRESS; 
     break; 
      
  } 
address += x-1;
lcd_send_byte(0, 0x80 | address);
}
void lcd_putc(char c)
{

 switch(c)
   {
    case '\f':
     lcd_send_byte(0,1);
      delay_ms(2);
      break;

    case '\n':
       lcd_gotoxy(1,2);
       break;
    default:
       lcd_send_byte(1,c);
       break;
   }
   
}
void Clear_LCD(){
     lcd_send_byte(0,1);
     delay_ms(2); 
}
void CGRAM(int8 n){
   lcd_send_byte(1,n);
}
void CGRAM_x(int p){
lcd_send_byte(0,0x40+p*8);
}
