/*
* Author: aeshes
*/

#include <iostream>
#include <vector>
#include <deque> 

using namespace std;

/*
* @brief Determine maximum value in each contiguous subarray of given size
* @param[in] arr - Vector of integers
* @param[in] array_size - Size of this vector
* @param[in] width - The width of sliding window
* @return Vector of maximum values in each sliding window
*/
vector<int> max_sliding_window(vector<int>& arr, int array_size, int width){
    deque< pair<int, int> > deq;
    vector<int> result;
    
    // Initial filling of the deque
    for (int i = 0; i < width; i++)
    {
        while (!deq.empty() && arr[i] >= deq.back().first)
            deq.pop_back();
        deq.push_back (make_pair(arr[i], i));
    }
    
    // Process the remaining elements
    for (int i = width; i < array_size; i++)
    {
        result.push_back (deq.front().first);
        
        // Remove elements which are out of current window
        while (!deq.empty() && deq.front().second <= i - width)
            deq.pop_front();
        
        // Now iter points to the next element in array
        while (!deq.empty() && arr[i] >= deq.back().first)
            deq.pop_back();                     // Delete all elements smaller than new
        deq.push_back (make_pair(arr[i], i));   // Push new element from array
    }

    result.push_back (deq.front().first);
    return result;
}

// Nothing interesting
int main(){
  
    int ntests;
    cin >> ntests;
    
    for (int i = 0; i < ntests; i++)
    {
        int array_size, win_width;
        cin >> array_size >> win_width;

        vector<int> input(array_size);
        for(int i = 0; i< array_size; i++)
            cin >> input[i];
        vector<int> result = max_sliding_window(input, array_size, win_width);
       
        for (int j = 0; j < result.size(); j++)
            cout << result[j] << " ";
        cout << endl;
    }
    return 0;
}
