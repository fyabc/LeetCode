//
// Debugging utilities.
//
// Created by fyabc on 2021/4/30.
//

#ifndef LEETCODE_DEBUGGING_H
#define LEETCODE_DEBUGGING_H

#include "support/IO.h"

namespace leetcode {

/// Macros to print variable name and values.

#define LEETCODE_DBG_VARS_1(a1) ::leetcode::printlnV(#a1"=", (a1))
#define LEETCODE_DBG_VARS_2(a1, a2) ::leetcode::printlnV(#a1"=", (a1), #a2"=", (a2))
#define LEETCODE_DBG_VARS_3(a1, a2, a3) ::leetcode::printlnV(#a1"=", (a1), #a2"=", (a2), #a3"=", (a3))
#define LEETCODE_DBG_VARS_4(a1, a2, a3, a4) ::leetcode::printlnV(#a1"=", (a1), #a2"=", (a2), #a3"=", (a3), #a4"=", (a4))
#define LEETCODE_DBG_VARS_5(a1, a2, a3, a4, a5) ::leetcode::printlnV(#a1"=", (a1), #a2"=", (a2), #a3"=", (a3), #a4"=", (a4), #a5"=", (a5))
#define LEETCODE_DBG_VARS_6(a1, a2, a3, a4, a5, a6) ::leetcode::printlnV(#a1"=", (a1), #a2"=", (a2), #a3"=", (a3), #a4"=", (a4), #a5"=", (a5), #a6"=", (a6))
#define LEETCODE_DBG_VARS_7(a1, a2, a3, a4, a5, a6, a7) ::leetcode::printlnV(#a1"=", (a1), #a2"=", (a2), #a3"=", (a3), #a4"=", (a4), #a5"=", (a5), #a6"=", (a6), #a7"=", (a7))
#define LEETCODE_DBG_VARS_8(a1, a2, a3, a4, a5, a6, a7, a8) ::leetcode::printlnV(#a1"=", (a1), #a2"=", (a2), #a3"=", (a3), #a4"=", (a4), #a5"=", (a5), #a6"=", (a6), #a7"=", (a7), #a8"=", (a8))
#define LEETCODE_DBG_VARS_9(a1, a2, a3, a4, a5, a6, a7, a8, a9) ::leetcode::printlnV(#a1"=", (a1), #a2"=", (a2), #a3"=", (a3), #a4"=", (a4), #a5"=", (a5), #a6"=", (a6), #a7"=", (a7), #a8"=", (a8), #a9"=", (a9))
#define LEETCODE_DBG_VARS_10(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) ::leetcode::printlnV(#a1"=", (a1), #a2"=", (a2), #a3"=", (a3), #a4"=", (a4), #a5"=", (a5), #a6"=", (a6), #a7"=", (a7), #a8"=", (a8), #a9"=", (a9), #a10"=", (a10))

#define LEETCODE_DBG_DETAIL_ARG15(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, ...) a15
#define LEETCODE_DBG_DETAIL_COUNT_ARGS(...) LEETCODE_DBG_DETAIL_ARG15(dummy, ##__VA_ARGS__, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define LEETCODE_DBG_DETAIL_CONCAT(a, b) a ## b
#define LEETCODE_DBG_DETAIL_CONCAT2(a, b) LEETCODE_DBG_DETAIL_CONCAT(a, b)

// TODO: Cannot print correctly on MSVC, need more fix.
#define LEETCODE_DBG_PRINT_VARS(...) LEETCODE_DBG_DETAIL_CONCAT2(LEETCODE_PRINT_VARS_, LEETCODE_DBG_DETAIL_COUNT_ARGS(__VA_ARGS__)) (##__VA_ARGS__)

template <typename T>
void printlnType(const T& t) {
    leetcode::println(typeid(t).name());
}

}

#endif //LEETCODE_DEBUGGING_H
