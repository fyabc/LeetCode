//
// Created by fyabc on 2021/4/18.
//

#include "support/IO.h"

#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <chrono>

using namespace std;

class WC231Q1_Problem1784 {
public:
    static bool checkOnesSegment(const string& s) {
        int startPos = -1, endPos = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (startPos == -1 && s[i] == '1') {
                startPos = i;
                continue;
            }
            if (endPos == -1 && s[i] != '1') {
                endPos = i;
                continue;
            }
            if (startPos != -1 && endPos != -1 && s[i] == '1') {
                return false;
            }
        }
        return true;
    }
};

class WC231Q2_Problem1785 {
public:
    static int minElements(vector<int>& nums, int limit, int goal) {
        int64_t distance = abs(accumulate(nums.begin(), nums.end(), 0LL) - goal);
        return static_cast<int>(distance / limit + (distance % limit == 0 ? 0 : 1));
    }
};

class WC231Q3_Problem1786 {
    /**
     * Dijkstra to get shortest paths to node n-1, then accumulate strict paths from n-1.
     */
    static constexpr int MODULO = 1000000007;
public:
    static int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);     // adjNode, weight
        for (const auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1, weight = edge[2];
            adj[u].emplace_back(v, weight);
            adj[v].emplace_back(u, weight);
        }

        constexpr int MAX = numeric_limits<int>::max();

        int start = n - 1;
        vector<int> distances(n, MAX);

        dijkstra(start, distances, n, adj);

        return countPaths(adj, distances, n);
    }

private:
    static void relax(vector<int>& distances, int u, int v, int weight) {
        if (distances[v] > distances[u] + weight) {
            distances[v] = distances[u] + weight;
        }
    }

    static void dijkstra(int start, vector<int>& distances, int n, const vector<vector<pair<int, int>>>& adj) {
        distances[start] = 0;

        std::vector<bool> visited(n, false);

        auto cmp = [](const std::pair<int, int>& u, const std::pair<int, int>& v) {
            return u.first > v.first; };
        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            decltype(cmp)
        > priorityQueue(cmp);     // {distance, index}
        priorityQueue.emplace(0, start);

        while (!priorityQueue.empty()) {
            auto di = priorityQueue.top();
            auto u = di.second;
            priorityQueue.pop();

            if (visited[u]) {
                continue;
            }

            visited[u] = true;

            for (const auto& vw: adj[u]) {
                auto v = vw.first;
                auto w = vw.second;
                if (!visited[v]) {
                    relax(distances, u, v, w);
                    priorityQueue.emplace(distances[v], v);
                }
            }
        }
    }

    static int countPaths(const vector<vector<pair<int, int>>>& adj, const vector<int>& distances, int n) {
        int start = n - 1;
        vector<bool> visited(n, false);

        vector<int> pathCounts(n, 0);
        pathCounts[start] = 1;

        queue<int> q;
        q.push(start);

        vector<int> nodeOrder(n);
        iota(nodeOrder.begin(), nodeOrder.end(), 0);
        sort(nodeOrder.begin(), nodeOrder.end(),
             [&distances](int u, int v) { return distances[u] < distances[v] || (distances[u] == distances[v] && u > v); });
        for (int u: nodeOrder) {
            for (const auto& vw: adj[u]) {
                auto v = vw.first;
                if (distances[v] > distances[u]) {
                    pathCounts[v] = (pathCounts[v] + pathCounts[u]) % MODULO;
                }
            }
        }

        return pathCounts[0];
    }
};

class WC231Q4_Problem1787 {
    /**
     * If a ^ (b1 ^ b2 ^ ... ^ bn) == (b1 ^ b2 ^ ... ^ bn) ^ c, then a == c;
     * If a ^ (b1 ^ b2 ^ ... ^ bn) == 0, then a == b1 ^ b2 ^ ... ^ bn.
     * So all k-segments equal to zero => k-cyclic array.
     *
     * Solution 1: DFS + Pruning
     *
     * Solution 2: DP (TODO)
     */

