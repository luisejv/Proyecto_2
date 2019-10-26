//
// Created by PEPE JÁUREGUI on 26/10/2019.
//

#ifndef PROYECTO_2_QUICK_HPP
#define PROYECTO_2_QUICK_HPP
class Quick{
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
        auto inicio = first;
        auto fin = end;
        auto middle = first + (fin-inicio)/2;
        auto pivote = (*middle)->getTrade_usd();
        int inicioLimite, finLimite;
        do{
            inicioLimite = (*inicio)->getTrade_usd();
            finLimite = (*fin)->getTrade_usd();
            if ((inicioLimite >= pivote) && (finLimite <= pivote)){
                cambiar(*inicio, *fin);
                inicio++;
                fin--;
            }
            if (inicioLimite < pivote){
                inicio++;
            }
            if (finLimite > pivote){
                fin--;
            }
        }while(inicio <= fin);
        if (first < fin){
            sort(container, first, fin, atr);
        }
        if (inicio < end){
            sort(container, inicio, end, atr);
        }
    }
    template<typename T, typename iterador>
    void sort(T* container, iterador first, iterador end, string atr, string atr2, string atr3){
        auto inicio = first;
        auto fin = end;
        auto middle = first + (fin-inicio)/2;
        do{
            if (comparar(middle, inicio) && comparar(fin, middle)){
                cambiar(*inicio, *fin);
                inicio++;
                fin--;
            }
            if (comparar(inicio, middle)){
                inicio++;
            }
            if (comparar(middle, fin)){
                fin--;
            }
        }while(inicio<=fin);
        if (first < fin){
            sort(container, first, fin, atr, atr2, atr3);
        }
        if (inicio < end){
            sort(container, inicio, end, atr, atr2, atr3);
        }
    }
};
#endif //PROYECTO_2_QUICK_HPP
