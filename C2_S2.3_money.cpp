/*
ID: edward.26
TASK: money
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
#include <bitset>
using namespace std;

int n, m;
long long f[10030];
int a[30];


int main(int argc, const char * argv[]) {
    
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    
    fin>>n>>m;
    
    for(int i = 1;i<=n;i++){
        fin>>a[i];
        //f[a[i]] = 1;
    }
    f[0] = 1;

    for(int j = 1;j<=n;j++){
        for(int i = 1;i<=m;i++){
            if(i - a[j] >= 0){
                f[i] += f[i-a[j]];
            }
        }
    }
    
    fout<<f[m]<<endl;
   
    return 0;
}
