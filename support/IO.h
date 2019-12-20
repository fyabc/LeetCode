//
// Created by v-yaf on 12/6/2019.
//

#ifndef LEETCODE_IO_H
#define LEETCODE_IO_H

#include <iostream>
#include <string>
#include <utility>

namespace leetcode {

inline void println() {
    std::cout << std::endl;
}

template <typename Arg1>
inline void println(Arg1&& arg1) {
    std::cout << arg1 << std::endl;
}

template <typename Arg1, typename Arg2, typename... Args>
inline void println(Arg1&& arg1, Arg2&& arg2, Args&&... args) {
    std::cout << arg1 << ' ';
    println(std::forward<Arg2>(arg2), std::forward<Args>(args)...);
}

template <typename ContainerT>
inline void println_container(ContainerT&& container, const std::string& head="", const std::string& sep=", ") {
    std::cout << head << '[';
    for (auto&& item: container) {
        std::cout << item << sep;
    }
    std::cout << ']' << std::endl;
}

template <typename T1, typename T2>
inline std::ostream& operator<< (std::ostream& ostream, const std::pair<T1, T2>& pair) {
    ostream << "pair(" << pair.first << ", " << pair.second << ")";
    return ostream;
}

}

#endif //LEETCODE_IO_H
