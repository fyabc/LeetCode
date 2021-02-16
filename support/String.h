//
// Created by fyabc on 2021/2/16.
//

#ifndef LEETCODE_STRING_H
#define LEETCODE_STRING_H

#include <string>
#include <istream>
#include <vector>

namespace leetcode {

std::vector<std::string> split(const std::string& str) {
    std::istringstream is(str);
    std::string s;
    std::vector<std::string> result;

    while (is >> s) {
        result.push_back(s);
    }

    return result;
}

std::vector<std::string> split(const std::string& str, char delim) {
    std::istringstream is(str);
    std::string s;
    std::vector<std::string> result;

    while (std::getline(is, s, delim)) {
        result.push_back(s);
    }

    return result;
}

std::string join(const std::vector<std::string>& words, const std::string& sep) {
    // TODO
    return "";
}

}

#endif //LEETCODE_STRING_H
