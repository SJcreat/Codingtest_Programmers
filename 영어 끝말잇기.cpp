#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> chk;
    int x=0;
    int y=0;
    char start;
    start=words[0][0];
    for(int i=0;i<words.size();i++){       
        if(start!=words[i][0]||find(chk.begin(),chk.end(),words[i])!=chk.end()){
            x=i%n+1;
            y=i/n+1;
            break;
        }
         chk.push_back(words[i]);
        start=words[i][words[i].size()-1];
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}
