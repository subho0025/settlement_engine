#include "../includes/validator.hpp"
#include "../includes/net_balance.hpp"

static const Amount MAX_TRANSFER_AMT = 1000000000000000000LL;
ValidationResult validate_netting(const Instance& inst, const Plan& plan){

    ValidationResult res;

    res.transfers = plan.transfers.size();

    auto fail = [&](const string& msg){
    res.ok = false;
    res.error = msg;
    return res;
    };


    vector<__int128> effect(inst.n, 0);

    for(const Transfer& transfer: plan.transfers){

        if(transfer.to<0 || transfer.to>=inst.n) return fail("'to' out of range [0, n)");

        if(transfer.from<0 || transfer.from>=inst.n) return fail("'from' out of range [0, n)");

        if(transfer.from == transfer.to) return fail("'from' and 'to' must differ");

        if(transfer.amt<1 || transfer.amt >MAX_TRANSFER_AMT) return fail("amt out of range [1, 1e18]");

        Amount next;
        if(__builtin_add_overflow(res.total_moved, transfer.amt, &next))  return fail("total moved overflows int64");

        res.total_moved = next;
        effect[transfer.to]   += transfer.amt;
        effect[transfer.from] -= transfer.amt;
    }

    vector<Amount> bal = net_balance(inst);
    for(int i = 0; i < inst.n; i++){
        if(effect[i] != (__int128)bal[i]){
            return fail("party " + to_string(i) + ": plan effect differs from expected net balance "+ to_string(bal[i]));
        }
    }


    res.ok=1;

    return res;
    
}