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
|   File    : Lsystem.hpp                                                 |
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

#ifndef LSYSTEM_HPP
#define LSYSTEM_HPP

#include <string>
#include <set>
#include <map>

using namespace std;

/**
 * @class Lsystem
 * @brief Structure of the L-system, which consists of an alphabet of 
 * symbols, a collection of production rules and an initial axiom from
 * which to begin the construction.
 *
 * The constants are implicitly defined by those symbols in the alphabet
 * that are not expanded by any production rule.
 *
 * In case more than one production rule is available for a given symbol,
 * i.e., a stochastic grammar, a choice is taken according to an uniform
 * probability distribution among the possible rules.
 *
 * @author Alexandre Trilla (atrilla)
 */
class Lsystem {
    public:
        /**
         * @brief Plain L-system constructor.
         * @post Initialises an undefined L-system (null parameters). This
         *     is useless. Use the parametric constructor instead.
         */
        Lsystem();
        /**
         * @brief Parametric L-system constructor.
         * @param vars The variables.
         * @param start The initial axiom.
         * @param rules The production rules.
         * @pre The L-system definition must be consistent.
         * @post Initialises the defined L-system.
         */
        Lsystem(const set<char> &vars, const string start,
                const multimap<char, string> &rules);
        /**
         * @brief Generate a production by iterating the system on the
         *     initial axiom.
         * A stochastic L-system is allowed.
         * @param numIter The number of iterations to run.
         * @return Sequence of symbols by the end of the iteration.
         * @pre The parametric L-system must be defined.
         * @post Produces a sequence of symbols by iteration.
         */
        string produce(const int numIter) const;
    private:
        /**
         * @brief The set of variables.
         */
        set<char> theVariables;
        /**
         * @brief The initial axiom.
         */
        string theStart;
        /**
         * @brief The set of production rules.
         */
        multimap<char, string> theRules;
};

#endif

