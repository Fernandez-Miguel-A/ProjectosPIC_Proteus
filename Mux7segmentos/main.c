#define         B1      RC0_bit
#define         B2      RC1_bit
#define         B3      RC2_bit
#define         B4      RC3_bit

#define         port_off()      PORTC=0b00000000  
#define         display         PORTD 


void main()
{
     int i, j;
     
     TRISC= 0;
     TRISD= 0;
     
     while (1){                   
           port_off();
           display = 118;       // H
           B1 = 1;
           Delay_ms(5);
           
           port_off();
           display = 63;       // O
           B2 = 1;
           Delay_ms(5);
           
           port_off();
           display = 56;       // L
           B3 = 1;
           Delay_ms(5);
           
           port_off();
           display = 119;      // A
           B4 = 1;
           Delay_ms(5);
     }
     
}