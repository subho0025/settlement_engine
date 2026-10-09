#pragma once
#include <bits/stdc++.h>
#include "types.hpp"
#include "instance.hpp"

using namespace std;

class GridlockSolver {
public:
    virtual ~GridlockSolver() = default;
    virtual string name() const = 0;
    virtual vector<int> solve(const Instance&) = 0;
};