#include "bytestring_test.h"
#include "caesar_cipher_test.h"
#include <CUnit/Basic.h>
#include <CUnit/CUError.h>
#include <CUnit/TestDB.h>

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    CU_pSuite bstring_suite = CU_add_suite("ByteStringTestSuite", 0, 0);
    if (bstring_suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_add_test(bstring_suite, "test of bytestring delete/create", test_create_bytestring);
    CU_add_test(bstring_suite, "test of bytestring add byte", test_byte_add);
    CU_add_test(bstring_suite, "test of bytestring remove byte", test_remove_byte);
    CU_add_test(bstring_suite, "test of bytestring byte_at", test_byte_at);
    CU_add_test(bstring_suite, "test of bytestring set byte", test_set_byte);

    CU_pSuite caesar_suite = CU_add_suite("CaesarCipherTestSuite", 0, 0);
    if (caesar_suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_add_test(caesar_suite, "test of caesar encrypt", test_caesar_encrypt);
    CU_add_test(caesar_suite, "test of caesar decrypt", test_caesar_decrypt);

    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
