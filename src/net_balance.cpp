#include "../includes/net_balance.hpp"

using namespace std;

vector<Amount> net_balance(const Instance& inst){

    vector<Amount> balance(inst.n,0);

    for(int i=0; i<(int)inst.obs.size(); i++){
        balance[inst.obs[i].from]-= inst.obs[i].amt;
        balance[inst.obs[i].to] += inst.obs[i].amt;
    }

    return balance;
}