#include "bytestring_test.h"
#include <CUnit/CUnit.h>

void test_create_bytestring() {
    bytestring* test_string1 = create_bytestring(); 
    CU_ASSERT(test_string1->capacity == DEFAULT_CAPACITY);
    CU_ASSERT(test_string1->size == 0);
    bytestring* test_string2 = create_bytestring_capacity(2456);
    CU_ASSERT(test_string2->capacity == 2456);
    delete_bytestring(test_string1);
    delete_bytestring(test_string2);
}

void test_byte_add() {
    bytestring* test_string = create_bytestring();
    add_byte(test_string, 58);
    add_byte(test_string, 23);
    add_byte(test_string, 0);
    add_byte(test_string, 255);
    CU_ASSERT(test_string->size == 4);
    for (uint8_t i = 0; i < 17; i++) {
        add_byte(test_string, i);
    }
    CU_ASSERT(test_string->capacity == 2*DEFAULT_CAPACITY);
}

