#include <stdint.h>
#define    state    1 // 0: pull-down, 1: pull-up

// :begin_X3

#define    te_read0    RD0_bit
#define    te_read1    RD1_bit
#define    te_read2    RD2_bit
#define    te_read3    RD3_bit

#define    te_Put0    RD4_bit
#define    te_Put1    RD5_bit
#define    te_Put2    RD6_bit
#define    te_Put3    RD7_bit

//:: char keypadPort at PORTX;
char keypadMode at TRISD;


uint8_t t_tecla1(void);
uint8_t t_tecla2(void);
uint8_t t_tecla3(void);
uint8_t t_tecla4(void);

uint8_t tecla_presionada(void);
uint8_t tecla_deco(void);
// :end_X3