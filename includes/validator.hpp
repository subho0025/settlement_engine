#pragma once
#include <bits/stdc++.h>
#include "types.hpp"
#include "instance.hpp"

using namespace std;

struct ValidationResult {
    bool ok = false;
    string error;
    size_t transfers = 0;
    Amount total_moved = 0;
};

ValidationResult validate_netting(const Instance&, const Plan&);