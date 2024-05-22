#include "tests.h"
#include "lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define ASSERT_CC_ERR_ALLOC(x) ASSERT_EQ(x, CC_ERR_ALLOC)
#define ASSERT_CC_ERR_INVALID_CAPACITY(x) ASSERT_EQ(x, CC_ERR_INVALID_CAPACITY)
#define ASSERT_CC_ERR_INVALID_RANGE(x) ASSERT_EQ(x, CC_ERR_INVALID_RANGE)
#define ASSERT_CC_ERR_MAX_CAPACITY(x) ASSERT_EQ(x, CC_ERR_MAX_CAPACITY)
#define ASSERT_CC_ERR_KEY_NOT_FOUND(x) ASSERT_EQ(x, CC_ERR_KEY_NOT_FOUND)
#define ASSERT_CC_ERR_VALUE_NOT_FOUND(x) ASSERT_EQ(x, CC_ERR_VALUE_NOT_FOUND)
#define ASSERT_CC_ERR_OUT_OF_RANGE(x) ASSERT_EQ(x, CC_ERR_OUT_OF_RANGE)
#define ASSERT_CC_ITER_END(x) ASSERT_EQ(x, CC_ITER_END)

bool test_add() {
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 1))
    ASSERT_EQ(1, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 2))
    ASSERT_EQ(2, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1, 2]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 3))
    ASSERT_EQ(3, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1, 2, 3]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 4))
    ASSERT_EQ(4, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1, 2, 3, 4]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 5))
    ASSERT_EQ(5, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1, 2, 3, 4, 5]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 6))
    ASSERT_EQ(6, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1, 2, 3, 4, 5, 6]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 7))
    ASSERT_EQ(7, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1, 2, 3, 4, 5, 6, 7]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 8))
    ASSERT_EQ(8, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1, 2, 3, 4, 5, 6, 7, 8]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 9))
    ASSERT_EQ(9, cc_array_size(arr))
    ASSERT_EQ(16, cc_array_capacity(arr))
    //[1, 2, 3, 4, 5, 6, 7, 8, 9]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 10))
    ASSERT_EQ(10, cc_array_size(arr))
    ASSERT_EQ(16, cc_array_capacity(arr))
    //[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 11))
    ASSERT_EQ(11, cc_array_size(arr))
    ASSERT_EQ(16, cc_array_capacity(arr))
    //[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

    void* get_result;
    ASSERT_CC_OK(cc_array_get_at(arr, 0, &get_result))
    ASSERT_EQ(1, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 1, &get_result))
    ASSERT_EQ(2, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 2, &get_result))
    ASSERT_EQ(3, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 3, &get_result))
    ASSERT_EQ(4, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 4, &get_result))
    ASSERT_EQ(5, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 5, &get_result))
    ASSERT_EQ(6, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 6, &get_result))
    ASSERT_EQ(7, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 7, &get_result))
    ASSERT_EQ(8, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 8, &get_result))
    ASSERT_EQ(9, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 9, &get_result))
    ASSERT_EQ(10, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 10, &get_result))
    ASSERT_EQ(11, (int) get_result)
    
    cc_array_destroy(arr);
    return true;
}

bool test_add_at() {
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_add_at(arr, (void*) 1, 1))
    ASSERT_EQ(0, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 1, 0))
    ASSERT_EQ(1, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1]

    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_add_at(arr, (void*) 2, 2))
    ASSERT_EQ(1, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1, 2]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 2, 1))
    ASSERT_EQ(2, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[1, 2]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 3, 0))
    ASSERT_EQ(3, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[3, 1, 2]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 4, 0))
    ASSERT_EQ(4, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[4, 3, 1, 2]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 5, 1))
    ASSERT_EQ(5, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[4, 5, 3, 1, 2]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 6, 4))
    ASSERT_EQ(6, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[4, 5, 3, 1, 6, 2]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 7, 3))
    ASSERT_EQ(7, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[4, 5, 3, 7, 1, 6, 2]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 8, 2))
    ASSERT_EQ(8, cc_array_size(arr))
    ASSERT_EQ(8, cc_array_capacity(arr))
    //[4, 5, 8, 3, 7, 1, 6, 2]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 9, 5))
    ASSERT_EQ(9, cc_array_size(arr))
    ASSERT_EQ(16, cc_array_capacity(arr))
    //[4, 5, 8, 3, 7, 9, 1, 6, 2]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 10, 9))
    ASSERT_EQ(10, cc_array_size(arr))
    ASSERT_EQ(16, cc_array_capacity(arr))
    //[4, 5, 8, 3, 7, 9, 1, 6, 2, 10]

    ASSERT_CC_OK(cc_array_add_at(arr, (void*) 11, 3))
    ASSERT_EQ(11, cc_array_size(arr))
    ASSERT_EQ(16, cc_array_capacity(arr))
    //[4, 5, 8, 11, 3, 7, 9, 1, 6, 2, 10]

    void* get_result;
    ASSERT_CC_OK(cc_array_get_at(arr, 0, &get_result))
    ASSERT_EQ(4, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 1, &get_result))
    ASSERT_EQ(5, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 2, &get_result))
    ASSERT_EQ(8, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 3, &get_result))
    ASSERT_EQ(11, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 4, &get_result))
    ASSERT_EQ(3, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 5, &get_result))
    ASSERT_EQ(7, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 6, &get_result))
    ASSERT_EQ(9, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 7, &get_result))
    ASSERT_EQ(1, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 8, &get_result))
    ASSERT_EQ(6, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 9, &get_result))
    ASSERT_EQ(2, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 10, &get_result))
    ASSERT_EQ(10, (int) get_result)
    
    cc_array_destroy(arr);
    return true;
}

