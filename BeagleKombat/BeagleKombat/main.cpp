//
//  main.cpp
//  BeagleKombat
//
//  Created by Pato Saldivar on 3/14/19.
//  Copyright © 2019 Pato Saldivar. All rights reserved.
/*
 
 ----------------------------------------------------------------------------------------
 The beagles in BeagleTown love to play BeagleKombat, which has 26 buttons (from ‘a’ to ‘z’).
 The game consist in make the more damage possible clicking buttons but is not possible to push the same button more than k times continues.
 Having a hit button sequence and their damage per each one, say the maximum damage that any beagle could make with this.
 
 
 Input
 In first line comes n -the length of the hit button sequenceand k –the maximum times hit the same button in continues way(1<=k<=n<=2*10⁵)
 In the second line comes the damage of each button (1<=a[i]<=10⁹)
 In the third line comes a string with n letters meaning the button sequence hit.
 
 Output
 An integer meaning the maximumpossible damageof the game.
 
 Sample Input
 7 3
 1 5 16 18 7 2 10
 baaaaca
 
 Sample Output
 54
 ----------------------------------------------------------------------------------------
 */

#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;


// Custom compare structure made for getting from lower indexes and from greater values
struct Comapre {
    bool operator() (const pair<char, int>& lhs, const pair<char, int>& rhs) const{
        if(lhs.first!=rhs.first)
            return lhs.first<rhs.first;
        else
            return lhs.second>rhs.second;
    }
};

int main() {
    set<pair<char,int>,Comapre> buttonPower;
    set<pair<char,int>> :: iterator it;
    vector<int> damage;
    map<char,int> howManySum;
    int n,k,power,counter=0;
    long sum=0;
    char button, beforeButton=' ';
    cin>>n>>k;
    for (int i=0; i<n; i++) {
        cin>>power;
        damage.push_back(power);
    }
    //Fills all the damage points of each buttons, at same counts the valid press of the buttons
    for (int i=0; i<n; i++) {
        cin>>button;
        if (beforeButton==button) {
            counter++;
        }else{
            beforeButton = button;
            counter=0;
        }
        if (counter<k){
            howManySum[button]++;
        }
        buttonPower.insert(pair<char,int>(button,damage[i]));
    }
    
    
    button='a'; //Our loop will start with the lower letter of the button which is a if possible, so we intialize for the fist comparison
    counter=-1; //Our loop sums up a one in the counter when the button matches so by starting in -1 wll repair the case of getting a as first button
    
    //Sums up all the valid buttons and jumps the lower invalid for the greatest posible damage
    for (it=buttonPower.begin(); it!=buttonPower.end(); ++it){
        if (button==(*it).first) {
            counter++;
        }else{
            button=(*it).first;
            counter=0;
        }
        if (counter<howManySum[button]) {
            sum+= (*it).second;
        }
    }
    cout<<sum<<endl;
}
