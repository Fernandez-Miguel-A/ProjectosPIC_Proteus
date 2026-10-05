void main() {
    unsigned short i = 0;

    // 1. Configurar pines como salidas digitales
    TRISC.F2 = 0;       // RC2 es la salida física habitual para PWM1 en muchos PICs (ej. PIC16F887)

    // 2. Inicializar el módulo PWM1 a una frecuencia alta (ej. 5 kHz)
    // Una frecuencia alta facilita el filtrado RC.
    PWM1_Init(5000);

    // 3. Iniciar el módulo PWM1
    PWM1_Start();

    while (1) {
        // Generar una rampa ascendente de voltaje
        // El ciclo de trabajo (Duty Cycle) va de 0 (0V) a 255 (5V)
        for (i = 0; i < 255; i++) {
            PWM1_Set_Duty(i);  // Cambia el valor analógico de salida
            Delay_ms(10);      // Controla la velocidad de la rampa
        }
        
        // Generar una rampa descendente de voltaje
        for (i = 255; i > 0; i--) {
            PWM1_Set_Duty(i);
            Delay_ms(10);
        }
    }
}
