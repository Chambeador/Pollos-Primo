#include<bits/stdc++.h>
using namespace std;


int lsb(int x) {return x & -x;}
template <typename T>
struct FenwickTree{
    //indexado a 1
       vector<T> bit;
        FenwickTree(int N): bit(N+1, 0) {};
       void add(int i, T val){
             while(i < bit.size()){
                   bit[i] = (bit[i]+val)%MOD;
                   i += lsb(i);
             }
       }
       T sum(int i){
             T ret = 0;
             while(i > 0){
              ret = (ret +  bit[i]) %MOD;
              i -= lsb(i);
             }
             return ret;
       }
       T sum(int l, int r){
         return sum(r)-sum(l-1);
       }
};

signed main(){
     return 0;
}