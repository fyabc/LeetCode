//
// Created by v-yaf on 12/6/2019.
//

#ifndef LEETCODE_IO_H
#define LEETCODE_IO_H

#include "support/Common.h"

#include <forward_list>
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

namespace leetcode {

/**
 * Define some output operators for common types.
 *
 * @tparam T1
 * @tparam T2
 * @param ostream
 * @param pair
 * @return
 */
template <typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& ostream, const std::pair<T1, T2>& pair) {
    ostream << "pair(" << pair.first << ", " << pair.second << ")";
    return ostream;
}

/**
 * Variadic println.
 *
 * @tparam Args
 * @param args
 */
template <typename... Args>
inline void printlnV(Args&& ... args);

inline void printlnV() {
    std::cout << std::endl;
}

template <typename Arg1>
inline void printlnV(Arg1&& arg1) {
    std::cout << arg1 << std::endl;
}

template <typename Arg1, typename Arg2, typename... Args>
inline void printlnV(Arg1&& arg1, Arg2&& arg2, Args&& ... args) {
    std::cout << arg1 << ' ';
    printlnV(std::forward<Arg2>(arg2), std::forward<Args>(args)...);
}

namespace detail {

template <typename ContainerT>
void _printContainer(const ContainerT& container, std::ostream& os,
                     const std::string& sep, const std::string& lp, const std::string& rp,
                     bool printTypename) {
    if (printTypename)
        os << getTypename<ContainerT>();
    os << lp;
    std::size_t count = 0;
    for (auto it = std::begin(container); it != std::end(container); ++it, ++count) {
        if (count > 0) {
            os << sep;
        }
        print(*it, os);
    }
    os << rp;
}

template <typename SetT>
inline void _printSet(const SetT& container, std::ostream& os,
                      const std::string& sep, const std::string& lp, const std::string& rp) {
    if (container.empty()) {
        os << "set()";
        return;
    }
    _printContainer(container, os, sep, lp, rp, false);
}

template <typename MappingT>
void _printMap(const MappingT& container, std::ostream& os,
               const std::string& sep, const std::string kvSep,
               const std::string& lp, const std::string& rp) {
    os << lp;
    std::size_t count = 0;
    for (auto it = container.begin(); it != container.end(); ++it, ++count) {
        if (count > 0) {
            os << sep;
        }
        print(it->first, os);
        os << kvSep;
        print(it->second, os);
    }
    os << rp;
}

}

template <typename T>
inline void print(const T& container) {
    print(container, std::cout);
}

template <typename T>
inline std::enable_if_t<!isContainer<T>::value> print(const T& value, std::ostream& os) {
    os << value;
}

template <typename T>
inline std::enable_if_t<isContainer<T>::value> print(const T& container, std::ostream& os) {
    detail::_printContainer(container, os, ", ", "(", ")", true);
}

/**
 * Special case for basic strings, not print it as container.
 *
 * @tparam T
 * @param string
 * @param os
 */
template <typename T>
inline void print(const std::basic_string<T>& string, std::ostream& os) {
    os << string;
}

/**
 * Special case for C-strings, not print it as container.
 *
 * @tparam N
 * @param string
 * @param os
 */
#define _IO_PRINT_C_STRING(CharType)                                \
template <std::size_t N>                                            \
inline void print(const CharType string[N], std::ostream& os) {     \
    os << string;                                                   \
}                                                                   \
                                                                    \
template <std::size_t N>                                            \
inline void print(const CharType (&string)[N], std::ostream& os) {  \
    os << string;                                                   \
}

_IO_PRINT_C_STRING(char)

_IO_PRINT_C_STRING(wchar_t)

_IO_PRINT_C_STRING(char16_t)

_IO_PRINT_C_STRING(char32_t)

/**
 * Special case for std::initializer_list<T>.
 *
 * @tparam T
 * @param container
 * @param os
 */
template <typename T>
inline void print(const std::initializer_list<T>& container, std::ostream& os = std::cout) {
    detail::_printContainer(container, os, ", ", "initlist(", ")", false);
}

/**
 * Special case for nullptr.
 * Before LWG2221, std::ostream cannot output nullptr.
 * @param os
 */
inline void print(std::nullptr_t, std::ostream& os) {
    os << "nullptr";
}

#define _IO_PRINT_SINGLE_CONTAINER(ContainerType, SEP, LP, RP)              \
template <typename T>                                                       \
inline void print(const ContainerType <T>& container, std::ostream& os) {   \
    detail::_printContainer(container, os, (SEP), (LP), (RP), false);       \
}

_IO_PRINT_SINGLE_CONTAINER(std::vector, ", ", "[", "]")

_IO_PRINT_SINGLE_CONTAINER(std::list, " <-> ", "[", "]")

_IO_PRINT_SINGLE_CONTAINER(std::forward_list, " -> ", "[", "]")

#define _IO_PRINT_SET(SetType)                                          \
template <typename T>                                                   \
inline void print(const SetType <T>& container, std::ostream& os) {     \
    detail::_printSet(container, os, ", ", "{", "}");                   \
}

_IO_PRINT_SET(std::unordered_set)

_IO_PRINT_SET(std::unordered_multiset)

_IO_PRINT_SET(std::set)

_IO_PRINT_SET(std::multiset)

#define _IO_PRINT_MAPPING(MappingType)                                      \
template <typename K, typename V>                                           \
inline void print(const MappingType <K, V>& container, std::ostream& os) {  \
    detail::_printMap(container, os, ", ", ": ", "{", "}");                 \
}

_IO_PRINT_MAPPING(std::unordered_map)

_IO_PRINT_MAPPING(std::unordered_multimap)

_IO_PRINT_MAPPING(std::map)

_IO_PRINT_MAPPING(std::multimap)


/**
 * Return a formatted version of string fmt.
 *
 * @tparam Args
 * @param fmt
 * @param args
 * @return
 */
template <typename... Args>
std::string format(const std::string& fmt, Args&& ... args) {
    // TODO
    return fmt;
}

/**
 * Print a formatted version of string fmt to output stream os.
 *
 * @tparam Args
 * @param os
 * @param fmt
 * @param args
 */
template <typename... Args>
inline void formatP(std::ostream& os, const std::string& fmt, Args&& ... args) {
    os << format(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void formatP(const std::string& fmt, Args&& ... args) {
    formatP(std::cout, fmt, std::forward<Args>(args)...);
}

}

#endif //LEETCODE_IO_H
