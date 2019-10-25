#include <iostream>
#include <fstream>
#include "container.cpp"
#include <list>
#include <sstream>
#include <vector>
#include <string>

using std::ios, std::cout, std::list, std::stringstream, std::vector;

void merge(list<int> datos, int first, int middle, int size){
    int L[middle - first + 1];
    int R[size - middle];
    auto it = datos.begin();
    for (int i = 0; i < first+middle-1; i++){
        L[i] = *(it + i + 1);
    }
    for (int j = 0; j < size - middle; j++){

    }

}

void mergeSort(list<int> datos, int first, int size){
    if (size > first) {
        int middle = (first+size-1)/2;
        mergeSort(datos, first, middle);
        mergeSort(datos, middle + 1, size);
        merge(datos, first, middle, size);
    };
}

int main() {
    string line;
    list<Container*> datosList;
    vector<Container*> datosVec;
    std::ifstream archivo;
    archivo.open("sample_data.csv", ios::in);
    if (!archivo.is_open()){
        cout << "Archivo fallo en leer"<< std::endl;
        return 0;
    }
    getline(archivo,line); //Para la cabecera
    string country, commodity, flow, qttyname, categ, tempYear, tempCommCode, tempTrade, tempWeight, tempQtty;
    int year, commCode;
    long trade, weight, qtty;
    while(getline(archivo, line)){
        datosVec.clear();
        stringstream s(line);
        getline(s, country, ',');
        getline(s, tempYear, ',');
        year = std::stoi(tempYear);
        getline(s, tempCommCode, ',');
        commCode = std::stoi(tempCommCode);
        getline(s, commodity, ',');
        getline(s, flow, ',');
        getline(s, tempTrade, ',');
        trade = (tempTrade == "") ? 0 : std::stoi(tempTrade);
        getline(s, tempWeight, ',');
        weight = (tempWeight == "") ? 0 : std::stoi(tempTrade);
        getline(s, qttyname, ',');
        getline(s, tempQtty, ',');
        qtty = (tempQtty == "") ? 0 : std::stoi(tempQtty);
        getline(s, categ, ',');
        Container* contain = new Container(country, year, commCode, commodity, flow, trade, weight, qttyname, qtty, categ);
        datosVec.push_back(contain);
    }
    return 0;
}