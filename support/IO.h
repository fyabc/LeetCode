//
// Created by v-yaf on 12/6/2019.
//

#ifndef LEETCODE_IO_H
#define LEETCODE_IO_H

#include <iostream>

namespace leetcode {

template <typename T>
void print(const T& t,
    std::ostream& ostream=std::cout) {
    ostream << t << std::endl;
}

template <typename It1, typename It2>
void print(It1 begin, It2 end,
    const std::string& sep=" ",
    std::ostream& ostream=std::cout) {
    auto it = begin;
    while (it != end) {
        ostream << *it;
        ++it;
        if (it != end) {
            ostream << sep;
        }
    }
    ostream << std::endl;
}

}

#endif //LEETCODE_IO_H
