#pragma once
#include "../structures/bytestring.h"

bytestring* caesar_encrypt(bytestring* plaintext, uint8_t key);
bytestring* caesar_decrypt(bytestring* ciphertext, uint8_t key);

