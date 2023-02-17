#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> save;
    save.push_back(0);
    int y=k;
    int x=0;
    double w=0;
    while(y!=1){
        if(y%2==0){
        w+=0.75*y; 
         y=0.5*y;  
        }
        else{
            w+=2*y+0.5;
            y=y*3+1;
        }
         save.push_back(w);
        x++;
    } 
    for(int i=0;i<ranges.size();i++){
        if(x+ranges[i][1]<ranges[i][0]){
            answer.push_back(-1);
        }
        else
        answer.push_back(save[x+ranges[i][1]]-save[ranges[i][0]]);
    }
    
    
    return answer;
}
