#pragma once
#include "../structures/bytestring.h"

typedef struct RC4 {
    bytestring* S;
    bytestring* key;
} RC4;

RC4* create_rc4(bytestring* key);
void initialization(RC4* rc4);
bytestring* key_gen(RC4* rc4, uint32_t out_size);

