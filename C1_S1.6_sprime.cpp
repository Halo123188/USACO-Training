/*
ID: edward.26
TASK: sprime
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

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int n;
vector<int> a;
int main(int argc, const char * argv[]) {
    
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    fin>>n;
    a.push_back(2);
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    
    for(int i = 2;i<=n;i++){
        vector<int> temp;
        for(int x:a){
            for(int j = 1;j<=9;j++){
                if(isPrime(x*10 + j)){
                    temp.push_back(x*10+j);
                }
            }
        }
        a.swap(temp);
    }
    for(int xx:a){
        fout<<xx<<endl;
    }
    
    return 0;
}
