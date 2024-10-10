// Jack Mulvihill

char glbl[128];

unsigned long get_timer_count() {
    unsigned long *timer_count_register = 0x3f003004;
    return *timer_count_register;
}

void kernel_main() {

    /* import values of bss start and end to the compiler */
    extern int __bss_start, __bss_end;

    /* make pointers for start and end of bss segment assign addresses 
       of bss start and end respectively to the pointers */
    char *bssstart = &__bss_start; //0x82000
    char *bssend = &__bss_end; // 0x83000

    /* write a for loop that sets all of the memory values to zero between the boundaries of bss start and end */
    for (char *i = bssstart; i < bssend; i++) {
         /* Set the value of all bss pointers to zero */
         *i = 0;
    }

    while(1){
    }
    esp_printf(putc, "Current Execution Level is %d\r\n", getEL());
} // method kernel_main
