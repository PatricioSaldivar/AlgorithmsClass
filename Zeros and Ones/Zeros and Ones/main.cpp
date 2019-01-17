//
//  main.cpp
//  Zeros and Ones
//  Created by Pato Saldivar on 1/17/19.
//  Copyright © 2019 Pato Saldivar. All rights reserved.
//
/*Description:
Jemes the Android is a galaxy-famous detective. In his free time he likes to think about strings containing zeros and ones. Once he thought about a string of length n consisting of zeroes and ones. Consider the following operation: we choose any two adjacent positions in the string, and if one them contains 0, and the other contains 1, then we are allowed to remove these two digits from the string, obtaining a string of length n - 2 as a result. Now James thinks about what is the minimum length of the string that can remain after applying the described operation several times (possibly, zero)? Help him to calculate this number. Input First line of the input contains a single integer n (1  ≤ n  ≤  200000), the length of the string that James has. The second line contains the string of length n consisting only from zeros and ones. Output The minimum length of the string that may remain after applying the described operations several times.
Sample Input:
4
1100
 
 Sample Output:
 0
 */



#include <iostream>
#include <string>
using namespace std;

long MinimumLengthOfString(string linea, int n){
    int curr = 1, last = 0;
    while (curr<n) {
        if (linea[curr] != linea[last]) {
            linea.erase(last,2);
            if (last!=0) {
                last--;
                curr--;
            }
            n-=2;
        }else{
            curr++;
            last++;
        }
    }
    return linea.length();
}


int main(){
    cout<<"Empieza:\n";
    int n;
    string linea;
    cin>>n;
    cin>>linea;
    cout<<MinimumLengthOfString(linea, n)<<endl;
    return 0;
}

