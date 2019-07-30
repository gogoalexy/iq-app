#ifndef IQ_INTERFACE_H

#include <cstdio>
#include "iq_neuron.h"
#include "synapse.h"

class IQsim
{
public:
    IQsim(int num);
    ~IQsim();
    int howManyNeurons();
    void initAllNeuronParam(int rest, int threshold, int reset, int a, int b, int noise);
    void setNeuronParam(int id, int rest, int threshold, int reset, int a, int b, int noise);
    //iq_neuron listNeuronParam(int id);
    void injectI(int id, int current);
    void run(unsigned int steps);

private:
    const int num_neurons;
    FILE *fp[num_neurons];
    iq_neuron *neurons;
    int *weights;
    int *currents;
};

#define IQ_INTERFACE_H
#endif
