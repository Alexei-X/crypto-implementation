#pragma once
#include <stdlib.h>
#include <stdint.h>
/*
 * Byte stream structrure representing string of bytes. I chose to use a vector data structure to store the bytes. 
 */
typedef struct bytestring {
    uint32_t size;
    uint32_t capacity;
    uint8_t* data;
} bytestring;

#define DEFAULT_CAPACITY 20

bytestring* create_bytestring();
bytestring* create_bytestring_capacity(uint32_t capacity);
void add_byte(bytestring* string, uint8_t byte);
void remove_byte(bytestring* string, size_t index);
void delete_bytestring(bytestring* string);
uint8_t byte_at(bytestring* string, size_t index);
void set_byte(bytestring* string, size_t index, uint8_t value);
void print_bstring(bytestring* string);
