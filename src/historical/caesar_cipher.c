#include "caesar_cipher.h"

bytestring* caesar_encrypt(bytestring* plaintext, uint8_t key) {
    bytestring* ciphertext = create_bytestring_capacity(plaintext->capacity);
    for (size_t i = 0; i < plaintext->size; i++) {
        uint8_t new_val = (byte_at(plaintext, i)+key)%255;
        add_byte(ciphertext, new_val);
    }
    return ciphertext;
}

bytestring* caesar_decrypt(bytestring* ciphertext, uint8_t key) {
    return caesar_encrypt(ciphertext, key);
}

