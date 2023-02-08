#include <string>
#include <vector>
#include <iostream>
using namespace std;

int t[3610]={0};
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for(int i=0;i<book_time.size();i++){
        int h1=stoi(book_time[i][0].substr(0,2));
        int m1=stoi(book_time[i][0].substr(3));
        
        int h2=stoi(book_time[i][1].substr(0,2));
        int m2=stoi(book_time[i][1].substr(3));
        
        for(int j=h1*60+m1;j<=h2*60+m2;j++){
            t[j]++;
        }
          for(int j=h2*60+m2+1;j<=h2*60+m2+9;j++){
            t[j]++;

        }        
    }

    for(int i=0;i<3600;i++){
        answer=max(t[i],answer);
    }
    
    return answer;
}
