#ifndef RAIOS_HPP
#define RAIOS_HPP

#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;


class Raios{
private:
    unordered_map<string, int> raios;
    int X;
    int Y;
    int same {0};
public:
    
    Raios(int n, int m): 
        X(n), Y(m){ 
    }

    void add(int x, int y){
        if (x > X || y > Y) return;
        stringstream key;
        key << x;
        key << ',';
        key << y;
        if (raios.find(key.str()) == raios.end()) {
            raios.insert({key.str(), 1});
        }
        else {
            raios[key.str()] = raios.at(key.str()) + 1;
            same++;
        }
    }

    int mesmo_lugar(){
        if (same > 0) return 1;
        return 0;
    }

    void print() {
        for (auto i: raios) 
            cout << i.first << ": " << i.second << ", ";
    }
};

#endif

// #ifndef RAIOS_HPP
// #define RAIOS_HPP

// #include <bits/stdc++.h>

// using namespace std;

// class Raios{

//     private:
       
//     public:
    
//     Raios(int n, int m){ 
        
//     }

//     void add(int x, int y){
        
//     }

//     int mesmo_lugar(){
       
//     }
// };

// #endif