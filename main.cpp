#include <iostream>
#include <fstream>
#include "container.hpp"
#include <list>
#include <sstream>
#include <vector>
#include <string>
#include "Sorter.hpp"
#include "map.h"
#include <iterator>


using std::ios, std::cout, std::list, std::stringstream, std::vector, std::ofstream;


void Guardar(ofstream& archivo, vector<Map*>* arreglo){
    auto iter = arreglo->begin();
    string delim = ",";
    archivo << "country_or_area,year,comm_code,commodity,flow,trade_usd,weight_kg,quantity_name,quantity,category\n";
    while (iter != arreglo->end()){
        archivo << (*iter)->getCountry_or_area() << delim;
        archivo << (*iter)->getYear() << delim;
        archivo << (*iter)->getComm_code() << delim;
        archivo << (*iter)->getCommodity() << delim;
        archivo << (*iter)->getFlow() << delim;
        archivo << (*iter)->getTrade_usd() << delim;
        archivo << (*iter)->getWeight_kg() << delim;
        archivo << (*iter)->getQuantity_name() << delim;
        archivo << (*iter)->getQuantity() << delim;
        archivo << (*iter)->getCategory() << delim;
        iter++;
    }
    archivo.close();
}

int main() {
    Container * cont1 = new Container("abc.csv");
    Container * cont2 = new Container("abc.csv");
    Container * cont3 = new Container("abc.csv");
    Container * cont4 = new Container("abc.csv");
    Container * cont5 = new Container("abc.csv");
    Container * cont6 = new Container("abc.csv");
    Container * cont7 = new Container("abc.csv");
    Container * cont8 = new Container("abc.csv");

    cont1->pruebas();

    Sorter<Quick> Sort1;
    Sorter<Merge> Sort2;
    Sorter<Shell> Sort3;
    Sorter<Heap> Sort4;

    Sort1(cont1->getElements(), cont1->getElements()->begin(), cont2->getElements()->end()-1, "trade_usd");
    Sort1(cont2->getElements(), cont2->getElements()->begin(), cont2->getElements()->end()-1, "country_or_area", "year", "trade_usd");
    Sort2(cont3->getElements(), cont3->getElements()->begin(), cont3->getElements()->end()-1, "trade_usd");
    Sort2(cont4->getElements(), cont4->getElements()->begin(), cont4->getElements()->end()-1, "country_or_area", "year", "trade_usd");
    Sort3(cont5->getElements(), cont5->getElements()->begin(), cont5->getElements()->end()-1, "trade_usd");
    Sort3(cont6->getElements(), cont6->getElements()->begin(), cont6->getElements()->end()-1, "country_or_area", "year", "trade_usd");
    Sort4(cont7->getElements(), cont7->getElements()->begin(), cont7->getElements()->end()-1, "trade_usd");
    Sort4(cont8->getElements(), cont8->getElements()->begin(), cont8->getElements()->end()-1, "country_or_area", "year", "trade_usd");

    ofstream archivo;
    archivo.open("Quick.csv");
    Guardar(archivo, cont1->getElements());
    archivo.open("Quick3.csv");
    Guardar(archivo, cont2->getElements());
    archivo.open("Merge.csv");
    Guardar(archivo, cont3->getElements());
    archivo.open("Merge3.csv");
    Guardar(archivo, cont4->getElements());
    archivo.open("Shell.csv");
    Guardar(archivo, cont5->getElements());
    archivo.open("Shell3.csv");
    Guardar(archivo, cont6->getElements());
    archivo.open("Heap.csv");
    Guardar(archivo, cont7->getElements());
    archivo.open("Heap3.csv");
    Guardar(archivo, cont8->getElements());

    delete cont1;
    delete cont2;
    delete cont3;
    delete cont4;
    delete cont5;
    delete cont6;
    delete cont7;
    delete cont8;

    return 0;
}


