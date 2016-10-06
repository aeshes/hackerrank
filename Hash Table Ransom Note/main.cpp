#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom)
{
    std::unordered_map<std::string, int> table;
    
    for (auto word : magazine) { ++table[word]; }
    for (auto word : ransom)
    {
        if (table.at(word) == 0) return false;  // No words in the magazine available
        else --table[word];                     // Take one word from magazine
    }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}