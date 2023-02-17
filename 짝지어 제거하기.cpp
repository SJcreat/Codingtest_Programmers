#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> t;
    if(s.size()%2==1)return 0;
    
    t.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(t.empty())t.push(s[i]);
        else if(t.top()==s[i]){        
                t.pop();        
        }
        else{
            t.push(s[i]);
        }        
    }
    
    if(t.empty()){
        answer=1;
    }
    else{
        answer=0;
    }
    
   


    return answer;
}
