cmake_minimum_required(VERSION 3.15)

project(A)

include_directories(include)

add_executable(main 
    test/main.cpp 
    dts_datastruct_list.c 
    dts_datastruct_bt.c 
    dts_datastruct_bst.c 
    dts_datastruct_rbt.c
)

add_executable(list_test 
    test/dts_datastruct_list_test.c 
    dts_datastruct_list.c
)

add_executable(list_foreach_test 
    test/dts_datastruct_list_foreach_test.c 
    dts_datastruct_list.c
)

add_executable(qsort_test 
    test/dts_algorithm_qsort_test.c 
    dts_algorithm_qsort.c
)

add_executable(kdt_test 
    test/dts_datastruct_kdt_test.c 
    dts_algorithm_qsort.c 
    dts_datastruct_kdt.c 
    dts_datastruct_list.c 
    dts_datastruct_bt.c
)

add_executable(bst_test 
    test/dts_datastruct_bst_test.c 
    dts_datastruct_bst.c 
    dts_datastruct_bt.c 
    dts_datastruct_list.c
)

add_executable(rbt_test 
    test/dts_datastruct_rbt_test.c 
    dts_datastruct_rbt.c 
    dts_datastruct_bst.c 
    dts_datastruct_bt.c 
    dts_datastruct_list.c
)

add_executable(bitmap_test 
    test/dts_datastruct_bitmap_test.c 
    dts_datastruct_bitmap.c
)
