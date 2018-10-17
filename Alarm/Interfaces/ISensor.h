//External sensor interface definition.
#ifndef ISensor_h
#define ISensor_h

using namespace std;

template <class T> class ISensor{
public:
    virtual void Initialise() = 0;
    virtual T ReadSensor() = 0;
};
    
#endif 
