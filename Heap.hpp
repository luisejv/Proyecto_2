//
// Created by PEPE JÁUREGUI on 26/10/2019.
//

#ifndef PROYECTO_2_HEAP_HPP
#define PROYECTO_2_HEAP_HPP

#include <string>
class Heap{
public:
    template <typename T, typename iterador>
    void sort(T* container, iterador first, iterador end, string atributo){
        auto temp = end - first;
        temp++;
        for (auto i = temp/2 - 1; i >= 0; i--){
            heap(container, temp, i, atributo);
        }
        for (auto i = temp - 1; i >= 0; i--){
            std::swap(*(container->begin()), *(container->begin()+i));
            heap(container, i, 0, atributo);
        }
    }
    template <typename T, typename iterador>
    void sort(T* container, iterador first, iterador end, string atributo, string atributo2, string atributo3){
        auto temp = end - first;
        temp++;
        for (auto i = temp/2 - 1; i >= 0; i--){
            heap(container, temp, i, atributo, atributo2, atributo3);
        }
        for (auto i = temp - 1; i >= 0; i--){
            std::swap(*(container->begin()), *(container->begin()+i));
            heap(container, i, 0, atributo, atributo2, atributo3);
        }
    }
    template <typename T, typename iterador>
    void heap(T* container, iterador temp, iterador i, string atributo){
        int big = i;
        int izq = 2 * i + 1;
        int der = 2 * i + 2;

        if (izq < temp && (*(container->begin()+izq))->getTrade_usd() > (*(container->begin()+big))->getTrade_usd())
            big = izq;
        if (der < temp && (*(container->begin()+der))->getTrade_usd() > (*(container->begin()+big))->getTrade_usd())
            big = der;
        if (big != i){
            std::swap(*(container->begin()+i), *(container->begin()+big));
            heap(container, temp, big, atributo);
        }
    }
    template <typename T, typename iterador>
    void heap(T* container, iterador temp, iterador i, string atr, string atr1, string atr2){
        int big = i;
        int izq = 2 * i + 1;
        int der = 2 * i + 2;

        if (izq < temp){
            if ((*(container->begin()+izq))->getCountry_or_area() > (*(container->begin()+big))->getCountry_or_area())
                big = izq;
            else if ((*(container->begin()+izq))->getCountry_or_area() == (*(container->begin()+big))->getCountry_or_area()){
                if ((*(container->begin()+izq))->getYear() > (*(container->begin()+big))->getYear())
                    big = izq;
                else if ((*(container->begin()+izq))->getYear() == (*(container->begin()+big))->getYear()){
                    if ((*(container->begin()+izq))->getTrade_usd() > (*(container->begin()+big))->getTrade_usd())
                        big = izq;
                }
            }
        }
        if (der < temp){
            if ((*(container->begin()+der))->getCountry_or_area() > (*(container->begin()+big))->getCountry_or_area())
                big = der;
            else if ((*(container->begin()+der))->getCountry_or_area() == (*(container->begin()+big))->getCountry_or_area()){
                if ((*(container->begin()+der))->getYear() > (*(container->begin()+big))->getYear())
                    big = der;
                else if ((*(container->begin()+der))->getYear() == (*(container->begin()+big))->getYear()){
                    if ((*(container->begin()+der))->getTrade_usd() > (*(container->begin()+big))->getTrade_usd())
                        big = der;
                }
            }
        }
        if (big != i){
            std::swap(*(container->begin()+i), *(container->begin()+big));
            heap(container, temp, big, atr, atr1, atr2);
        }
    }
};
#endif //PROYECTO_2_HEAP_HPP