bool test_replace_at() {
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    void* get_result;
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_replace_at(arr, (void*) 1, 0, &get_result))
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_replace_at(arr, (void*) 1, 1, &get_result))

    ASSERT_CC_OK(cc_array_add(arr, (void*) 1))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 2))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 3))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 4))
    //[1, 2, 3, 4]

    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_replace_at(arr, (void*) 1, 4, &get_result))
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_replace_at(arr, (void*) 1, 5, &get_result))

    ASSERT_CC_OK(cc_array_replace_at(arr, (void*) 5, 2, NULL)) //[1, 2, 5, 4]
    ASSERT_CC_OK(cc_array_replace_at(arr, (void*) 6, 0, &get_result)) //[6, 2, 5, 4]
    ASSERT_EQ(1, (int) get_result)
    ASSERT_CC_OK(cc_array_replace_at(arr, (void*) 7, 3, NULL)) //[6, 2, 5, 7]

    ASSERT_CC_OK(cc_array_get_at(arr, 0, &get_result))
    ASSERT_EQ(6, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 1, &get_result))
    ASSERT_EQ(2, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 2, &get_result))
    ASSERT_EQ(5, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 3, &get_result))
    ASSERT_EQ(7, (int) get_result)

    cc_array_destroy(arr);
    return true;
}

bool test_swap_at() {
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 1))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 2))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 3))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 4))
    //[1, 2, 3, 4]

    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_swap_at(arr, 3, 4))
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_swap_at(arr, 3, 5))
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_swap_at(arr, 4, 3))
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_swap_at(arr, 4, 4))
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_swap_at(arr, 4, 5))
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_swap_at(arr, 5, 3))
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_swap_at(arr, 5, 4))
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_swap_at(arr, 5, 5))

    ASSERT_CC_OK(cc_array_swap_at(arr, 0, 3)) //[4, 2, 3, 1]
    ASSERT_CC_OK(cc_array_swap_at(arr, 1, 2)) //[4, 3, 2, 1]
    ASSERT_CC_OK(cc_array_swap_at(arr, 3, 2)) //[4, 1, 3, 2]
    ASSERT_CC_OK(cc_array_swap_at(arr, 2, 0)) //[3, 1, 4, 2]

    void* get_result;
    ASSERT_CC_OK(cc_array_get_at(arr, 0, &get_result))
    ASSERT_EQ(3, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 1, &get_result))
    ASSERT_EQ(1, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 2, &get_result))
    ASSERT_EQ(4, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 3, &get_result))
    ASSERT_EQ(2, (int) get_result)

    cc_array_destroy(arr);
    return true;
}

bool test_remove() {
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    ASSERT_CC_ERR_VALUE_NOT_FOUND(cc_array_remove(arr, (void*) 0, NULL))
    ASSERT_EQ(0, cc_array_size(arr))

    ASSERT_CC_OK(cc_array_add(arr, (void*) 1))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 2))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 3))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 4))
    //[1, 2, 3, 4]

    void* get_result;
    ASSERT_CC_ERR_VALUE_NOT_FOUND(cc_array_remove(arr, (void*) 5, &get_result))
    ASSERT_EQ(4, cc_array_size(arr))

    ASSERT_CC_OK(cc_array_remove(arr, (void*) 2, NULL)) //[1, 3, 4]
    ASSERT_EQ(3, cc_array_size(arr))

    ASSERT_CC_OK(cc_array_remove(arr, (void*) 4, &get_result)) //[1, 3]
    ASSERT_EQ(2, cc_array_size(arr))
    ASSERT_EQ(4, (int) get_result)

    ASSERT_CC_OK(cc_array_get_at(arr, 0, &get_result))
    ASSERT_EQ(1, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 1, &get_result))
    ASSERT_EQ(3, (int) get_result)

    cc_array_destroy(arr);
    return true;
}

