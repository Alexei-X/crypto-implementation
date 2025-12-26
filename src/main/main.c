#include "../historical/caesar_cipher.h"
#include <stdio.h>
#include "../RC4/RC4.h"
#include "../structures/bytestring.h"

int main() {
    bytestring* message = create_bytestring();
    bytestring* key = create_bytestring();
    for (int i = 0; i < 256; i++) {
        add_byte(key, (uint8_t) i);
    }
    RC4* rc4 = create_rc4(key);
    initialization(rc4);
    printf("Init done\n");
    bytestring* res = key_gen(rc4, 10);
    print_bstring(res);

    return 0;
}
