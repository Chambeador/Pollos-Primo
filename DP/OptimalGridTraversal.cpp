#include<bits/stdc++.h>

using namespace std;
int const MAX_N = 100;
int const MAX_M = 100;
int G[MAX_N][MAX_M];
int n,m;
int memo[MAX_N][MAX_M];

int f(int i, int j){
    int &a = memo[i][j];
    if(a != -1) return a;
    if(i == n-1 && j == m-1) a = G[i][j];
    else{
       a = 0;
       if(i < n-1) a = max(a, G[i][j]+f(i+1,j));
       if(j < m-1) a = max(a, G[i][j]+f(i,j+1));      
    } 
    return a;
}

//llamar despues de llamar a la funcion f
string ans = "";
void caminoOptimo(int i, int j){
     if(i == n-1 && j == m-1) return;
     if(i < n-1 && memo[i][j] == G[i][j]+memo[i+1][j]){
        ans+='A'; //hacia abajo
        caminoOptimo(i+1,j);
     }else{
        ans += 'D'; //hacia derecha
        caminoOptimo(i,j+1);
     }
}
//igualmente despues de llamar a la funcion f
int cont[MAX_N][MAX_M];
int cant(){
    for(int i = n-1; i >= 0; --i){
        for(int j = m-1; j>= 0; --j){
            if(i == n-1 && j == m-1) cont[i][j] =1;
            else{
               cont[i][j] = 0;
               if(i < n-1 && memo[i][j] == G[i][j]+memo[i+1][j])
                 cont[i][j] += cont[i+1][j];
                if(j < m-1 && memo[i][j] == G[i][j]+memo[i][j+1])
                cont[i][j] += cont[i][j+1];
            }
        }
    }
    return cont[0][0];
}

string sol = "";
//usa el contar solucion y la funcion f
void getk(int i, int j, int k) {
    if (i == n-1 && j == m-1) return;
    if (i < n-1 && memo[i][j] == G[i][j] + memo[i+1][j]){
        if(cont[i+1][j] >= k){
            sol += 'A'; 
            getk(i+1, j, k); 
            return; 
        }
        k -= cont[i+1][j]; 
    }
    if (j < m-1 && memo[i][j] == G[i][j] + memo[i][j+1]) {
        sol += 'D';  
        getk(i, j+1, k);
    }
}
signed main(){
       memset(memo, -1, sizeof(memo));
       cin>>n>>m;
       for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
               cin>>G[i][j];
           }
       }
       cout<<f(0,0)<<endl;
       caminoOptimo(0,0);
       cout<<ans<<endl;
       cout<<cant()<<endl;
       getk(0,0,3);
       cout<<sol<<endl;
}