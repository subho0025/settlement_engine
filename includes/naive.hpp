#pragma once
#include "netting_solver.hpp"

using namespace std;

class GrossSolver : public NettingSolver {
public:
    string name() const override;
    Plan solve(const Instance&) override;
};

class HubSolver : public NettingSolver {
public:
    string name() const override;
    Plan solve(const Instance&) override;
};