#include "caesar_cipher_test.h"
#include <CUnit/CUnit.h>

void test_caesar_encrypt() {
    bytestring* string1 = create_bytestring();
    for (uint8_t i = 0; i < 255; i++) {
        add_byte(string1, i);
    }
    bytestring* cipher1 = caesar_encrypt(string1, 3);
    for (uint8_t i = 0; i < 255; i++) {
        CU_ASSERT(byte_at(cipher1, i) == (i+3)%256);
    }
    delete_bytestring(string1);
    delete_bytestring(cipher1);
}

void test_caesar_decrypt() {
    bytestring* string1 = create_bytestring();
    for (uint8_t i = 0; i < 255; i++) {
        add_byte(string1, 255-i);
    }
    bytestring* cipher1 = caesar_encrypt(string1, 14);
    bytestring* string2 = caesar_decrypt(cipher1, 14);
    for (uint8_t i = 0; i < 255; i++) {
        CU_ASSERT(byte_at(string2, i) == byte_at(string1, i));
    }

    delete_bytestring(string1);
    delete_bytestring(string2);
    delete_bytestring(cipher1);
}
