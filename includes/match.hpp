#pragma once
#include <bits/stdc++.h>
#include "types.hpp"
#include "netting_solver.hpp"

using namespace std;

vector<vector<int>> match_groups(const vector<Amount>& b);

class MatchSolver : public NettingSolver{
public:
    string name() const override;
    Plan solve(const Instance&) override;
};