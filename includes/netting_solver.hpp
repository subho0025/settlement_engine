#pragma once
#include <bits/stdc++.h>
#include "types.hpp"
#include "instance.hpp"

using namespace std;

class NettingSolver {
public:
    virtual ~NettingSolver() = default;
    virtual string name() const = 0;
    virtual Plan solve(const Instance&) = 0;
};