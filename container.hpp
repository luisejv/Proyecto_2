#ifndef PROYECTO_2_CONTAINER_HPP
#define PROYECTO_2_CONTAINER_HPP

#include <string>

using std::string;

class Container {
private:
    string country;
    int year;
    int commCode;
    string commodity;
    string flow;
    long trade;
    long weight;
    string qttyName;
    long qtty;
    string categ;
public:
    Container(const string &country, int year, int commCode, const string &commodity, const string &flow, long trade,
              long weight, const string &qttyName, long qtty, const string &categ);
    //virtual void ordenar(string atributo) = 0;
};


#endif //PROYECTO_2_CONTAINER_HPP
