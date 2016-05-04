#include "include/app/cce.h"

////////////////////////////////////////////////////////////////////////////////
//{{{  EnsembleCCE
class EnsembleCCE:public CCE
{
public:
    EnsembleCCE(int my_rank, int worker_num, const ConfigXML& cfg):CCE(my_rank, worker_num, cfg) { set_parameters(); }

    void set_parameters();
    vec cluster_evolution(int cce_order, int index);
protected:

private:
    Hamiltonian create_spin_hamiltonian(const cSPIN& espin, const PureState& center_spin_stat, const vector<cSPIN>& spin_list);
    LiouvilleSpaceOperator create_incoherent_operator(const vector<cSPIN>& spin_list);
    Liouvillian create_spin_liouvillian(const Hamiltonian& hami0, const Hamiltonian hami1);
    DensityOperator create_spin_density_state(const vector<cSPIN>& spin_list);

    vec _bath_polarization;
    vec calc_observables(QuantumEvolutionAlgorithm* ker);
};
//}}}
////////////////////////////////////////////////////////////////////////////////
