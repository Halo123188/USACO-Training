/*
ID: edward.26
TASK: gift1
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

struct person{
    string name;
    int m, give, acc;
}t[15];
map<string, int> lis;
int main(int argc, const char * argv[]) {
    
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    fin>>n;
    for(int i = 1;i<=n;i++){
        string nam;
        fin>>nam;
        lis.insert({nam, i});
    }

    for(int i = 1;i<=n;i++){
        string nam;
        int x,y;
        fin>>nam>>x>>y;
        t[lis[nam]].name = nam;
        t[lis[nam]].m = x;
        t[lis[nam]].give = y;
        int mod = 0, gif = 0;
        if(y != 0){
            mod = x%y;
            t[lis[nam]].acc+= mod;
            gif = (x-mod)/y;
        }
        else{
            t[lis[nam]].acc+= x;
        }
        
        for(int j = 1;j<=y;j++){
            string tn;
            fin>>tn;
            t[lis[tn]].acc += gif;
        }
    }
    
    for(int i = 1;i<=n;i++){
        fout<<t[i].name<<" "<<t[i].acc-t[i].m<<endl;
    }
    return 0;
}
