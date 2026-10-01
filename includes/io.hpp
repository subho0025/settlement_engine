#pragma once
#include "types.hpp"
#include "instance.hpp"

using namespace std;

Instance read_instance(istream&);

void write_instance(ostream&, const Instance&);