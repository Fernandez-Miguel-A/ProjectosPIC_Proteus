
  
  
//Declaración de varíales.
float x0, y0;
unsigned int YY;
  //Declaración de la función de interrupciones.
  
void interrupt() iv 0x0008  ics ICS_AUTO
{
    if( INTCON.F2 ){
      TMR0L=135;
      //Timer0 con periodo de 774,4u segundo.
      // Fs = 1291,32 Hz.
      //Adquisición de una muestra de 10 bits en, x[0].
      x0 = (float)(ADC_Read(0)-512.0*2);
      //
      //Espacio para procesar la señal.
      //
      //Reconstrucción de la señal: y en 10 bits.
      YY = (unsigned int)(x0+512*2);
      PORTC = (YY>>8)&3;
      PORTB = YY&255;
      INTCON.F2=0;
    }
}


void main( void )
{
    //Inicio del puerto B como salida.
    TRISB = 0;
    TRISC = 0;

    PORTB = 0;
    PORTC = 0;
    //Se configura el TIMER 0, su interrupción.
    INTCON = 0b10100000;
    T0CON = 0b11000101;
    
    //TMR0ON_bit = 1;
    
    while(1)//Bucle infinito.
    {
        //PORTB = 0xff;
    }
}