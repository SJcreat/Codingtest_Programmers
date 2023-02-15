#include <string>
#include <vector>
#include <queue>
using namespace std;
bool chk[1000001];
int solution(int x, int y, int n) {
    int answer = -1;
    queue<pair<int,int>> qu;
    
    qu.push({x,0});
   
    while(!qu.empty()){
        int N=qu.front().first;
        int cnt=qu.front().second;
        chk[N]=true;
        if(N==y){
            answer=cnt;
            break;
        }
        else if(N+n==y){
                        answer=cnt+1;
            break;        
        }
                else if(N*2==y){
                        answer=cnt+1;
            break;        
        }
                else if(N*3==y){
                        answer=cnt+1;
            break;        
        }
        qu.pop();
        if(N+n<y&& chk[N+n]!=true){        
        qu.push({N+n,cnt+1});
        }
        if(N*2<y&& chk[N*2]!=true){
           qu.push({N*2,cnt+1}); 
        }
        if(N*3<y&& chk[N*3]!=true){
           qu.push({N*3,cnt+1}); 
        } 
        
   }

    
    
    
    
    return answer;
}
