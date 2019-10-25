//
// Created by Macarena Oyague on 2019-10-24.
//

#ifndef PROJECT_MAP_H
#define PROJECT_MAP_H

#include <string>
using namespace std;


class Map {
private:
    string country_or_area;
    int year;
    unsigned long int comm_code;
    string commodity;
    string flow;
    unsigned long int trade_usd;
    unsigned long int weight_kg;
    string quantity_name;
    unsigned long int quantity;
    string category;
public:
    Map(string country_or_area, int year, unsigned long int comm_code,
        string commodity, string flow, unsigned long int trade_usd,
        unsigned long int weight_kg, string quantity_name,
        unsigned long int quantity, string category)
    {
        this->country_or_area = country_or_area;
        this->year = year;
        this->comm_code = comm_code;
        this->commodity = commodity;
        this->flow = flow;
        this->trade_usd = trade_usd;
        this->weight_kg = weight_kg;
        this->quantity_name = quantity_name;
        this->quantity = quantity;
        this->category = category;
    }
    //setters para el ordenamiento
};


#endif //PROJECT_MAP_H
