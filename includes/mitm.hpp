#pragma once
#include <bits/stdc++.h>
#include "types.hpp"
#include "netting_solver.hpp"

using namespace std;

vector<int> mitm_zero_subset(const vector<Amount>&);

vector<vector<int>> refine_groups(const vector<Amount>&, vector<vector<int>>);

class MitmSolver : public NettingSolver {
public:
    string name() const override;
    Plan solve(const Instance&) override;
};