#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int N;
int xy[1024][1024]={0,};
int num_1=0;
int num_0=0;
void unlimit(int x,int y,int n){    
    if(x>=N)return;
    if(y>=N)return;
    
    if(n==1){
        if(xy[x][y]==1)num_1++;
        else if(xy[x][y]==0)num_0++;
        return;
    }
        bool one=false;
        bool zero=false;
        for(int i=x;i<x+n;i++){
            for(int j=y;j<y+n;j++){
                if(xy[i][j]==1)one=true;
                else{
                    zero=true;
                }
                if(one&&zero)break;
            }
            if(one&&zero)break;
        }
        if(one&&!zero){
            num_1++;
        }
        else if(zero&&!one){
                num_0++;    
        }
    
        if(one&&zero){         
            unlimit(x,y,n/2);
            unlimit(x+n/2,y,n/2);
            unlimit(x,y+n/2,n/2);
            unlimit(x+n/2,y+n/2,n/2);
        }
    
    
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    N=arr[0].size();
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            xy[i][j]=arr[i][j];
        }
    }
    unlimit(0,0,N);
    
    answer.push_back(num_0);
    answer.push_back(num_1);
    
    return answer;
}
