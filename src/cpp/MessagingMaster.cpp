#include <thread>
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>


// mr4c include
#include <algo_dev_api.h>
#include <util/util_api.h>

using namespace MR4C;

class MessagingMaster : public Algorithm { // { , public MessageConsumer {

private:
//    AlgorithmData data;
//    AlgorithmContext context;

     int expectedWorkers = 0;
public:
 
    MessagingMaster() {};

    std::string getParameters( std::string workerId) {
       return "{\"parameters\":[1,2,3,4,5] }";
    }

    void executeAlgorithm(AlgorithmData& data, AlgorithmContext& context)
    {

        std::cout << "***************** BEGIN *****************" << std::endl;
        expectedWorkers = data.getConfig().getConfigParamAsInt( "trialInputCount" );
        std::cout << "workers to connect is " << expectedWorkers << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(30000));
        std::cout << "***************** END *****************" << std::endl;
    }

    void receiveMessage(const Message& msg) {

        std::cout << "recv'd message : " << msg << std::endl;

    }

    /*
     * MR4C method that's called when algorithm is registered
     * list input and output datasets here
     * static
     */
    static MR4C::Algorithm* create() {
        MessagingMaster* algo = new MessagingMaster();
        return algo;
    }
};

//this will create a global variable that registers the algorithm when its library is loaded.
MR4C_REGISTER_ALGORITHM(messagingMaster,MessagingMaster::create());
