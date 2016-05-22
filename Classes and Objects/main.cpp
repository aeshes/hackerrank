#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Student {
private:
    std::vector<int> grades;
public:
    void input();
    int calculateTotalScore();
};

void Student::input()
{
    int score = 0;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> score;
        this->grades.push_back (score);
    }
}

int Student::calculateTotalScore()
{
    return std::accumulate (grades.begin(), grades.end(), 0);
}


// This code is given by system

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}