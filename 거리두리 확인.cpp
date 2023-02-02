#include <string>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;
int xy[5][5]={0};
map<char,int> maps;
enum{table,person,wall};
queue<tuple<int,int,int,int,int>> qu;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    maps.insert({'0',0});
    maps.insert({'P',1});
    maps.insert({'X',2});
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){ 
                     xy[j][k]=maps[places[i][j][k]];
                    if(xy[j][k]==person)qu.push({j,k,0,j,k});
                }              
        }
        bool chk_break=false;
        while(!qu.empty()){
            int x=get<0>(qu.front());
            int y=get<1>(qu.front());
            int cnt=get<2>(qu.front());
            int ori_x=get<3>(qu.front());
            int ori_y=get<4>(qu.front());
            qu.pop();
            if(cnt>1)
                break;            
                for(int z=0;z<4;z++){
                     if(x+dx[z]==ori_x&&y+dy[z]==ori_y)continue;
                    if(x+dx[z]>=0&&x+dx[z]<5&&y+dy[z]>=0&&y+dy[z]<5){
                       
                    if(xy[x+dx[z]][y+dy[z]]==person){
                        chk_break=true;                        
                    }
                    else if(xy[x+dx[z]][y+dy[z]]==table){
                        qu.push({x+dx[z],y+dy[z],cnt+1,ori_x,ori_y});
                    }
                        }
                } 
            if(chk_break)break;
            
        }
        if(chk_break){
            answer.push_back(0);
        }
        else{
            answer.push_back(1);
        }
        while(!qu.empty())qu.pop();
     
    }
    return answer;
}
