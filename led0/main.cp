#line 1 "C:/Users/FernandezMiguelA/Documents/STM32/led0/main.c"
#line 1 "c:/mikroelektronika/mikroc_pro_for_pic/include/stdio.h"
#line 1 "c:/mikroelektronika/mikroc_pro_for_pic/include/stdlib.h"







 typedef struct divstruct {
 int quot;
 int rem;
 } div_t;

 typedef struct ldivstruct {
 long quot;
 long rem;
 } ldiv_t;

 typedef struct uldivstruct {
 unsigned long quot;
 unsigned long rem;
 } uldiv_t;

int abs(int a);
float atof(char * s);
int atoi(char * s);
long atol(char * s);
div_t div(int number, int denom);
ldiv_t ldiv(long number, long denom);
uldiv_t uldiv(unsigned long number, unsigned long denom);
long labs(long x);
int max(int a, int b);
int min(int a, int b);
void srand(unsigned x);
int rand();
int xtoi(char * s);
#line 1 "c:/mikroelektronika/mikroc_pro_for_pic/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;



typedef signed char int_fast8_t;
typedef signed int int_fast16_t;
typedef signed long int int_fast32_t;


typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;


typedef signed int intptr_t;
typedef unsigned int uintptr_t;


typedef signed long int intmax_t;
typedef unsigned long int uintmax_t;
#line 7 "C:/Users/FernandezMiguelA/Documents/STM32/led0/main.c"
uint8_t segment[10]={
63,6,91,79,102,109,125,7,255,103
};



void main()
{
 uint8_t i,j;
 TRISD = 0x00;

 while (1){
 PORTD = 0x00;
 Delay_ms(1000);
#line 47 "C:/Users/FernandezMiguelA/Documents/STM32/led0/main.c"
 i = 0;
 for(; i< 8; i++){
 PORTD = 1<<i;
 Delay_ms(1000);
 }
 j = 0;
 for(; j< 10; j++){
 PORTD = segment[j];
 Delay_ms(1000);
 }
 }
}
