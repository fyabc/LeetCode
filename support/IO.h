//
// Created by v-yaf on 12/6/2019.
//

#ifndef LEETCODE_IO_H
#define LEETCODE_IO_H

#ifdef __GNUC__
#include <cxxabi.h>
#endif

#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

namespace leetcode {

/**
 * Get the string representation of the given typename.
 *
 * @tparam T
 * @return
 */
template <typename T>
inline std::string getTypename() {
#ifdef __GNUC__
    std::unique_ptr<char, decltype(std::free)> gnuTypename {
        abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr), std::free};
    return *gnuTypename;
#else
    return typeid(T).name();
#endif
}

/**
 * Println anything.
 *
 * @tparam Args
 * @param args
 */
template <typename... Args>
inline void println(Args&&... args);

inline void println() {
    std::cout << std::endl;
}

template <typename Arg1>
inline void println(Arg1&& arg1) {
    std::cout << arg1 << std::endl;
}

template <typename Arg1, typename Arg2, typename... Args>
inline void println(Arg1&& arg1, Arg2&& arg2, Args&& ... args) {
    std::cout << arg1 << ' ';
    println(std::forward<Arg2>(arg2), std::forward<Args>(args)...);
}

namespace impl {

template <typename ContainerT>
void _printlnContainerGeneric(const ContainerT& container, const std::string& head,
                              const std::string& sep, const std::string& lp, const std::string& rp,
                              std::ostream& os, bool printTypename) {
    os << head;
    if (printTypename)
        os << getTypename<ContainerT>();
    os << lp;
    std::size_t count = 0;
    for (auto it = container.begin(); it != container.end(); ++it, ++count) {
        if (count > 0) {
            os << sep;
        }
        os << *it;
    }
    os << rp << std::endl;
}

template <typename MappingT>
void _printlnMap(const MappingT& container,
                 const std::string& head, const std::string& sep,
                 std::ostream& os) {
    os << head << "{";
    std::size_t count = 0;
    for (auto it = container.begin(); it != container.end(); ++it, ++count) {
        if (count > 0) {
            os << sep;
        }
        os << it->first << ": " << it->second;
    }
    os << "}" << std::endl;
}

}

/**
 * Println container.
 *
 * @tparam ContainerT
 * @param container
 * @param head
 * @param sep
 * @param lp
 * @param rp
 * @param os
 */
template <typename ContainerT>
void printlnC(const ContainerT& container,
              const std::string& head = "", const std::string& sep = ", ",
              const std::string& lp = "(", const std::string& rp = ")",
              std::ostream& os = std::cout) {
    impl::_printlnContainerGeneric(container, head, sep, lp, rp, os, true);
}

template <typename T>
inline void printlnC(const std::initializer_list<T>& container,
                     const std::string& head = "", const std::string& sep = ", ",
                     std::ostream& os = std::cout) {
    impl::_printlnContainerGeneric(container, head, sep, "(", ")", os, true);
}

#define PRINTLNC_LP_RP(ContainerType, LP, RP)                                       \
template <typename T>                                                               \
inline void printlnC(const ContainerType <T>& container,                            \
                     const std::string& head = "", const std::string& sep = ", ",   \
                     std::ostream& os = std::cout) {                                \
    impl::_printlnContainerGeneric(container, head, sep, LP, RP, os, false);        \
}

PRINTLNC_LP_RP(std::vector, "[", "]")
PRINTLNC_LP_RP(std::unordered_set, "{", "}")
PRINTLNC_LP_RP(std::unordered_multiset, "{", "}")
PRINTLNC_LP_RP(std::set, "{", "}")
PRINTLNC_LP_RP(std::multiset, "{", "}")


#define PRINTLNC_MAP(MapType)                                                       \
template <typename K, typename V>                                                   \
inline void printlnC(const MapType <K, V>& container,                               \
                     const std::string& head = "", const std::string& sep = ", ",   \
                     std::ostream& os = std::cout) {                                \
    impl::_printlnMap(container, head, sep, os);                                    \
}

PRINTLNC_MAP(std::unordered_map)
PRINTLNC_MAP(std::unordered_multimap)
PRINTLNC_MAP(std::map)
PRINTLNC_MAP(std::multimap)


template <typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& ostream, const std::pair<T1, T2>& pair) {
    ostream << "pair(" << pair.first << ", " << pair.second << ")";
    return ostream;
}

}

#endif //LEETCODE_IO_H
