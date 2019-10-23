//
// Created by PEPE JÁUREGUI on 22/10/2019.
//

#include "container.hpp"

Container::Container(const string &country, int year, int commCode, const string &commodity, Flow flow, long trade,
                     long weight, const string &qName, long qtty, const string &categ) : country(country), year(year),
                                                                                         commCode(commCode),
                                                                                         commodity(commodity),
                                                                                         flow(flow), trade(trade),
                                                                                         weight(weight), q_name(qName),
                                                                                         qtty(qtty), categ(categ) {}