bool test_remove_at() {
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_remove_at(arr, 0, NULL))
    ASSERT_EQ(0, cc_array_size(arr))

    ASSERT_CC_OK(cc_array_add(arr, (void*) 1))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 2))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 3))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 4))
    //[1, 2, 3, 4]

    void* get_result;
    ASSERT_CC_ERR_VALUE_NOT_FOUND(cc_array_remove(arr, (void*) 4, NULL))
    ASSERT_CC_ERR_VALUE_NOT_FOUND(cc_array_remove(arr, (void*) 5, &get_result))
    ASSERT_EQ(4, cc_array_size(arr))

    ASSERT_CC_OK(cc_array_remove_at(arr, 1, NULL)) //[1, 3, 4]
    ASSERT_EQ(3, cc_array_size(arr))

    ASSERT_CC_OK(cc_array_remove_at(arr, 2, &get_result)) //[1, 2]
    ASSERT_EQ(2, cc_array_size(arr))
    ASSERT_EQ(4, (int) get_result)

    ASSERT_CC_OK(cc_array_get_at(arr, 0, &get_result))
    ASSERT_EQ(1, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 1, &get_result))
    ASSERT_EQ(3, (int) get_result)

    cc_array_destroy(arr);
    return true;
}

bool test_remove_last() {
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_remove_last(arr, NULL))
    ASSERT_EQ(0, cc_array_size(arr))

    ASSERT_CC_OK(cc_array_add(arr, (void*) 1))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 2))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 3))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 4))
    //[1, 2, 3, 4]

    void* get_result;
    ASSERT_CC_OK(cc_array_remove_last(arr, NULL)) //[1, 2, 3]
    ASSERT_EQ(3, cc_array_size(arr))

    ASSERT_CC_OK(cc_array_remove_last(arr, &get_result)) //[1, 2]
    ASSERT_EQ(2, cc_array_size(arr))
    ASSERT_EQ(3, (int) get_result)

    ASSERT_CC_OK(cc_array_get_at(arr, 0, &get_result))
    ASSERT_EQ(1, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 1, &get_result))
    ASSERT_EQ(2, (int) get_result)

    cc_array_destroy(arr);
    return true;
}

bool test_remove_all(){
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 1))
    //[1]

    cc_array_remove_all(arr);
    ASSERT_EQ(0, cc_array_size(arr))

    cc_array_destroy(arr);
    return true;
}

bool test_remove_all_free(){
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 1))
    //[1]

    cc_array_remove_all_free(arr);
    ASSERT_EQ(0, cc_array_size(arr))

    cc_array_destroy(arr);
    return true;
}

bool test_get_at(){
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    ASSERT_CC_OK(cc_array_add(arr, (void*) 1))
    ASSERT_CC_OK(cc_array_add(arr, (void*) 2))
    //[1, 2]

    void* get_result;
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_get_at(arr, 2, &get_result))
    ASSERT_CC_ERR_OUT_OF_RANGE(cc_array_get_at(arr, 3, &get_result))

    ASSERT_CC_OK(cc_array_get_at(arr, 0, &get_result))
    ASSERT_EQ(1, (int) get_result)
    ASSERT_CC_OK(cc_array_get_at(arr, 1, &get_result))
    ASSERT_EQ(2, (int) get_result)

    cc_array_destroy(arr);
    return true;
}

bool test_get_last(){
    CC_Array* arr;

    ASSERT_CC_OK(cc_array_new(&arr))
    //[]

    void* get_result;
    ASSERT_CC_ERR_VALUE_NOT_FOUND(cc_array_get_last(arr, &get_result))

    ASSERT_CC_OK(cc_array_add(arr, (void*) 1)) //[1]

    ASSERT_CC_OK(cc_array_get_last(arr, &get_result))
    ASSERT_EQ(1, (int) get_result)

    ASSERT_CC_OK(cc_array_add(arr, (void*) 2)) //[1, 2]

    ASSERT_CC_OK(cc_array_get_last(arr, &get_result))
    ASSERT_EQ(2, (int) get_result)

    cc_array_destroy(arr);
    return true;
}


test_t TESTS[] = {
    &test_add,
    &test_add_at,
    &test_replace_at,
    &test_swap_at,
    &test_remove,
    &test_remove_at,
    &test_remove_last,
    &test_remove_all,
    &test_remove_all_free,
    &test_get_at,
    &test_get_last,
    NULL
};
