#define F_CPU 8000000UL
#include<util/delay.h>
#include<avr/io.h>

void usart_init();
void send(char send);
char rec(void);
void main()
{
DDRC=0xff;
usart_init();
_delay_ms(10);
while(1)
{
char a;
a=rec();
_delay_ms(10);
  if(a=='F')
{PORTB=0b00001010;}
 
  else if(a=='B')
{PORTB=0b00000101;}
 
  else if(a=='R')
{PORTB=0b00000110;}
  
  else if(a=='L')
{PORTB=0b00001001;}
  
  else if(a=='S')
{PORTB=0x00;}

}
}
void usart_init()
{
  UBRRL=51;
 UBRRH=0;
 UCSRB=0x18;
 UCSRC=0x8e;
}


void send(char send)
 {
    while((UCSRA & 0x20)==0);
	UDR=send;
 }


char rec(void)
{
  while ((UCSRA & 0x80)==0);
  return UDR;
 }







