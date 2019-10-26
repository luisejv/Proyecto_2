//
// Created by PEPE JÁUREGUI on 26/10/2019.
//

#ifndef PROYECTO_2_SHELL_HPP
#define PROYECTO_2_SHELL_HPP
class Shell{
public:
    template<typename T>
    bool comparar(T& ct1, T& ct2){
        if ((*ct1)->getCountry_or_area() < (*ct2)->getCountry_or_area()){
            return true;
        } else if ((*ct1)->getCountry_or_area() == (*ct2)->getCountry_or_area()){
            if ((*ct1)->getYear() < (*ct2)->getYear()){
                return true;
            } else if ((*ct1)->getYear() == (*ct2)->getYear()){
                if ((*ct1)->getTrade_usd() < (*ct2)->getTrade_usd())
                    return true;
            }
        }
        return false;
    }
    template<typename T>
    void cambiar(T& inicio, T& fin){
        auto temp = inicio;
        inicio = fin;
        fin = temp;
    }
    template<typename T, typename iterador>
    void sort(T* container, iterador first, iterador end, string atr){
        auto n = 2;
        auto pivot = first + (end - first)/n;
        while(pivot > first){
            auto ordenados = true;
            while(ordenados){
                auto cont = 0;
                auto j = first;
                auto iter = pivot;
                while (iter != end){
                    if((*j)->getTrade_usd()>(*iter)->getTrade_usd()){
                        cambiar(*j, *iter);
                        iter++;
                        j++;
                        cont++;
                        ordenados = true;
                    } else {
                        iter++;
                        j++;
                        ordenados = false;
                        if(cont >= 1){
                            ordenados = true;
                        }
                    }
                }
            }
            pivot = first + (pivot-first)/n;
        }
    }
    template<typename T, typename iterador>
    void sort(T* container, iterador first, iterador end, string atr, string atr2, string atr3){
        auto n = 2;
        auto pivot = first + (end - first)/n;
        while(pivot > first){
            auto ordenados = true;
            while(ordenados){
                auto cont = 0;
                auto j = first;
                auto iter = pivot;
                while (iter != end){
                    if(comparar(iter, j)){
                        cambiar(*j, *iter);
                        iter++;
                        j++;
                        cont++;
                        ordenados = true;
                    } else {
                        iter++;
                        j++;
                        ordenados = false;
                        if(cont >= 1){
                            ordenados = true;
                        }
                    }
                }
            }
            pivot = first + (pivot-first)/n;
        }
    }
};
#endif //PROYECTO_2_SHELL_HPP
