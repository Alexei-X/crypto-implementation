#include "RC4.h"
#include <stdio.h>

RC4* create_rc4(bytestring* key) {
    RC4* res = malloc(sizeof(RC4));
    if (res == NULL) {
        printf("Error creating rc4 instance\n");
        return NULL;
    }
    res->S = create_bytestring_capacity(256);
    res->key = key;
    return res;
}

void initialization(RC4* rc4) {
    bytestring* key = rc4->key;
    for (uint8_t i = 0; i < 255; i++) {
        set_byte(rc4->S, (size_t) i, i);
    }
    size_t j = 0;
    for (uint8_t i = 0; i < 255; i++) {
        j = (j + byte_at(rc4->S, i) + byte_at(key, i%key->size))%256;
        uint8_t temp = byte_at(rc4->S, i);
        set_byte(rc4->S, i, byte_at(rc4->S, j));
        set_byte(rc4->S, j, temp);
    }
}

bytestring* key_gen(RC4* rc4, uint32_t out_size) {
    size_t i = 0; size_t j = 0; uint32_t k = 0;
    bytestring* result = create_bytestring_capacity(out_size);
    while (k < out_size) {
        i = (i + 1) % 256;
        j = (j + byte_at(rc4->S, i)) % 256;
        uint8_t temp = byte_at(rc4->S, i);
        set_byte(rc4->S, i, byte_at(rc4->S, j));
        set_byte(rc4->S, j, temp);
        uint8_t z = byte_at(rc4->S, (byte_at(rc4->S, i) + byte_at(rc4->S, j)) % 256);
        add_byte(result, z);
        k++;
    }
    return result;
}

