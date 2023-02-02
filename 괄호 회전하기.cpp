#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

stack<char> chk;
int solution(string s) {
    int answer = 0;

    for(int i=0;i<s.size();i++){
        bool ans=true;
        string t=s.substr(i)+s.substr(0,i);
        if(s.size()%2==1){
            
            continue;
        }
        for(int j=0;j<t.size();j++){
            if(t[j]=='['||t[j]=='('||t[j]=='{'){
                chk.push(t[j]);
            }
            else{
                if(chk.empty())
                    ans=false;
                else if(t[j]==']'){
                char k=chk.top();
                chk.pop();         
                    if(k!='[')ans=false;
                }
                else if(t[j]==')'){
                char k=chk.top();
                chk.pop();         
                    if(k!='(')ans=false;
                }
                else if(t[j]=='}'){
                char k=chk.top();
                chk.pop();         
                    if(k!='{')ans=false;
                }
                    
            }
            if(!ans)break;
        }
        if(ans)
        answer++;
        while(!chk.empty())chk.pop();
        
        
    }
    
    return answer;
}