    static constexpr int MAX_VALUE = 1024;
public:
    static int minChanges(vector<int>& nums, int k) {
        auto n = static_cast<int>(nums.size());

        // Value frequency counter.
        vector<vector<int>> freq(k, vector<int>(MAX_VALUE, 0));
        // Unique values at position k.
        vector<unordered_set<int>> uniqueValues(k);
        for (int i = 0; i < n; ++i) {
            ++freq[i % k][nums[i]];
            uniqueValues[i % k].insert(nums[i]);
        }

        return implDFS(n, k, freq, uniqueValues);
    }

private:
    static int implDFS(int n, int k, const vector<vector<int>>& freq, const vector<unordered_set<int>>& uniqueValues) {
        // Unique values at position k, in descent order of frequency.
        vector<vector<int>> sortedValues(k);
        for (int i = 0; i < k; ++i) {
            sortedValues[i].assign(uniqueValues[i].begin(), uniqueValues[i].end());
            const auto& freqI = freq[i];
            sort(sortedValues[i].begin(), sortedValues[i].end(),
                 [&freqI](int a, int b) { return freqI[a] > freqI[b]; });
        }

        vector<int> currentChoice;
        currentChoice.reserve(k);

        int maxKeep = 0;

        DFS(k, freq, sortedValues, 0, 0, currentChoice, maxKeep);

        return n - maxKeep;
    }

    static void DFS(int k, const vector<vector<int>>& freq, const vector<vector<int>>& sortedValues, int depth,
                   int currentResult, vector<int>& currentChoice, int& maxKeep, bool existFree = false) {
        if (depth == k - 1) {
            int thisKeep;
            if (!existFree) {
                // If not exist free, the final value should be fixed.
                int finalChoice = accumulate(currentChoice.begin(), currentChoice.end(), 0, bit_xor<>());
                thisKeep = currentResult + freq[depth][finalChoice];
            } else {
                // Else, the final value can choose the highest frequency.
                thisKeep = currentResult + freq[depth][sortedValues[depth][0]];
            }

            // The last value should be XOR sum of all other values
            if (thisKeep > maxKeep) {
                maxKeep = thisKeep;
            }
            return;
        }
        for (int value: sortedValues[depth]) {
            int fr = freq[depth][value];
            int maxPossibleKeep = currentResult + fr;
            for (int i = depth + 1; i < k; ++i) {
                maxPossibleKeep += freq[i][sortedValues[i][0]];
            }
            if (maxPossibleKeep <= maxKeep) {
                // Prune other branches.
                break;
            }
            currentChoice.push_back(value);
            DFS(k, freq, sortedValues, depth + 1, currentResult + fr, currentChoice, maxKeep, existFree);
            currentChoice.pop_back();
        }

        // choice[depth] will match none of current values (only once)
        if (!existFree) {
            currentChoice.push_back(-1);
            DFS(k, freq, sortedValues, depth + 1, currentResult, currentChoice, maxKeep, true);
            currentChoice.pop_back();
        }
    }
};

class WC232Q3_Problem1792 {
public:
    static double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return gain(a) < gain(b);
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> queue(cmp);
        for (const auto& cls: classes) {
            queue.emplace(cls[0], cls[1]);
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto cls = queue.top();
            queue.pop();

            queue.emplace(cls.first + 1, cls.second + 1);
        }

        auto result = 0.0;
        while (!queue.empty()) {
            const auto& cls = queue.top();

            result += static_cast<double>(cls.first) / static_cast<double>(cls.second);

            queue.pop();
        }

        return result / static_cast<double>(classes.size());
    }

private:
    static inline double gain(const pair<int, int>& cls) {
        auto ad = static_cast<double>(cls.first), bd = static_cast<double>(cls.second);

        return (ad + 1) / (bd + 1) - (ad / bd);
    }
};

class WC232Q4_Problem1793 {
public:
    static int maximumScore(vector<int>& nums, int k) {
        // mins[i] = minimum from i to k (or k to i)
        vector<int> mins(nums.size());
        mins[k] = nums[k];


        for (int i = k - 1; i >= 0; --i) {
            mins[i] = min(mins[i + 1], nums[i]);
        }
        for (int j = k + 1; j < nums.size(); ++j) {
            mins[j] = min(mins[j - 1], nums[j]);
        }

        int i = k, j = k, currentMin = nums[k], maxScore = 0;

        while (true) {
            while (i > 0 && mins[i - 1] == currentMin) {
                --i;
            }
            while (j + 1 < nums.size() && mins[j + 1] == currentMin) {
                ++j;
            }

            maxScore = max(maxScore, (j - i + 1) * currentMin);

            if (i == 0 && j + 1 == nums.size()) {
                break;
            }

            // Try to extend left and right
            if (i == 0) {
                ++j;
                currentMin = mins[j];
            } else if (j + 1 == nums.size()) {
                --i;
                currentMin = mins[i];
            } else {
                if (mins[i - 1] > mins[j + 1]) {
                    --i;
                    currentMin = mins[i];
                } else {
                    ++j;
                    currentMin = mins[j];
                }
            }
        }

        return maxScore;
    }
};

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

            auto task = queue.top();
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
        return accumulate(arr1.begin(), arr1.end(), 0, bit_xor<>()) &
            accumulate(arr2.begin(), arr2.end(), 0, bit_xor<>());
    }
};