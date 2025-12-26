#include "bytestring_test.h"
#include <CUnit/Basic.h>
#include <CUnit/TestDB.h>

int main() {
    CU_initialize_registry();
    CU_pSuite bstring_suite = CU_add_suite("ByteStringTestSuite", 0, 0);
    CU_add_test(bstring_suite, "test of bytestring delete/create", test_create_bytestring);
    CU_add_test(bstring_suite, "test of bytestring add byte", test_byte_add);

    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
