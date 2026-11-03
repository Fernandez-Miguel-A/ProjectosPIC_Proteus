
#define    state    1 // 0: pull-down, 1: pull-up

// :begin_X3

#define    te_c1    RD0_bit
#define    te_c2    RD1_bit
#define    te_c3    RD2_bit
#define    te_c4    RD3_bit


uint8_t t_tecla1(void);
uint8_t t_tecla2(void);
uint8_t t_tecla3(void);
uint8_t t_tecla4(void);

uint8_t tecla_presionada(void);
uint8_t tecla_deco(void);
// :end_X3