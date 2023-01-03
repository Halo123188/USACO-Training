/*
ID: edward.26
TASK: lamps
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

int n, c;
int a[120], b[120], cnt;
string ans [130];

int main(int argc, const char * argv[]) {
    
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    
    fin>>n>>c;
    int temp;
    memset(a, -1, sizeof a);
    fin>>temp;
    while(temp != -1){
        a[temp] = 1;
        fin>>temp;
    }
    fin>>temp;
    while(temp != -1){
        a[temp] = 0;
        fin>>temp;
    }
    
    for(int i = 0;i<=1;i++){
        for(int j = 0;j<=1;j++){
            for(int k = 0;k<=1;k++){
                for(int q = 0;q<=1;q++){
                    if(i + j + k + q > c) continue;
                    
                    if((i + j) % 2 == (k + q)%2 && c%2==1) continue;
                    
                    if((i + j) % 2 != (k + q)%2 && c % 2 == 0) continue;
                    
                    for(int p = 1;p<=n;p++){
                        b[p] = 1;
                    }
                    
                    if(i){
                        for(int p = 1;p<=n;p++){
                            b[p] ^= 1;
                        }
                    }
                    
                    if(j){
                        for(int p = 1;p<=n;p+=2){
                            b[p] ^= 1;
                        }
                    }
                    
                    if(k){
                        for(int p = 2;p<=n;p+=2){
                            b[p] ^= 1;
                        }
                    }
                    
                    if(q){
                        for(int p = 1;p<=n;p+=3){
                            b[p] ^= 1;
                        }
                    }
                    
                    int flag = 1;
                    for(int p = 1;p<=n;p++){
                        if(a[p] == -1) continue;
                        if(a[p] != b[p])  flag = 0;
                    }
                    
                    if(flag){
                        string s = "";
                        for(int p = 1;p<=n;p++){
                            s += char(b[p] +'0');
                        }
                        cnt++;
                        ans[cnt] = s;
                    }
                }
            }
        }
    }
    
    sort(ans + 1, ans +1 + cnt);
    if(cnt == 0) fout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i = 1;i<=cnt;i++){
            fout<<ans[i]<<endl;
        }
    }
    
    
    return 0;
}
