/*
                                                          _
                                                        _(_)_       _
     _                             _                   (_)@(_)    _(_)_
    | |              ___ _   _ ___| |_ ___ _ __ ___      (_)\    (_)@(_)
    | |      _____  / __| | | / __| __/ _ \ '_ ` _ \        |     /(_)
    | |___  |_____| \__ \ |_| \__ \ ||  __/ | | | | |      \|/   \|/
    |_____|         |___/\__, |___/\__\___|_| |_| |_|    \\\|//\\\|///
 ________________________ |___/ ________________________________________
|                                                                      |\
|                                                                      |_\
|   File    : Lsystem.cpp                                                 |
|   Created : 03-Dec-2011                                                 |
|   By      : atrilla                                                     |
|                                                                         |
|   L-system - Parallel string rewriting system                           |
|                                                                         |
|   Copyright (c) 2011 Alexandre Trilla                                   |
|                                                                         |
|   -------------------------------------------------------------------   |
|                                                                         |
|   This file is part of L-system.                                        |
|                                                                         |
|   L-system is free software: you can redistribute it and/or modify it   |
|   under the terms of the MIT/X11 License as published by the            |
|   Massachusetts Institute of Technology. See the MIT/X11 License for    |
|   more details.                                                         |
|                                                                         |
|   You should have received a copy of the MIT/X11 License along with     |
|   this source code distribution of L-system (see the COPYING            |
|   file in the root directory). If not, see                              |
|   <http://www.opensource.org/licenses/mit-license>.                     |
|________________________________________________________________________*/

#include "Lsystem.hpp"
#include <string>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

Lsystem::Lsystem() {
}

Lsystem::Lsystem(const set<char> &vars, const string start,
        const multimap<char, string> &rules) {
    theVariables = vars;
    theStart = start;
    theRules = rules;
    srand(time(NULL));
}

string Lsystem::produce(const int numIter) const {
    string production = theStart;
    string aux;
    string::const_iterator prodIter;
    multimap<char, string>::const_iterator ruleIter;
    int numRules, chance, epoch;
    for (epoch = 0; epoch < numIter; epoch++) {
        aux.clear();
        for (prodIter = production.begin(); prodIter < production.end();
                prodIter++) {
            numRules = theRules.count(*prodIter);
            if (numRules > 0) {
                chance = rand()%numRules;
                for (ruleIter = theRules.lower_bound(*prodIter);
                        ruleIter != theRules.upper_bound(*prodIter);
                        ruleIter++) {
                    if (!chance) {
                        aux += (*ruleIter).second;
                        break;
                    }
                    chance--;
                }
            } else {
                aux += *prodIter;
            }
        }
        production = aux;
    }
    return production;
}

