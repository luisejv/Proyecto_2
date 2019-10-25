//
// Created by PEPE JÁUREGUI on 22/10/2019.
//

#include "container.hpp"

Container::Container(const string &country, int year, int commCode, const string &commodity, const string &flow,
                     long trade, long weight, const string &qttyName, long qtty, const string &categ) : country(
        country), year(year), commCode(commCode), commodity(commodity), flow(flow), trade(trade), weight(weight),
                                                                                                        qttyName(
                                                                                                                qttyName),
                                                                                                        qtty(qtty),
                                                                                                        categ(categ) {}
