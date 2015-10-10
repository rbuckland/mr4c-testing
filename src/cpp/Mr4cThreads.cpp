#include <thread>
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>


// mr4c include
#include <algo_dev_api.h>
#include <util/util_api.h>

using namespace MR4C;

class Mr4cThreads : public Algorithm {

private:
//    AlgorithmData data;
//    AlgorithmContext context;

     int completed = 0;
public:
 
    Mr4cThreads() {};

    void thread2Runner() {

      while ( ! completed) {
        std::cout << ":: thread2Runner waiting .." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      }

    }

    void executeAlgorithm(AlgorithmData& data, AlgorithmContext& context)
    {

        std::cout << "***************** BEGIN *****************" << std::endl;
        std::thread t1 { thread2Runner }; // starts our thread
        std::this_thread::sleep_for(std::chrono::milliseconds(6000));
        completed = 1;
        t1.join(); // wait for the thread to complete
        std::cout << "***************** END *****************" << std::endl;
    }

    /*
     * MR4C method that's called when algorithm is registered
     * list input and output datasets here
     * static
     */
    static MR4C::Algorithm* create() {
        Mr4cThreads* algo = new Mr4cThreads();
        return algo;
    }
};

//this will create a global variable that registers the algorithm when its library is loaded.
MR4C_REGISTER_ALGORITHM(mr4cThreads,Mr4cThreads::create());
