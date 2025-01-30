#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr dat; 

    // Push back case 1: empty list 
    dat.push_back("a");
    if (dat.size() == 1 && dat.back() == "a")
    {
        std::cout << "Push back with empty list success" << std::endl; 
    }

    // Push back case 2: space exists 
    dat.push_back("i");
    if(dat.size() == 2 && dat.back() == "i")
    {
        std::cout << "Push back with existing space success" << std::endl;
    }

    // Push back case 3: not enough space
    for (int i = 0; i < 8; i++)
    {
        dat.push_back(std::to_string(i + 2));
    }
    dat.push_back("y");
    if (dat.size() == 10 && dat.back() == "y")
    {
        std::cout << "Push back with not enough space success" << std::endl; 
    }

    // Push front case 1: empty list
    dat.clear();
    dat.push_front("b");
    if (dat.size() == 1 && dat.front() == "b") {
        std::cout << "Push front with empty list success" << std::endl;
    } 

    // Push front case 2: space exists 
    dat.push_front("e");
    if(dat.size() == 2 && dat.front() == "e")
    {
        std::cout << "Push front with existing space success" << std::endl;
    }

    // Push front case 3: not enough space
    for (int i = 0; i < 8; i++)
    {
        dat.push_front(std::to_string(i + 2));
    }
    dat.push_front("j"); 
    if (dat.size() == 10 && dat.front() == "j")
    {
        std::cout << "Push front with not enough space success" << std::endl; 
    }

    // Pop back case 1: multiple items
    dat.clear(); 
    dat.push_back("q");
    dat.push_back("w");
    dat.pop_back(); 
    if (dat.size() == 1 && dat.front() == "q") {
        std::cout << "Pop back multi item success" << std::endl; 
    }
    
    // Pop back case 2: 1 item
    dat.pop_back();
    if (dat.size() == 0 && dat.empty()) {
        std::cout << "Pop back one item success" << std::endl;
    }

    // Pop back case 3: empty list
    dat.pop_back();
    if (dat.size() == 0 && dat.empty()) {
        std::cout << "Pop back empty list success" << std::endl;
    }

    // Pop front case 1: one item 
    dat.clear(); 
    dat.push_back("k");
    dat.pop_front(); 
    if (dat.size() == 0 && dat.empty()) {
        std::cout << "Pop front one item success" << std::endl;
    }

    // Pop front case 2: multiple items
    dat.push_back("q");
    dat.push_back("w");
    dat.pop_front();
    if (dat.size() == 1 && dat.front() == "w") {
        std::cout << "Pop front multi item success" << std::endl; 
    }

    // Pop front case 3: empty list
    dat.pop_front();
    dat.pop_front();
    if (dat.size() == 0 && dat.empty()) {
        std::cout << "Pop front empty list success" << std::endl;
    }

    // Back
    dat.clear();
    dat.push_back("t");
    dat.push_back("p");
    if (dat.back() == "p") {
        std::cout << "Back success" << std::endl;
    }

    // Front
    dat.clear();
    dat.push_back("t");
    dat.push_back("p");
    if (dat.front() == "t") {
        std::cout << "Front success" << std::endl;
    }

    // Get function test
    dat.clear();
    dat.push_back("apple");
    dat.push_back("banana");
    if (dat.get(0) == "apple" && dat.get(1) == "banana") {
        std::cout << "Get function success" << std::endl;
    } else {
        std::cout << "Get function failed" << std::endl;
    }

    return 0;
}

