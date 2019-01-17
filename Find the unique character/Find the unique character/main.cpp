//
//  main.cpp
//  Find the unique character
//
//  Created by Pato Saldivar on 1/16/19.
//  Copyright © 2019 Pato Saldivar. All rights reserved.
/*
 
 Description:
 
 Given a string that contains several characters in duplicate and continuous, except  one character, find the unique character within the string.
 
 Input:
 One string
 
 Ouput:
 Write the unique character in a line.
 
 Sample Input:
 AABCCDDEEFF
 
 Sample Output:
 B
 

 */

#include <iostream>
#include <string>
using namespace std;

char binarySearch(string linea){
    long central, bajo, alto, n;
    char valorCentral;
    bajo = 0;
    n = linea.length();
    if (n % 2 == 0){
        return ' ';
    }
    alto = n-1;
    while (bajo <= alto) {
        central = (bajo + alto)/2;
        valorCentral = linea[central];
        
        if (valorCentral != linea[central+1] && valorCentral != linea[central-1])
            return valorCentral;
        
        else if (valorCentral == linea[central+1]) {
            
            if (((alto - (central+1)) % 2 != 0) && (alto - (central + 1)) != 0) {
                bajo = central + 2;
            }else
                alto = central - 1;
            
        }else{
            if (((central-1) - bajo) % 2 == 0) {
                bajo = central + 1;
            }else
                alto = central - 2;
        }
        
    }
    return ' ';
}


int main() {
    cout<<"Empieza:\n";
    string lineaCompleta;
    cin>>lineaCompleta;
    char ans = binarySearch(lineaCompleta);
    cout<<ans<<endl;
    
    return 0;
}
