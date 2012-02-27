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
|   File    : Parser.hpp                                                  |
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

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <set>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

/**
 * @class Parser
 * @brief L-system definition file parser.
 *
 * Follows a symbolic definition similar to the
 * <a href="http://en.wikipedia.org/wiki/L-system">L-system</a> as is
 * defined in the Wikipedia, but it avoids punctuation marks for
 * convenient parsing issues.
 *
 * @author Alexandre Trilla (atrilla)
 */
class Parser {
    public:
        /**
         * @brief Parser constructor.
         * @post Builds the parser.
         */
        Parser();
        /**
         * @brief Parse the L-system definition file.
         * @param file The file.
         * @pre File must be open.
         * @post Parser loaded with definition. Does not close file.
         */
        void parse(ifstream& file);
        /**
         * @brief Alphabet getter.
         * @return The alphabet of the L-system definition.
         * @pre Parser has to be loaded.
         * @post The alphabet is returned.
         */
        set<char> getAlphabet() const;
        /**
         * @brief Axiom getter.
         * @return The axiom of the L-system definition.
         * @pre Parser has to be loaded.
         * @post The axiom is returned.
         */
        string getAxiom() const;
        /**
         * @brief Production rules getter.
         * @return The production rules of the L-system definition.
         * @pre Parser has to be loaded.
         * @post The production rules are returned.
         */
        multimap<char, string> getRules() const;
        /**
         * @brief Number of iterations to run getter.
         * @return The number of iterations to run.
         * @pre Parser has to be loaded.
         * @post The number of iterations to run is returned.
         */
        int getIterations() const;
        /**
         * @brief Turtle graphics getter.
         * @return The symbol-drawing instruction correspondence.
         * @pre Parser has to be loaded.
         * @post The correspondence of symbol-drawing instruction.
         */
        map<char, string> getTurtle() const;
        /**
         * @brief Drawing reduction scale getter.
         * @return The drawing reduction scale.
         * @pre Parser has to be loaded.
         * @post The reduction rate applied to the drawing.
         */
        string getReductionScale() const;
        /**
         * @brief Initial position getter.
         * @return The initial position of the turtle.
         * @pre Parser has to be loaded.
         * @post The initial position of the turtle.
         */
        vector<string> getInitPos() const;
        /**
         * @brief Initial angle getter.
         * @return The initial angle of the turtle.
         * @pre Parser has to be loaded.
         * @post The initial angle of the turtle.
         */
        string getInitAng() const;
    private:
        /**
         * @brief The alphabet.
         */
        set<char> theV;
        /**
         * @brief The axiom.
         */
        string theW;
        /**
         * @brief The production rules.
         */
        multimap<char, string> theP;
        /**
         * @brief Number of running iterations.
         */
        int theNumIters;
        /**
         * @brief Symbol-drawing instruction correspondence.
         */
        map<char, string> theTurtle;
        /**
         * @brief The drawing scale.
         */
        string theScale;
        /**
         * @brief The initial position of the turtle.
         */
        vector<string> theInitPos;
        /**
         * @brief The initial angle of the turtle.
         */
        string theInitAng;
};

#endif

