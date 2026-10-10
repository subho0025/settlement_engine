#pragma once
#include <bits/stdc++.h>
#include "types.hpp"
#include "instance.hpp"
#include "gridlock.hpp"

using namespace std;

class FifoBypassSolver: public GridlockSolver{
public:
    string name() const override;
    vector<int> solve(const Instance&) override;
};