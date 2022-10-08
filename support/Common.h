//
// Created by v-yaf on 12/23/2019.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H


#ifdef __GNUC__
#include <cxxabi.h>
#include <memory>
#endif

#include <string>
#include <list>
#include <type_traits>
#include <utility>

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
    auto rawName = typeid(T).name();
    int status = -4;
    using freeType = decltype(std::free);
    std::unique_ptr<char, freeType*> gnuTypename {
        abi::__cxa_demangle(rawName, nullptr, nullptr, &status), std::free};
    return (status == 0) ? gnuTypename.get() : rawName;
#else
    return typeid(T).name();
#endif
}

namespace detail {

template <typename T>
auto isContainerImpl(int) -> decltype(void(std::begin(std::declval<T>())), void(
    std::end(std::declval<T>())), std::true_type{});

template <typename T>
auto isContainerImpl(...) -> std::false_type;

}

/**
 * Check if T is a container (has begin() and end()).
 * Method from https://stackoverflow.com/questions/45332612/sfinae-with-vc-compiler/45334033#45334033.
 * @tparam T
 */
template <typename T>
struct isContainer : decltype(detail::isContainerImpl<T>(0)) {
};

/**
 * Another implementation of isContainer.
 * Method from https://gist.github.com/fenbf/d2cd670704b82e2ce7fd.
 * @tparam T
 */
template <typename T>
class isContainer2 {
private:
    using YesType = char[1];
    using NoType = char[2];

#pragma warning(push)
#pragma warning(disable : 4068)
#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotImplementedFunctions"

    template <typename C>
    static YesType& test(decltype(std::begin(std::declval<C>()), std::end(std::declval<C>()), 0));

    template <typename C>
    static NoType& test(...);

#pragma clang diagnostic pop
#pragma warning(pop)

public:
    enum {
        value = sizeof(test<T>(0)) == sizeof(YesType)
    };
};

}

#endif //LEETCODE_COMMON_H
