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
|   File    : Parser.cpp                                                  |
|   Created : 04-Dec-2011                                                 |
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

#include "Parser.hpp"
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace boost;

Parser::Parser() {
    theScale = "1";
    theInitPos.push_back("0");
    theInitPos.push_back("0");
    theInitAng = "0";
}

void Parser::parse(ifstream& file) {
    string line, instros;
    char cLine;
    while (file.good()) {
        getline(file, line);
        if (!line.empty()) { // Skip blank lines
            // Skip comments
            if (line.at(0) != '#') {
                tokenizer<> tok(line);
                tokenizer<>::iterator lineChar = tok.begin();
                if (!(*lineChar).compare("variables")) {
                    lineChar++;
                    for(lineChar; lineChar != tok.end(); lineChar++) {
                        cLine = (*lineChar).at(0);
                        theV.insert(cLine);
                    }
                } else if (!(*lineChar).compare("start")) {
                    lineChar++;
                    theW = *lineChar;
                } else if (!(*lineChar).compare("rules")) {
                    lineChar++;
                    for(lineChar; lineChar != tok.end(); lineChar++) {
                        cLine = (*lineChar).at(0);
                        lineChar++;
                        theP.insert(pair<char, string>(cLine,
                            (*lineChar)));
                    }
                } else if (!(*lineChar).compare("runIters")) {
                    lineChar++;
                    theNumIters = atoi((*lineChar).c_str());
                } else if (!(*lineChar).compare("tg")) {
                    lineChar++;
                    cLine = (*lineChar).at(0);
                    lineChar++;
                    instros.clear();
                    for(lineChar; lineChar != tok.end(); lineChar++) {
                        instros += *lineChar;
                        instros += " ";
                    }
                    theTurtle[cLine] = instros;
                } else if (!(*lineChar).compare("drawingReductionScale")) {
                    lineChar++;
                    theScale = *lineChar;
                } else if (!(*lineChar).compare("drawingInitPos")) {
                    lineChar++;
                    theInitPos[0] = *lineChar;
                    lineChar++;
                    theInitPos[1] = *lineChar;
                    // Check negatives
                    if (line.find("-") < line.find(",")) {
                        theInitPos[0].insert(0, "-");
                    }
                    if (line.rfind("-") > line.find(",")) {
                        theInitPos[1].insert(0, "-");
                    }
                } else if (!(*lineChar).compare("drawingInitAng")) {
                    lineChar++;
                    theInitAng = *lineChar;
                }
            }
        }
    }
}

set<char> Parser::getAlphabet() const {
    return theV;
}

string Parser::getAxiom() const {
    return theW;
}

multimap<char, string> Parser::getRules() const {
    return theP;
}

int Parser::getIterations() const {
    return theNumIters;
}

map<char, string> Parser::getTurtle() const {
    return theTurtle;
}

string Parser::getReductionScale() const {
    return theScale;
}

vector<string> Parser::getInitPos() const {
    return theInitPos;
}

string Parser::getInitAng() const {
    return theInitAng;
}

