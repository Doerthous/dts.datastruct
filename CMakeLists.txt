cmake_minimum_required(VERSION 3.15)

project(A)

add_executable(main 
    test/main.cpp 
    dts_datastruct_list.c 
    dts_datastruct_bt.c 
    dts_datastruct_bst.c 
    dts_datastruct_rbt.c
)
target_include_directories(main PRIVATE .)

add_executable(list_test 
    test/dts_datastruct_list_test.c 
    dts_datastruct_list.c
)
target_include_directories(list_test PRIVATE .)

add_executable(qsort_test 
    test/dts_algorithm_qsort_test.c 
    dts_algorithm_qsort.c
)
target_include_directories(qsort_test PRIVATE .)

add_executable(kdt_test 
    test/dts_datastruct_kdt_test.c 
    dts_algorithm_qsort.c 
    dts_datastruct_kdt.c 
    dts_datastruct_list.c 
    dts_datastruct_bt.c
)
target_include_directories(kdt_test PRIVATE .)

add_executable(bst_test 
    test/dts_datastruct_bst_test.c 
    dts_datastruct_bst.c 
    dts_datastruct_bt.c 
    dts_datastruct_list.c
)
target_include_directories(bst_test PRIVATE .)

add_executable(rbt_test 
    test/dts_datastruct_rbt_test.c 
    dts_datastruct_rbt.c 
    dts_datastruct_bst.c 
    dts_datastruct_bt.c 
    dts_datastruct_list.c
)
target_include_directories(rbt_test PRIVATE .)

add_executable(bitmap_test 
    test/dts_datastruct_bitmap_test.c 
    dts_datastruct_bitmap.c
)
target_include_directories(bitmap_test PRIVATE .)
