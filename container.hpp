#ifndef PROYECTO_2_CONTAINER_HPP
#define PROYECTO_2_CONTAINER_HPP

#include <string>

using std::string;

enum Flow {Import, Export};
class Container {
private:
    string country;
    int year;
    int commCode;
    string commodity;
    Flow flow;
    long trade;
    long weight;
    string q_name;
    long qtty;
    string categ;
public:
    Container(const string &country, int year, int commCode, const string &commodity, Flow flow, long trade,
              long weight, const string &qName, long qtty, const string &categ);
};


#endif //PROYECTO_2_CONTAINER_HPP
