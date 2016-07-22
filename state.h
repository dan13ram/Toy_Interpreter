#ifndef _STATE_H
#define _STATE_H

#include<iostream>
#include<utility>
#include<string>
#include<vector>

using namespace std;

class State{

        vector<pair<string,int > > varCol;
        
        public:
        
        int getVal(string );				//returns VarExpr who's name is given as nm
        bool exists(string );
        void setVar(string ,int );
        void print();
};


#endif // _STATE_H
