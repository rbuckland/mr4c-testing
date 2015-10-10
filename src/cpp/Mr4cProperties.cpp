#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

// mr4c include
#include <algo_dev_api.h>
#include <util/util_api.h>

using namespace MR4C;

class Mr4cProperties : public Algorithm {

private:
//    AlgorithmData data;
//    AlgorithmContext context;

public:
 
    Mr4cProperties() {};

    void executeAlgorithm(AlgorithmData& data, AlgorithmContext& context)
    {

//        this.data = data;
 //     this.context = context;

        dumpProperties(MR4CEnvironment::RUNTIME,"RUNTIME");
        dumpProperties(MR4CEnvironment::JAVA,"JAVA");
        dumpProperties(MR4CEnvironment::CUSTOM,"CUSTOM");
        dumpProperties(MR4CEnvironment::RAW,"RAW");
    }

    void dumpProperties(MR4CEnvironment::EnvSet envType, std::string envname) {

        std::map<std::string,std::string> properties = MR4CEnvironment::instance().getProperties(envType).getPropertyMap();

        std::cout << "***************** OUT " << envname << "*****************" << std::endl;
        for(std::map<std::string,std::string>::iterator iter = properties.begin(); iter != properties.end(); ++iter)
        {
          std::string k =  iter->first;
          std::string v = iter->second;
          std::cout << k << "=" << v << std::endl;
        }
        std::cout << "***************** END " << envname << " *****************" << std::endl;

    }

    /*
     * MR4C method that's called when algorithm is registered
     * list input and output datasets here
     * static
     */
    static MR4C::Algorithm* create() {
        Mr4cProperties* algo = new Mr4cProperties();
        return algo;
    }
};

//this will create a global variable that registers the algorithm when its library is loaded.
MR4C_REGISTER_ALGORITHM(mr4cProperties,Mr4cProperties::create());
