//
//  main.cpp
//  Audiophobia
//
//  Created by Pato Saldivar on 3/4/19.
//  Copyright © 2019 Pato Saldivar. All rights reserved.
//


#include <iostream>
#include <climits>
using namespace std;

void Floyd(int D[20][20], int n){
    for (int k = 0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX) {
                    D[i][j] = min(D[i][j],max(D[i][k], D[k][j]));
                }
            }
        }
    }
}





int main(){
    int n, m, q, a, b, c, T;
    cout<<"Empeiza \n";
    cin>> T;
    for (int x=0; x<T; x++) {
        
    cin >> n >> m >> q;
    int D[20][20];
    for(int i=0; i<n; i++){
        D[i][i] = 0;
        for (int j=i+1; j<n; j++) {
            D[i][j] = D[j][i] = INT_MAX;
        }
    }
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        D[a-1][b-1] = D[b-1][a-1] = c;
    }
    Floyd(D,n);
        cout<<"Case "<<x+1<<":\n";
    for (int i=0; i<q; i++) {
        cin >> a >> b;
        if(D[a-1][b-1] == INT_MAX){
            cout<< "no path\n";
        }else
        cout << D[a-1][b-1] << endl;
    }
    }
}

