//
//  main.cpp
//  Reto Semestral 1
//
//  Created by Pato Saldivar on 2/7/19.
//  Copyright © 2019 Pato Saldivar. All rights reserved.
//

#include <iostream>
using namespace std;

 struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
 };


ListNode* deleteUnique(ListNode* head) {
        ListNode *curr;
        ListNode *newHead = NULL;
        ListNode *lastOfNewHead = NULL;
        int numPasado;
        
        while(head != NULL && head->next!= NULL){
            curr = head;
            head= head->next;
            
            // Checo los pares
            if(head->val == curr->val){
                numPasado= head->val;
                head = head->next;
                curr->next->next= NULL;
                
                // Checo si es el primero que detecta
                if (newHead == NULL) {
                    newHead=curr;
                    lastOfNewHead = curr->next;
                }else{
                    lastOfNewHead->next =curr;
                    lastOfNewHead = curr->next;
                }
                
                // CAso en el que sea impar ([1,1,1,2])
            }else if (newHead != NULL && numPasado == curr->val){
                curr->next=NULL;
                lastOfNewHead->next =curr;
                lastOfNewHead = curr;
            }
            //Borra la memoria extra ya que ninguno se repetia
            else
                delete curr;
        }
        // Checo si el ultimo head era impar y no lo cheque
        if(head != NULL && head->val == numPasado){
            lastOfNewHead->next= head;
        }
        return newHead;
    }



int main() {
    
}
