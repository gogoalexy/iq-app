#include "iq-interface.h"

using namespace std;

IQsim::IQsim(int num) : num_neurons(num)
{
    neurons = new iq_neuron[num_neurons];
    weight = new int[num_neurons * num_neurons]();
    current = new int[num_neurons]();
    // empty parentheses imply initializing to zeros
    char[] filename = "output_Number.txt";
    for(int i = 0; i < num_neurons; ++i)
    {
        sprintf(filename, "output_%d.txt", i);
        fp[i] = fopen(filename, "w");
    }
}

IQsim::~IQsim()
{
    delete[] neurons;
    delete[] weights;
    delete[] currents;
    for(int i = 0; i < num_neurons; ++i)
    {
        fclose(fp[i]);
    }
}

int IQsim::howManyNeurons()
{
    return num_neurons;
}

void IQsim::initAllNeuronParam(int rest, int threshold, int reset, int a, int b, int noise)
{
    for(int i = 0; i < num_neurons; ++i)
    {
        if(!(neurons + i)->is_set())
        {
            (neurons + i)->set(rest, threshold, reset, a, b, noise);
        }
    }
    FILE *infd;
    get_weight(infd, num_neurons, weights)
}

void IQsim::setNeuronParam(int id, int rest, int threshold, int reset, int a, int b, int noise)
{
    (neurons + id)->set(rest, threshold, reset, a, b, noise);
}

void IQsim::injectI(int id, int current)
{
    *(currents + id) = current;
}

void IQsim::run(unsigned int steps)
{
    for(int i = 0; i < steps; ++i)
    {
        send_synapse(num_neurons, neurons, weight, 5, current);
        for(int j = 0; j < num_neurons; ++j)
        {
            fprintf(fp[j], "%d\n", (neurons + j)->potential());
        }
    }
}
