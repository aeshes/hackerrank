/*
You have an empty sequence, and you will be given NN queries. Each query is one
of these three types:

1 x  -Push the element x into the stack.
2    -Delete the element present at the top of the stack.
3    -Print the maximum element in the stack.

Input Format

The first line of input contains an integer, NN. 
The next NN lines each contain an above mentioned query. (It is guaranteed
that each query is valid.)
*/

#include <iostream>
#include <algorithm>
#include <stack>


class MaxStack{
private:
    std::stack< std::pair<int, int> > s;
public:
    void push(int new_elem){
        int maximum;
        if(s.empty()){
            s.push(std::make_pair(new_elem, new_elem));
        }else{
            maximum = (new_elem > s.top().second) ? new_elem : s.top().second;
            s.push(std::make_pair(new_elem, maximum));
        }
    }

    void pop(){
        s.pop();
    }

    int top(){
        return s.top().first;
    }

    int max(){
        return s.top().second;
    }
};

enum{PUSH = 1, DELETE = 2, PRINT_MAX = 3};

void query(MaxStack *s, int type){
    int temp;

    if(type == PUSH){
        std::cin >> temp;
        s->push(temp);
    }else if(type == DELETE){
        s->pop();
    }else if(type == PRINT_MAX){
        std::cout << s->max() << std::endl;
    }
}

int main() {
    MaxStack my_stack;
    int n, type;

    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> type;
        query(&my_stack, type);
    }
    return 0;
}