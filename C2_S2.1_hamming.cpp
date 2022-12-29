/*
ID: edward.26
TASK: hamming
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
int n,b,d, num = 1, len;
int ans[70];

int main(int argc, const char * argv[]) {
    
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    
    fin>>n>>b>>d;
    len++;
    ans[len] = 0;
    while(len <= n){
        bool flag = false;
        for(int j = 1;j<=len;j++){
            if(__builtin_popcount(ans[j] ^ num) < d){
                flag = true;
                break;
            }
        }
        if(flag == false){
            len++;
            ans[len] = num;
        }
        num++;
    }
    
    for(int i = 1;i<len;i++){
        fout<<ans[i];
        if(i % 10 == 0 || i == len-1){
            fout<<endl;
        }
        else{
            fout<<" ";
        }
    }
    
    
    return 0;
}
