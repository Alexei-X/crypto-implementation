#include "../historical/caesar_cipher.h"
#include "../structures/bytestring.h"

int main() {
    bytestring* message = create_bytestring();
    add_byte(message, 193);
    print_bstring(message);

    bytestring* cipher = caesar_encrypt(message, 2);
    print_bstring(cipher);

    return 0;
}
