
// mr4c include
#include <algo_dev_api.h>

using namespace MR4C;

class Mr4cMessaging : public Algorithm, public MessageConsumer {

private:
    AlgorithmData& data;
    AlgorithmContext& context;

public:
    void executeAlgorithm(AlgorithmData& data, AlgorithmContext& context)
    {


        this.data = data;
        this.context = context;

        context.registerMessageConsumer(this);

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
     * what do we do when we receive a message
     */
    void receiveMessage(const Message& msg) {

    }

    /*
     * MR4C method that's called when algorithm is registered
     * list input and output datasets here
     * static
     */
    MR4C::Algorithm* create() {
        Mr4cMessaging * algo = new Mr4cMessaging();
        return algo;
    }
};

//this will create a global variable that registers the algorithm when its library is loaded.
MR4C_REGISTER_ALGORITHM(messageHandler,MyMessageHandling::create());
