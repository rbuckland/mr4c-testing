
// mr4c include
#include <algo_dev_api.h>

using namespace MR4C;

class Mr4cProperties : public Algorithm {

private:
    AlgorithmData& data;
    AlgorithmContext& context;

public:
    void executeAlgorithm(AlgorithmData& data, AlgorithmContext& context)
    {

        this.data = data;
        this.context = context;

        std::map<std::string,std::string> properties =
          MR4CEnvironment.instance().getProperties(MR4CEnvironment.EnvSet.RAW).getProperties();

        for(std::map<std::string,std::string>::iterator iter = properties.begin(); iter != properties.end(); ++iter)
        {
          std::string k =  iter->first;
          std::string v = iter->second;

          cout << k << " -> " << v << std:endl;
        }
    }

    /*
     * MR4C method that's called when algorithm is registered
     * list input and output datasets here
     * static
     */
    MR4C::Algorithm* create() {
        Mr4cProperties * algo = new Mr4cProperties();
        return algo;
    }
};

//this will create a global variable that registers the algorithm when its library is loaded.
MR4C_REGISTER_ALGORITHM(mr4cProperties,Mr4cProperties::create());
