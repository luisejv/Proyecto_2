#include <iostream>
#include <fstream>
#include "container.cpp"
#include <list>
#include <sstream>
#include <vector>

using std::ios, std::list, std::stringstream, std::vector;

int main() {
    std::fstream archivo;
    archivo.open("sample_data.csv", ios::in);
    string line, word, temp;
    list<int> datos;
    vector<string> fila;
    while (archivo >> temp){
        datos.clear();
        getline(archivo, line);
        stringstream s(line);
        while (getline(s, word, ',')){
            fila.push_back(word);
        }

    }
    return 0;
}