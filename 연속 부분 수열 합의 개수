#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

set<int> S;
int solution(vector<int> elements) {
    int answer = 0;
    for(int i=1;i<=elements.size();i++){        
        for(int j=0;j<elements.size();j++){      
            int s=0;
            for(int k=j;k<j+i;k++){
                if(k<elements.size())
                s+=elements[k];
                else{
                    s+=elements[k-elements.size()];
                }
            }
        
            S.insert(s);
        }  
       
    }
    
    answer=S.size();
    return answer;
}
