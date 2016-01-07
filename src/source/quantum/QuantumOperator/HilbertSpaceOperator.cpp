#include <assert.h>
#include "include/quantum/HilbertSpaceOperator.h"

////////////////////////////////////////////////////////////////////////////////
//{{{  HilbertSpaceOperator
HilbertSpaceOperator::HilbertSpaceOperator()
{ LOG(INFO) << "Default constructor: HilbertSpaceOperator."; }

HilbertSpaceOperator::~HilbertSpaceOperator()
{ LOG(INFO) << "Default destructor: HilbertSpaceOperator."; }
//}}}
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
//{{{ Hamiltonian
Hamiltonian::Hamiltonian()
{ LOG(INFO) << "Default constructor: Hamiltonian";}

Hamiltonian::Hamiltonian(const vector<cSPIN>& spin_list)
{ LOG(INFO) << "constructor of Hamiltonian with spin_list.";

    _spin_list = spin_list;
    for(auto spin: _spin_list)
        _dim_list.push_back( spin.get_dimension() );
}

Hamiltonian::~Hamiltonian()
{ LOG(INFO) << "Default destructor: Hamiltonian";}

void Hamiltonian::addInteraction(cSpinInteraction& spin_interaction)
{
    assert( this->_dim_list == spin_interaction.getDimList() );
    _interaction_list.push_back(spin_interaction);
}

SumKronProd& Hamiltonian::kronProdForm()
{
    _kron_form = _interaction_list[0].getSumKronProd();
    for(int i=1; i<_interaction_list.size(); ++i)
        _kron_form = _kron_form + _interaction_list[i].getSumKronProd();
    return _kron_form;
}

//}}}
////////////////////////////////////////////////////////////////////////////////
