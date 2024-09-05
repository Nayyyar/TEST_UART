#pragma warning disable 520,2053
#include "mcc_generated_files/system/system.h"

// dev branch

void UART1_sendString(const char *str) {
    while (*str) {
        while (!(UART1_IsTxReady()));
        UART1_Write(*str++);
        while (!UART1_IsTxDone());
    }
}

int main(void) {
    SYSTEM_Initialize();

    while (1) {

         UART1_sendString("\n------------ HELLO WORLD ----------\n");
         __delay_ms(1000);
    }
}