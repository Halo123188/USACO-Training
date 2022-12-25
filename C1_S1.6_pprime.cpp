/*
ID: edward.26
TASK: pprime
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
using namespace std;

bool Prime(int x){
    if(x < 2){
        return false;
    }
    
    for(int i = 2;i*i<=x;i++){
        if(x % i == 0){
            return false;
        }
    }
    
    return true;
}

int z[100000], num;

int main(int argc, const char * argv[]) {
    
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    
    int l, r;
    fin>>l>>r;
    
    for(int i = 1;i<=10000;i++){
        {
            char st[20] = {};
            sprintf(st, "%d", i);
            int len = strlen(st);
            for(int i = 0;i<len;i++){
                st[2*len-2-i] = st[i];
            }
            int x;
            sscanf(st, "%d", &x);
            if(Prime(x)){
                z[num++] = x;
            }
        }
        {
            char st[20] = {};
            sprintf(st, "%d", i);
            int len = strlen(st);
            for(int i = 0;i<len;i++){
                st[2*len-1-i] = st[i];
            }
            int x;
            sscanf(st, "%d", &x);
            if(Prime(x)){
                z[num++] = x;
            }
        }
        
    }
    
    sort(z, z+num);
    for(int i = 0;i<num;i++){
        if(z[i] >= l && z[i] <= r){
            fout<<z[i]<<endl;
        }
    }
    
    return 0;
}
