//
// Created by A. Harrison Owen on 4/17/2021.
//

#ifndef CS202HW5_READWRITE_READWRITE_H
#define CS202HW5_READWRITE_READWRITE_H

#include <iostream>
#include <string>
#include <fstream>

template<class T>
void myWrite(std::ofstream & ofile, T &a){
    if(ofile){
        ofile.write(reinterpret_cast<const char *>(&a), sizeof(a));
    }
    return;
}

template <class T>
void myRead(std::ifstream &ifile, T &a){
    if(ifile){
        ifile.read(reinterpret_cast<char *>(&a), sizeof(a));
    }
    return;
}

#endif //CS202HW5_READWRITE_READWRITE_H
