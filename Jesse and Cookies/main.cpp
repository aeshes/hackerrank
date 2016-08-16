#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>

template<class T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

inline int combine(int first, int second)
{
    return first + 2*second;
}

int main() {
    int cookies = 0, required_sweetness = 0;
    int operations = 0;
    
    std::cin >> cookies >> required_sweetness;
    
    std::istream_iterator<int> iter(std::cin), eof;
    min_heap<int> pq(iter, eof);
    
    while (pq.size() >= 2 && pq.top() < required_sweetness)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        int new_cookie = combine(first, second);
        pq.push(new_cookie);
        
        ++operations;
    }
    
    if (!pq.empty() && pq.top() < required_sweetness)
        std::cout << -1 << std::endl;
    else
        std::cout << operations << std::endl;
    
    return 0;
}