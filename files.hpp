#pragma once

#include <fstream>

using namespace std;
fstream openFile(string nome){
    fstream arq;
    arq.open(nome, std::fstream::in | std::fstream::trunc);
    return arq;

fstream readFile(string nome){
    fstream arq;
    arq.open(nome, std::fstream::out );
    return arq;
}