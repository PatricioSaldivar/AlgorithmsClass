//
//  main.cpp
//  How Many Trees, Catalan Number
//
//  Created by Pato Saldivar on 3/21/19.
//  Copyright © 2019 Pato Saldivar. All rights reserved.

/*
 Given n (nodes), we want to know how many binary trees we can make with these amount of nodes.
 Input:
 Comes in a line n ( 1 <= n <= 30), nodes
 
 Output:
 A line with the amount of binary trees
 
 
 Sample Input:
 3
 
 Sample Output:
 5 BTrees
 
*/
 
 
 

#include <iostream>
#include <vector>
using namespace std;

long long binomialCoeficient(int n){
    //Combinations of size column(k) in row(n) elements
    //In this case k == n and n == 2n
    vector<vector<long long>> B(2*n+1,(vector<long long>(n+1,0)));
    for (int i=0; i<=2*n; i++) {
        for (int j=0; j<=min(n,i); j++) {
            if (j==0 || j==i) {
                B[i][j]=1;
            }else
                B[i][j]= B[i-1][j-1] + B[i-1][j];
        }
    }
    return B[2*n][n];
}


int main() {
    int n;
    cin >> n;
    long long ans = binomialCoeficient(n);
    ans/=(n+1);
    cout<< ans<<" BTrees\n";
    
}
