//
//  main.cpp
//  Multiplicacion de Matrices adaptado a cutting sticks
//
//  Created by Pato Saldivar on 3/8/19.
//  Copyright © 2019 Pato Saldivar. All rights reserved.
/*
 Description:
 
 You have to cut a wood stick into pieces. The most affordable company, The Analog Cutting Machinery, Inc. (ACM), charges money according to the length of the stick being cut. Their procedure of work requires that they only make one cut at a time.
 
 It is easy to notice that different selections in the order of cutting can led to different prices. For example, consider a stick of length 10 meters that has to be cut at 2, 4 and 7 meters from one end. There are several choices. One can be cutting first at 2, then at 4, then at 7. This leads to a price of 10 + 8 + 6 = 24 because the first stick was of 10 meters, the resulting of 8 and the last one of 6. Another choice could be cutting at 4, then at 2, then at 7. This would lead to a price of 10 + 4 + 6 = 20, which is a better price.
 
 Your boss trusts your computer abilities to find out the minimum cost for cutting a given stick.
 
 Input:
 
 The input will consist of several input cases. The first line of each test case will contain a positive number l that represents the length of the stick to be cut. You can assume l < 1000. The next line will contain the number n (n <= 50) of cuts to be made. The next line consists of n positive numbers ci ( 0 < ci < l) representing the places where the cuts have to be done, given in strictly increasing order. An input case with l = 0 will represent the end of the input.
 
 Output:
 
 You have to print the cost of the optimal solution of the cutting problem, that is the minimum cost of cutting the given stick. Format the output as shown below.
 
 
 Sample Input:
 
 100
 3
 25 50 75
 10
 4
 4 5 7 8
 0
 
 Sample Output:
 
 The minimum cutting is 200.
 The minimum cutting is 22.
 


 */
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MM(vector<int> cuts){
    int j;
    vector<vector<int>> mat(cuts.size()-1,(vector<int> (cuts.size()-1,INT_MAX)));
    for (int i=0; i<cuts.size()-1; i++) {
        mat[i][i]=0;
    }
    for (int diagonal=1; diagonal<cuts.size()-1; diagonal++) {
        for (int i=0; i<cuts.size()-diagonal-1; i++) {
        j=i+diagonal;
            for (int k=i; k<j; k++) {
                if(mat[i][j]> mat[i][k]+mat[k+1][j]){
                    mat[i][j]= mat[i][k]+mat[k+1][j];
                }
            }
             mat[i][j]+= cuts[j+1]-cuts[i];
        }
    }
    
    
    return mat[0][cuts.size()-2];
}


int main() {
    int length=1, n, x;
    vector<int> cuts;
    cin>>length;
    while (length!=0) {
        cin>>n;
        cuts.push_back(0);
        for (int i=0; i<n; i++) {
            cin>>x;
            cuts.push_back(x);
        }
        cuts.push_back(length);
        cout<<"The minimum cutting is "<<MM(cuts)<<"."<<endl;
        cin>>length;
        cuts.erase(cuts.begin(),cuts.end());
        
    }
    
    
    
    return 0;
}
