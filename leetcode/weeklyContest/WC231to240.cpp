//
// Created by fyabc on 2021/4/18.
//

#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include "support/IO.h"

using namespace std;

class WC237Q1_Problem1832 {
public:
    static bool checkIfPangram(const string& sentence) {
        vector<bool> occurrence (26, false);

        for (auto ch : sentence) {
            occurrence[ch - 'a'] = true;
        }

        return all_of(occurrence.begin(), occurrence.end(), [](bool b) {return b;});
    }
};

class WC237Q2_Problem1833 {
public:
    static int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int sum = 0;
        int count = 0;

        while (sum <= coins && count < costs.size()) {
            sum += costs[count];
            ++count;
        }

        if (sum > coins) {
            --count;
        }
        return count;
    }
};

class WC237Q3_Problem1834 {
    struct Task {
        int time;
        int index;
    };

public:
    static vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); ++i) {
            tasks[i].push_back(i);
        }

        auto cmpEnqueue = [] (const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        sort(tasks.begin(), tasks.end(), cmpEnqueue);

        auto cmpTimeIdx = [] (const Task& a, const Task& b) {
            return a.time > b.time || (a.time == b.time && a.index > b.index);
        };

        priority_queue<Task, vector<Task>, decltype(cmpTimeIdx)> queue(cmpTimeIdx);

        int64_t currentTime = 0;
        int tasksStart = 0;
        vector<int> order;

        while (true) {
            if (queue.empty() && tasksStart < tasks.size()) {    // Jump to next enqueue time.
                auto nextEnqueueTime = tasks[tasksStart][0];
                if (currentTime < nextEnqueueTime) {
                    currentTime = nextEnqueueTime;
                }
            }
            while (tasksStart < tasks.size() && tasks[tasksStart][0] <= currentTime) {
                const auto& task = tasks[tasksStart];
                queue.push({task[1], task[2]});
                ++tasksStart;
            }

            if (queue.empty()) {
                break;
            }

            auto task = std::move(queue.top());
            queue.pop();

            order.push_back(task.index);
            currentTime += task.time;
        }

        return order;
    }
};

class WC237Q4_Problem1835 {
    /**
     * (a & b) ^ (a & c) == a & (b ^ c)
     * (a_i & b_1) ^ (a_i & b_2) ^ ... & (a_i & b_N) == a_i & (b_1 ^ b_2 ^ ... ^ b_N)
     * the XOR sum == (a_1 ^ a_2 ^ ... ^ a_N) & (b_1 ^ b_2 ^ ... ^ b_N)
     */
public:
    static int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        return accumulate(arr1.begin(), arr1.end(), 0, bit_xor<int>()) &
            accumulate(arr2.begin(), arr2.end(), 0, bit_xor<int>());
    }
};