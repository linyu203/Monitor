#include "monitor.h"
#include <fstream>
#include <string>
#include <iostream>



int main(int args, char * arv[]){
    using namespace std;
    if(args != 2){
        return 1;
    }
    ifstream f(arv[1]);
    if(!f.is_open()){
        return 1;
    }
    Monitor m;
    string line;
    while(getline(f,line)){
        try{
            m.parseEvent(line);
        }
        catch (const exception& e){
            cout<<e.what()<<endl;
        }
    }

    return 0;
}



