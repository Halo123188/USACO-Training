/*
ID: edward.26
TASK: nocows
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

int n, k;
int mod = 9901;
long long f[330][110];


int main(int argc, const char * argv[]) {
    
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    
    fin>>n>>k;
    
    for(int i = 1;i<=k;i++){
        f[1][i] = 1;
    }
    
    for(int tk = 1;tk<=k;tk++){
        for(int i = 3;i<=n;i+=2){
            for(int j = 1;j<i;j+=2){
                f[i][tk] += (f[j][tk-1] * f[i-1-j][tk-1] + mod)%mod;
            }
        }
    }
    
    fout<<(f[n][k] - f[n][k-1] + 10*mod) % mod<<endl;
    return 0;
}
