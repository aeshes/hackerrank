/*
The median of a finite list of numbers can be found by arranging all the integers 
from lowest to highest value and picking the middle one. 
For example, the median of {3,3,5,9,11} is 55. If there is an even number of integers, 
then there is no single middle value, and the median is then usually defined to be 
the mean of the two middle values. For examples, the median of {3,5,7,9} is (5+7)/2=6

Given that integers are read from a data stream, 
find the median of elements read so far in an efficient way.
*/

#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>


class RunningMedian
{
private:
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    
public:
    void push(int value)
    {
        // adding the number into the proper heap
        if (max_heap.empty())
	       max_heap.push(value);
        else
		{
	       if(value >= max_heap.top())
	           min_heap.push(value);
	       else
	           max_heap.push(value);
        }
        // balancing heaps
        if (max_heap.size() - min_heap.size() == 2)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() - max_heap.size() == 2)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double median()
    {
        if (max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top()) / 2.0;
        else if (max_heap.size() > min_heap.size())
            return max_heap.top();
        else
            return min_heap.top();
    }
};

int main()
{
    RunningMedian solver;
	int n, value;
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> value;
        solver.push(value);
        std::cout << std::fixed << std::setprecision(2)
				  << solver.median() << std::endl;
    }
	return 0;
}