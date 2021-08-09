#include <bits/stdc++.h>
using namespace std;

//Purpose is to learn basics of dp with fibonacci no computaion
int f(int n){
    if(n<2) return n;
    return f(n-2)+f(n-1);}         /*it is slow program for nth fib no, since we are overcomputng numerous values 

                                    Here dp comes to the rescue which expedites the process.  O(2^n)-> O(n)
                                    Recursively concept of memoization is used here to store the computed values in a
                                    array ,say cache array cache[n]; (the array sort of memorizes the values computed 
                                    and store it to prevent us from overcomputing.) */


int cache[50];

int f(int n){
    if(n<2)  return n;
    if(cache[n]!=-1){
        return cache[n];
    }
     cache[n]=f(n-1)+f(n-2);       //TOP-DOWN dp->concept of memoization used to bring down complexity to O(n)
     return cache[n];

}
void solve(){
    int n=20;
    for(int i=0;i<=20;i++){
        cache[i]=-1;
    }
}

void solve1(){
    int n=20;
    int f[50];
    f[0]=0,f[1]=1;                 //to compute f[i], we guarantee we know values of f[i-1] & f[i-2], also called pull dp
                                    //Iterative dp (is more used)-(bottom-up dp)
    for(int i=0;i<=20;i++){
        f[i]=f[i-1]+f[i-2]; 
    }
}

void solve2(){
    int n=20;
    int dp[50]={0};
    dp[0]=0,dp[1]=1;                 //we say dp[i] contributes to dp[i+1] and dp[i+2]s
                                    //Iterative dp ,push dp is used
    for(int i=0;i<=20;i++){
        for(int j=i+1;j<=i+2;j++){
            
            dp[j]+=dp[i];
        }
    }
  cout<<dp[6];}

int main() {
   solve1();}

/*IN DP ,always think of :   1.STATE        ->   f(i)
                         ,   2.TRANSITION   ->  f(n-1)+ f(n-2)  
                             3.Base conditions and answer       */