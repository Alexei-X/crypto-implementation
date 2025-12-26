#include "caesar_cipher.h"

bytestring* caesar_encrypt(bytestring* plaintext, uint8_t key) {
    bytestring* ciphertext = create_bytestring_capacity(plaintext->capacity);
    for (size_t i = 0; i < plaintext->size; i++) {
        uint8_t new_val = (byte_at(plaintext, i)+key)%256;
        add_byte(ciphertext, new_val);
    }
    return ciphertext;
}

bytestring* caesar_decrypt(bytestring* ciphertext, uint8_t key) {
    bytestring* plaintext = create_bytestring_capacity(ciphertext->capacity);
    for (size_t i = 0; i < ciphertext->size; i++) {
        uint8_t new_val = (byte_at(ciphertext, i)-key)%256;
        add_byte(plaintext, new_val);
    }
    return plaintext;
}

