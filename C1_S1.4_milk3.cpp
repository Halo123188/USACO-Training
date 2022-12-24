/*
ID: edward.26
TASK: milk3
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

int a,b,c;
int ans[25];
int vis[25][25][25];

void milk(int x, int y, int z){
    if(vis[x][y][z] == 1){
        return;
    }
    if(x == 0){
        ans[z] = 1;
    }
    vis[x][y][z] = 1;
    if(y + z > b){
        milk(x, b, y + z - b);
    }
    else{
        milk(x, y + z, 0);
    }
    
    if(x + z > a){
        milk(a, y, x + z - a);
    }
    else{
        milk(x + z, y, 0);
    }
    
    if(y + z > c){
        milk(x, z+y-c, c);
    }
    else{
        milk(x, 0, z+y);
    }
    
    if(x+y > a){
        milk(a, x+y-a, z);
    }
    else{
        milk(x+y, 0, z);
    }
    
    if(y + x > b){
        milk(y+x-b, b, z);
    }
    else{
        milk(0, y+x, z);
    }
    
    if(x + z > c){
        milk(z+x-c, y, c);
    }
    else{
        milk(0, y, z+x);
    }
    return;
    
}
int main(int argc, const char * argv[]) {
    
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    
    fin>>a>>b>>c;
    milk(0, 0, c);
    
    int n = 0;
    for(int i = 0;i<=20;i++){
        if(ans[i] && n == 0){
            fout<<i;
            n++;
        }
        else if(ans[i]){
            fout<<" "<<i;
        }
    }
    fout<<endl;
    return 0;
}
