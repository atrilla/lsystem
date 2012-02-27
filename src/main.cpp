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
|   File    : main.cpp                                                    |
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
#include "Parser.hpp"
#include "Turtle.hpp"
#include <string>
#include <set>
#include <map>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char* argv[]) {
    Parser p;
    ifstream f(argv[1]);
    string prod, drawing;
    if (f.is_open()) {
        p.parse(f);
        f.close();
        Lsystem lsys(p.getAlphabet(), p.getAxiom(), p.getRules());
        prod = lsys.produce(p.getIterations());
        Turtle ninja;
        drawing = ninja.rewrite(prod, p.getTurtle(),
            p.getReductionScale(), p.getInitPos(), p.getInitAng());
        cout << drawing;
        return EXIT_SUCCESS;
    } else {
        cout << "error opening file" << endl;
        return EXIT_FAILURE;
    }
}

