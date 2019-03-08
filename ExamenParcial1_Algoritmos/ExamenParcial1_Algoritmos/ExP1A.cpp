//
/*
 Matricula: A01282504
 Nombre:    Patricio Saldivar Flores
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool iguales(vector<int> &d, int k){
    if(k>0 && d.size() > 1){
    map<int,int> myMap;
    map<int,int>::iterator it;
    
    for (int i=0; i<d.size(); i++) {
        it = myMap.find(d[i]);
        if(it != myMap.end()){
        if (i-it->second <= k)
            return true;
        }
        myMap[d[i]]=i;
        }
    }
    return false;
}

int main(){
    cout<<"Empieza:\n";
    int n, k;
    cin >> n >> k;
    vector<int> datos(n);
    for (int i=0; i<n; i++){
        cin>>datos[i];
    }
    cout << (iguales(datos, k)? "YES" : "NO") <<endl;
}

/*
 Ejemplo 1
 4 3
 1 2 3 1
 
 Ejemplo 2
 4 1
 1 0 1 1
 
 Ejmplo 3
 6 2
 1 2 3 1 2 3
 
 */
