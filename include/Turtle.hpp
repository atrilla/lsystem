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
|   File    : Turtle.hpp                                                  |
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

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include <string>
#include <map>
#include <vector>

using namespace std;

/**
 * @class Turtle
 * @brief Turtle graphics interface (Logo code generator).
 *
 * Generates Logo code from the string produced by iteration by the
 * L-system. The resulting code is outputted to the standard
 * output, and can thus be redirected into a file, to then be inputted
 * to a Logo interpreter such as
 * <a href="http://www.cs.berkeley.edu/~bh/logo.html">ucblogo</a>,
 * which is available in common user GNU/Linux software repos.
 *
 * @author Alexandre Trilla (atrilla)
 */
class Turtle {
    public:
        /**
         * @brief Turtle constructor.
         * @post Builds the turtle graphics.
         */
        Turtle();
        /**
         * @brief Replace graphical instructions.
         * @param L-system production by iteration.
         * @param corresp The correspondence between symbols and 
         *     drawing instructions.
         * @param scale Scale of the drawing.
         * @param iniPos The initial position.
         * @param iniAng The initial angle.
         * @pre L-system must deliver production and parser must
         *     deliver the correspondence.
         * @post Generates the instructions to draw.
         */
        string rewrite(const string prod, map<char, string> corresp,
                string scale, vector<string> iniPos, string iniAng) const;
    private:
        /**
         * @brief Starter Logo code.
         */
        string starterLogoCode;
};

#endif

