//
//  main.cpp
//  ContQuickSort
//
//  Created by Pato Saldivar on 2/11/19.
//  Copyright © 2019 Pato Saldivar. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int contComp=0;

//&function

void Particion(vector<int> &d, int ini, int fin, int &pivote){
    int elementoPivote= d[ini];
    int j=ini;
    for (int i=ini+1; i<=fin; i++) {
        contComp++;
        if (d[i]<elementoPivote) {
            j++;
            swap(d[i],d[j]);
        }
    }
    pivote=j;
    swap(d[ini],d[pivote]);
}

void QuickSort(vector<int> &d, int ini, int fin){
    if (ini<fin) {
        int pivote= ini;
        Particion(d, ini, fin, pivote);
        QuickSort(d, ini, pivote-1);
        QuickSort(d, pivote +1, fin);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> datos(n);
    cout<<"Entra:\n";
    for (int i=0; i<n; i++){
        cin>>datos[i];
    }
    QuickSort(datos, 0, n-1);
    cout << contComp<<endl;
    /*
     for (int i=0; i<n; i++){
     cout<<datos[i]<< " ";
     }
     cout << endl;
     */
}
