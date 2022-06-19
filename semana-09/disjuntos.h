#ifndef DISJUNTOS_HPP
#define DISJUNTOS_HPP

#include <iostream>
#include <unordered_map>

using namespace std;

class Disjuntos{
private:
    int last;
    unordered_map<int, int> dis;

    static int to_negative(int n) { return n < 0 ? n:n * -1; }
public:
    
    Disjuntos(int n) { 
        this->last = n;
    }

    int une(int x, int y){
        if (dis.find(x) != dis.end()) {
            return dis[x] = une(dis.at(x), y);
        } else if (dis.find(y) != dis.end()) {
            return dis[y] = une(x, dis.at(y));
        } else {
            dis[x] = last;
            dis[y] = last;
            return last++;
        }
        return -1;
    }

    void print_map() {
        for (auto i:dis) 
            cout << i.first << ": " << i.second << ", ";
        cout << '\n';
    }

    int mesmo(int x, int y){
        // caso exista alguem suba um nivel
        if (dis.find(x) != dis.end()) {
            dis[x] = dis.at(dis.find(x)->first);
            return mesmo(dis.at(x), y);
        }
        // caso exista alguem suba um nivel
        if (dis.find(y) != dis.end()) {
            dis[y] = dis.at(dis.find(y)->first);
            return mesmo(x, dis.at(y));
        }
        if (x != y) return 0;
        return 1;
    }
};


#endif