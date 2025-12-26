#include "bytestring.h"
#include <stdio.h>
#include <stdlib.h>

void increase_bytestring(bytestring* string) {
    string->capacity = string->capacity*2;
    string->data = realloc(string->data, string->capacity*sizeof(uint8_t));
}

bytestring* create_bytestring() {
    bytestring* string = (bytestring*) malloc(sizeof(bytestring));
    string->capacity = DEFAULT_CAPACITY;
    string->size = 0;
    string->data = (uint8_t*) calloc(string->capacity, sizeof(uint8_t));
    return string;
}

bytestring* create_bytestring_capacity(uint32_t capacity) {
    bytestring* string = (bytestring*) malloc(sizeof(bytestring));
    string->capacity = capacity;
    string->size = 0;
    string->data = (uint8_t*) calloc(string->capacity, sizeof(uint8_t));
    return string;
}

void add_byte(bytestring *string, uint8_t byte) {
    if (string->size == string->capacity) {
        increase_bytestring(string);
    }
    string->data[string->size] = byte;
    string->size++;
}

void remove_byte(bytestring *string, size_t index) {
    size_t end = string->size - 1;
    for (size_t i = index; i < end; i++) {
        string->data[i] = string->data[i+1];
    }
    string->size--;
}

void delete_bytestring(bytestring *string) {
    free(string->data);
    free(string);
}

uint8_t byte_at(bytestring *string, size_t index) {
    return string->data[index];
}

void set_byte(bytestring* string, size_t index, uint8_t value) {
    string->data[index] = value; 
}

void print_bstring(bytestring *string) {
    for (size_t i = 0; i < string->size; i++) printf("%d", byte_at(string, i));
    printf("\n");
}

