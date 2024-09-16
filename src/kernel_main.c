// Jack Mulvihill

char glbl[128];

void kernel_main() {

    /* import values of bss start and end to the compiler */
    extern int __bss_start, __bss_end;

    /* create pointers for the start and end of the bss segment */
    char *bssstart, *bssend;

    /* assign addresses of bss start and end respectively to the pointers */
    bssstart = &__bss_start; //0x82000
    bssend = &__bss_end; // 0x83000

    /* write a for loop that sets all of the memory values to zero between the boundaries of bss start and end */
    for (char *ptr = bssstart; ptr < bssend; ptr++) {
         /* Set the value of all bss pointers to zero */
         *ptr = 0;
    }

    while(1){
    }
}
