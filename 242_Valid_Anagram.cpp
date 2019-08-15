#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for (auto& i : s)
            m[i]++;
         for (auto& i : t)
            m[i]--;
        
        for (auto i : m)
            if (i.second != 0) return false; // false = 0
        return true; // true = 1
    }
};

int main()
{
	string s = "rat";
	string t = "car";
	//string s = "anagram";
	//string t = "nagaram";
	
	Solution a1;
	
	if(a1.isAnagram(s,t))
		cout << "true";
	else
		cout << "false";
	
	
	return 0;	
} 
