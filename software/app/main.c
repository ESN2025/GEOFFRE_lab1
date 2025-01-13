#include "sys/alt_stdio.h"
#include "system.h"
#include "io.h"
#include "alt_types.h"
#include "sys/alt_irq.h"
#include "altera_avalon_pio_regs.h"
#include "alt_types.h"
#include "unistd.h"
#include "stdbool.h"

alt_u8 led_state = 0b01010101;
volatile bool run = 0;
volatile alt_u32 decount = 0;
volatile alt_8 dat = 0;

static void btn0_isr(void * context) {
    run = !run;
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BTN0_BASE, 0x1);    //ack irq
    IORD_ALTERA_AVALON_PIO_EDGE_CAP(BTN0_BASE);
}

int main() {
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BTN0_BASE, 0xf);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BTN0_BASE, 0x0);

    alt_ic_isr_register(BTN0_IRQ_INTERRUPT_CONTROLLER_ID, BTN0_IRQ, btn0_isr, 0x00, 0x00);
    alt_ic_irq_enable(BTN0_IRQ_INTERRUPT_CONTROLLER_ID, BTN0_IRQ);

    led_state = 0b00001111;

    while (1) {
         //alt_printf("dat: %x", dat);
         //alt_printf("val: %x\r\n", led_state);
         if(run == true){
             led_state = ((led_state >> 7) & 0x01) + (led_state << 1);
         }

         IOWR_ALTERA_AVALON_PIO_DATA(LED0_BASE, led_state);
         usleep(100000);
    }
    return 0;
}