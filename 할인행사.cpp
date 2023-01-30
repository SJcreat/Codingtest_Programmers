#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
map<string,int> fruit;
queue<string> qu;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    for(int i=0;i<want.size();i++){
        fruit[want[i]]=i;
    }
    for(int i=0;i<discount.size();i++){
        qu.push(discount[i]);
        if(fruit.find(discount[i])!=fruit.end())
        number[fruit[discount[i]]]--;
        
        if(qu.size()>10){
            string tr=qu.front();
            qu.pop();
              if(fruit.find(tr)!=fruit.end())
        number[fruit[tr]]++;
        }
        bool chk=false;
        for(int j=0;j<number.size();j++){
            if(number[j]>0)
                chk=true;
        }
        if(!chk)answer++;
        
    }
    
    
    return answer;
}
