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
|   File    : Turtle.cpp                                                  |
|   Created : 06-Dec-2011                                                 |
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

#include "Turtle.hpp"
#include <string>
#include <map>
#include <vector>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

Turtle::Turtle() {
    starterLogoCode = "; Logo code automatically generated by L-system\n";
    starterLogoCode += "\nmake \"stackPOS []\nmake \"stackANG []\nsetpencolor 7\nsetbackground 0\n";
}

string Turtle::rewrite(const string prod, map<char, string> corresp,
        string scale, vector<string> iniPos, string iniAng) const {
    string expansion;
    string::const_iterator charIt;
    string logoCode = starterLogoCode;
    // Initial setup
    logoCode += "hideturtle\n";
    logoCode += "pu setxy ";
    logoCode += iniPos[0];
    logoCode += " ";
    logoCode += iniPos[1];
    logoCode += " pd\n";
    logoCode += "setheading ";
    logoCode += iniAng;
    logoCode += "\n";
    // Drawing instructions
    for (charIt = prod.begin(); charIt < prod.end(); charIt++) {
        // Not all produced symbols have an associated graphical instro.
        expansion += corresp[*charIt];
        expansion += " "; // Just to ensure.
    }
    // Translation of the drawing instructions
    tokenizer<> tok(expansion);
    tokenizer<>::iterator expToken;
    for (expToken = tok.begin(); expToken != tok.end(); expToken++) {
        if (!(*expToken).compare("drawForward")) {
            logoCode += "fd ";
            expToken++;
            // scaling
            logoCode += *expToken;
            logoCode += " / ";
            logoCode += scale;
            logoCode += "\n";
        } else if (!(*expToken).compare("pushPos")) {
            logoCode += "push \"stackPOS pos\n";
        } else if (!(*expToken).compare("pushAng")) {
            logoCode += "push \"stackANG heading\n";
        } else if (!(*expToken).compare("turnLeft")) {
            logoCode += "lt ";
            expToken++;
            logoCode += *expToken;
            logoCode += "\n";
        } else if (!(*expToken).compare("turnRight")) {
            logoCode += "rt ";
            expToken++;
            logoCode += *expToken;
            logoCode += "\n";
        } else if (!(*expToken).compare("popPos")) {
            logoCode += "pu setpos pop \"stackPOS pd\n";
        } else if (!(*expToken).compare("popAng")) {
            logoCode += "setheading pop \"stackANG\n";
        }
    }
    return logoCode;
}
