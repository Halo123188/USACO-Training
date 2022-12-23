/*
ID: edward.26
TASK: wormhole
LANG: C++
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int n;
int x[20], y[20];
int part[20], rig[20];

bool check(){
    
    for(int i = 1;i<=n;i++){
        int pos = i;
        for(int j = 1;j<=n+1;j++){
            pos = part[pos];
            pos = rig[pos];
        }
        
        if(pos != 0) return true;
    }
    
    return false;
}

int cal(){
    int i = 1, ans = 0;
    for(i = 1;i<=n;i++){
        if(part[i] == 0) break;
    }
    
    if(i == n+1){
        if(check()){
            return 1;
        }
        return 0;
    }
    
    for(int j = i+1;j<=n;j++){
        if(part[j] == 0){
            part[j] = i;
            part[i] = j;
            
            ans += cal();
            
            part[i] = part[j] = 0;
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    
    fin>>n;
    for(int i = 1;i<=n;i++){
        fin>>x[i]>>y[i];
    }
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == j) continue;
            
            if(y[i] == y[j] && x[j] > x[i] && rig[i] == 0){
                rig[i] = j;
            }
            else if(y[i] == y[j] && x[j] > x[i] && x[j] < x[rig[i]]){
                rig[i] = j;
            }
        }
    }
    
//    for(int i = 1;i<=n;i++){
//        cout<<rig[i]<<endl;
//    }
    fout<<cal()<<endl;
    
    return 0;
}
