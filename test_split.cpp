/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{

    // TEST CASE 1: 1,2,3,4
    Node* in = nullptr;

    for (int i = 1; i <= 4; i++) {
        Node* newNode = new Node(i, nullptr); 

        if (in == nullptr) {
            in = newNode;
        }
        else 
        {
            Node* temp = in; 
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    Node* temp = in; 
    Node* evens = nullptr;
    Node* odds = nullptr; 

    split(in, odds, evens);

    std::cout << "Evens: ";
    temp = evens; 
    while (temp != nullptr) {
        std::cout << temp->value << ",";
        temp = temp->next;
    }

    std::cout << "Odds: ";
    temp = odds; 
    while (temp != nullptr) {
        std::cout << temp->value << ",";
        temp = temp->next;
    }
    
    while (odds != nullptr) {
        Node* temp = odds;
        odds = odds->next;
        delete temp;
    }

    while (evens != nullptr) {
        Node* temp = evens; 
        evens = evens->next;
        delete temp; 
    }

    // TEST CASE: NULL INPUT
    Node* in_null = nullptr; 
    Node* evens_null = nullptr; 
    Node* odds_null = nullptr; 
    split(in_null, odds_null, evens_null); 

    std::cout << "Evens: ";
    temp = evens; 
    while (temp != nullptr) {
        std::cout << temp->value << ",";
        temp = temp->next;
    }

    std::cout << "Odds: ";
    temp = odds; 
    while (temp != nullptr) {
        std::cout << temp->value << ",";
        temp = temp->next;
    }

    return 0; 
}
