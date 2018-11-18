// IntLess.h
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//
// comparator for two integers
//


#ifndef INTLESS_H
#define INTLESS_H

//-----------------------------------------------------------
// IntLess (class)
//
//  comparator class (<)
//
// Private members: no
// Protected members: no
// Public members: yes
// Constructors: no
//-----------------------------------------------------------
class IntLess {
public:
  bool operator()(const int& x, const int& y) const {
    return x < y;
  }
};


#endif // INTLESS_H
