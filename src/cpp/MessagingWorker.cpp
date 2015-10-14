#include <thread>
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>


// mr4c include
#include <algo_dev_api.h>
#include <util/util_api.h>

using namespace MR4C;

class MessagingWorker : public Algorithm {

private:
//    AlgorithmData data;
//    AlgorithmContext context;
public:
 
    MessagingWorker() {};

    void executeAlgorithm(AlgorithmData& data, AlgorithmContext& context)
    {

        std::cout << "***************** BEGIN *****************" << std::endl;
        std::cout << "Sending a message" << std::endl;

        Message msg("messagetest","Hellow Master");
        context.sendMessage(msg); 

        std::cout << "***************** END *****************" << std::endl;
    }

    /*
     * MR4C method that's called when algorithm is registered
     * list input and output datasets here
     * static
     */
    static MR4C::Algorithm* create() {
        MessagingWorker* algo = new MessagingWorker();
        return algo;
    }
};

//this will create a global variable that registers the algorithm when its library is loaded.
MR4C_REGISTER_ALGORITHM(messagingWorker,MessagingWorker::create());
