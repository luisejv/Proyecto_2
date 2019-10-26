#ifndef PROYECTO_2_CONTAINER_HPP
#define PROYECTO_2_CONTAINER_HPP

#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "map.h"
#include "deserializador.h"
#include "Sorter.hpp"


class Container {
private:
    vector <Map*>* elements;
    //cambiar a generico
    DeserializadorMap deserializador;
public:
    explicit Container(const string& nombreArhivo){
        elements = new vector<Map*>();
        auto* archivo = new fstream(nombreArhivo, ios_base::in);
        string linea;
        if (!archivo->is_open()){
            cout << "Archivo fallo en leer"<< std::endl;
        }
        else{
            getline(*archivo,linea); //Para la cabecera
            while (getline(*archivo,linea)){
                    Map* element = deserializador.deserializar(linea, ',');
                    elements->push_back(element);
            }
            archivo->close();
        }
        delete archivo;
    }
    void pruebas(){
        for (Map *element: *elements)
        {
            cout<<element->getCountry_or_area()<<","<<element->getYear()<<","
                <<element->getComm_code()<<","<<element->getCommodity()<<","
                <<element->getFlow()<<","<<element->getTrade_usd()<<","
                <<element->getWeight_kg()<<","<<element->getQuantity_name()<<","
                <<element->getQuantity()<<","<<element->getCategory()<<endl;
        }
    }
    vector<Map*>* getElements(){
        return elements;
    }
    ~Container(){
        for (auto it : *elements){
            delete it;
        }
        delete elements;
    }
};



#endif //PROYECTO_2_CONTAINER_HPP
