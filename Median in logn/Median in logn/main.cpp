//
//  main.cpp
//  Median in logn
//
//  Created by Pato Saldivar on 3/14/19.
//  Copyright © 2019 Pato Saldivar. All rights reserved.
//

/*
 
 
 Description:
 
 Given a set of 2n integers data were separated into two arrays of size n, and every array was ordered ascending, and knowing that there are no repeated 2n values. They want to find the median of the set of 2n data. The median of a data set, that data is having 50% of those under him data and 50% of older data to it.
 
 It uses the strategy of divide and conquer, to design an algorithm that computes the median of 2n data in the two arrays (1 <= n <= 100).
 
 The algorithm you get must have a base 2 logarithmic or better order, O (log2 n).
 
 
 Input:
 First comes t the number of cases, for each case comes the size of the arrays (n), then comes n integers of the first array and n integer of the second array. The data of the arrays are positive integers no greather than 10^4.
 
 
 Output:
 Each case will come a floating number with two decimal representing the median of all 2n data with the presentation format of the sample input.
 
 Sample Input:
 
 2
 5
 1
 4
 7
 8
 10
 2
 9
 11
 14
 15
 3
 2
 4
 5
 1
 3
 6
 
 Sample Output:
 
 Median case 1: 8.50
 Median case 2: 3.50
 
*/

#include <iostream>
#include <iomanip>
using namespace std;


int BinarySearch(int arr[], int arr2[], int n){
    int left=0;
    int right=n-1;
    while (left<=right) {
        int mid = (left+right)/2;
        int index = n-mid-2;
        if(index<0){
            return arr[n-1]+arr2[0];
        }
        else if (arr[mid]<arr2[index+1] && arr2[index]<arr[mid+1]) {
            int median= (arr[mid]>arr2[index])? arr[mid] : arr2[index];
            return (arr[mid+1]<arr2[index+1])? arr[mid+1]+median : arr2[index+1]+median;
        }
        else if (arr[mid]>arr2[index+1]) {
            right= mid-1;
        }else
            left = mid+1;
    }
    return arr[0]+arr2[n-1];
}


void GetMedian(int t){
    int n;
    cin>>n;
    int arr[n], arr2[n];
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    for (int i=0; i<n; i++) {
        cin>>arr2[i];
    }
    double ans =BinarySearch(arr, arr2, n);
    ans/=2;
    //Fixed function works to add 0 to a float or double variable (strram manipulation)
    //Setprecision works to set the decimal limit to work on (stream manipulation)
    cout<<"Median case "<<t+1<<": "<<setprecision(2)<<fixed<<ans<<"\n";
}


int main() {
    int t;
    cin>>t;
    for (int i=0; i<t; i++) {
        GetMedian(i);
    }
    
    return 0;
}

