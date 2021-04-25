//
// Created by fyabc on 2021/2/16.
//

#ifndef LEETCODE_STRING_H
#define LEETCODE_STRING_H

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <locale>

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

std::vector<std::string> split(const std::string& str, const std::string& delim) {
    if (delim.empty()) {
        throw std::invalid_argument("empty separator");
    }

    if (str.empty()) {
        return {""};
    }

    std::vector<std::string> result;

    auto currentPos = str.begin(), newPos = str.begin();

    while (newPos != str.end()) {
        newPos = std::search(currentPos, str.end(), delim.begin(), delim.end());

        result.emplace_back(currentPos, newPos);

        if (newPos == str.end()) {
            break;
        }

        currentPos = newPos + static_cast<std::string::difference_type>(delim.size());
    }

    return result;
}

std::string join(const std::vector<std::string>& words, const std::string& sep) {
    if (words.empty()) {
        return "";
    }

    std::ostringstream os;

    auto it = words.begin();
    os << *it++;

    for (; it != words.end(); ++it) {
        os << sep;
        os << *it;
    }

    return os.str();
}

}

#endif //LEETCODE_STRING_H
