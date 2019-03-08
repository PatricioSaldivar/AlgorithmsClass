//
//  main.cpp
//  ContComparisios on a Merge Sort
//
//  Created by Pato Saldivar on 2/7/19.
//  Copyright © 2019 Pato Saldivar. All rights reserved.
//
#include <iostream>
#include <vector>

using namespace std;

int contComp=0;

//&function

void Une(vector<int> &d, int ini, int m, int fin){
    int i=ini;
    int j= m+1;
    vector<int> arr;
    
    while(i<=m && j<=fin){
        if(d[i] < d[j]){
            arr.push_back(d[i]);
            i++;
        }else{
            arr.push_back(d[j]);
            j++;
        }
        contComp++;
    }
    if(i<=m){
        while(i<=m){
            arr.push_back(d[i]);
            i++;
        }
        
    }else{
        while(j<=fin){
            arr.push_back(d[j]);
            j++;
        }
    }
    //Checar Esto
    for (int a=0, k=ini; a<arr.size(); a++) {
        d[k++] = arr[a];
    }
}

void MergeSort(vector<int> &d, int ini, int fin){
    if(ini<fin){
        int m = (ini + fin)/2;
        MergeSort(d, ini, m);
        MergeSort(d, m+1, fin);
        Une(d,ini, m, fin);
    }
}

int main(){
    int n;
    cout<< "Empieza:\n";
    cin >> n;
    vector<int> datos(n);
    for (int i=0; i<n; i++){
        cin>>datos[i];
    }
    MergeSort(datos, 0, n-1);
    cout << contComp<<endl;
        for (int i=0; i<n; i++){
     cout<<datos[i]<< " ";
   
}
}
