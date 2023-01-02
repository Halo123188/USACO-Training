/*
ID: edward.26
TASK: runround
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
#include <cstdio>
#include <numeric>
#include <cmath>
using namespace std;
int a[1000], d, vis[1000];
unsigned long m, num;

bool check1(int a[1000]){
    for(int i = 1;i<d;i++){
        if(a[i] == 0) return true;
        for(int j = i+1;j<=d;j++){
            if(a[i] == a[j]){
                return true;
            }
        }
    }
    return false;
}

bool check2(){
    int pos = d;
    while(vis[pos] == 0){
        vis[pos] = 1;
        pos -= a[pos] % d;
        pos = (pos + d) % d;
        if(pos == 0) pos = d;
        //cout<<"TEST: "<<pos<<endl;
    }
    
    if(pos != d){
        return false;
    }
    
    for(int i = 1;i<=d;i++){
       // cout<<vis[i]<<endl;
        if(vis[i] == 0) return false;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    
    fin>>m;
    num = m;
    while(num >= 10){
        d++;
        a[d] = num % 10;
        //vis[d] = 0;
        num /= 10;
    }
    
    if(num > 0){
        d ++;
        a[d] = num;
    }
    
    for(unsigned long i = m+1;;i++){
        a[1] ++;
        int dd = 1;
        while(a[dd] >= 10){
            a[dd] = 0;
            a[++dd] ++;
        }
        d = max(d, dd);
        
        //cout<<d<<endl;
        if(check1(a)){
            //cout<<"Fail ";
            continue;
        }
        
        for(int i = 1;i<=d;i++){
            vis[i] = 0;
        }
        
        if(check2()){
            fout<<i<<endl;
            break;
        }
    }
    
    return 0;
}
