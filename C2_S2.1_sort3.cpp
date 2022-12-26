/*
ID: edward.26
TASK: sort3
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
using namespace std;
int a[2000];
int a1, a2, a3, a4;

int main(int argc, const char * argv[]) {
    
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    
    int n;
    fin>>n;
    int n1 = 0, n2 = 0, n3 = 0;
    for(int i = 1;i<=n;i++){
        fin>>a[i];
        if(a[i] == 1){
            n1++;
        }
        if(a[i] == 2){
            n2++;
        }
        if(a[i] == 3){
            n3++;
        }
    }
    
    int ans = 1;
    for(int i = 1;i<=n1;i++){
        a[i]-=1;
    }
    
    for(int i = n1+1;i<=n1+n2;i++){
        a[i]-=2;
    }
    
    for(int i = n1+n2+1; i<=n;i++){
        a[i]-=3;
    }
    
    for(int i = 1;i<=n;i++){
        if(a[i] == -1) a1++;
        if(a[i] == 1) a2++;
        if(a[i] == 2) a3++;
        if(a[i] == -2) a4++;
    }
    
    fout<<max(a1, a2) + min(a3, a4)<<endl;
    return 0;
}
