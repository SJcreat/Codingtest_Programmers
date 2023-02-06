#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
queue<int> container;
stack<int> sub_container;
bool chk[1000001];
int solution(vector<int> order) {
    int answer = 0;
    for(int i=0;i<order.size();i++){
        container.push(i+1);
    }
    
    for(int i=0;i<order.size();i++){
        int tr=container.front();     
        if(order[i]==tr){
            answer++;
            container.pop();
        }
        else if(!sub_container.empty()){
            if(sub_container.top()==order[i]){
                sub_container.pop();
                
                answer++;
            }
            else if(chk[order[i]]){
                break;
            }
            else{
            sub_container.push(tr);
            container.pop();
            chk[tr]=true;
                i--;
            }
        }
        else{
            sub_container.push(tr);
            chk[tr]=true;
            container.pop();
            i--;
        } 
    }
    
    return answer;
}
