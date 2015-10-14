# mr4c-testing
Some Simple C++ Test Libraries to show various areas of Mr4c (http://github.com/google/mr4c)

### Mr4cProperties 

Showcase the properties found within the Mr4c environment

Simple app which dumps out the properties of the job executing

This is a sample from the output 


    ***************** OUT RUNTIME*****************
    ***************** END RUNTIME *****************
    ***************** OUT JAVA*****************
    awt.toolkit=sun.awt.X11.XToolkit
    file.encoding=UTF-8
    file.encoding.pkg=sun.io
    file.separator=/
    hadoop.metrics.log.level=WARN
    ...
    sun.font.fontmanager=sun.awt.X11FontManager
    sun.io.unicode.encoding=UnicodeLittle
    sun.java.command=org.apache.hadoop.mapred.YarnChild 10.0.0.159 51679 attempt_1443017128003_0091_m_000000_0 2
    sun.java.launcher=SUN_STANDARD
    sun.jnu.encoding=UTF-8
    sun.management.compiler=HotSpot 64-Bit Tiered Compilers
    sun.os.patch.level=unknown
    user.country=US
    user.dir=/opt/data/yarn/nm/usercache/ec2-user/appcache/application_1443017128003_0091/container_1443017128003_0091_01_000002
    user.home=/var/lib/hadoop-yarn
    user.language=en
    user.name=yarn
    user.timezone=US/Eastern
    yarn.app.container.log.dir=/var/log/hadoop-yarn/container/application_1443017128003_0091/container_1443017128003_0091_01_000002
    yarn.app.container.log.filesize=0
    ***************** END JAVA *****************
    ***************** OUT CUSTOM*****************
    jobid=job_1443017128003_0091
    taskid=attempt_1443017128003_0091_m_000000_0
    ***************** END CUSTOM *****************
    ***************** OUT RAW*****************
    ***************** END RAW *****************

Ths most interesting property there is the jobid and taskid :-) So from this we can know "which one" we are in a long running / multi task job.

#### Running


    runProperties.sh # shows dumping the running properties


### Messaging 

Showcase the Messaging Capabilities within the Mr4c Environment

  This has shown a push only model of messaging (push out from the algorithm)

  This is a simple test to show / workout how the messaging worked. Essentially at the moment - mr4c only uses PUSH http messages OUT from the algorithm. It cannot receive any.


    ***************** BEGIN *****************
    Sending a message
    2015-10-14 06:19:55,253 INFO  mr4c.java.message.Messages: Adding message handler for topic = [messagetest] and URI = [http://httpbin.org/post]
    2015-10-14 06:19:55,260 INFO  mr4c.java.message.HttpMessageHandler: POSTing message to [http://httpbin.org/post]: [topic=[messagetest]; content=[Hellow Master]; contentType=[text/plain]]
    2015-10-14 06:19:55,437 INFO  mr4c.java.message.HttpMessageHandler: Status line: HTTP/1.1 200 OK
    2015-10-14 06:19:55,437 INFO  mr4c.java.message.HttpMessageHandler: Content: {
      "args": {},
      "data": "Hellow Master",
      "files": {},
      "form": {},
      "headers": {
        "Content-Length": "13",
        "Content-Type": "text/plain",
        "Host": "httpbin.org",
        "User-Agent": "Apache-HttpClient/4.2.5 (java 1.5)"
      },
      "json": null,
      "origin": "x.x.x.x",
      "url": "http://httpbin.org/post"
    }
    
    ***************** END *****************

  The only protocol supported is http. See ``runMessagingWorker.sh`` for the PUSH. 

  Master does not do anything really because, INCOMING subscriber messaging is not included / implemented / designed.

#### Running


    # check the site.json file
    cmake .
    make
    ./runMessagingWorker.sh # sends a message to an external http:// pub/sub gateway. Note the configuration setup

    # this does not work .. as there is no incoming messaging
    ./runMessagingMaster.sh # shows waiting for a message (it never arrives - :-)


### mr4cThreads 

shows / test spinning up a secondary thread (thought might be useful for messaging :0)

#### Running


    # check the site.json file
    cmake .
    make 
    ./runThreads.sh

### openMp - see if the OpenMP library will work

A real simple example of compiling code using openmp to enforce parallelism in the shared lib.
This pre writtem OpenMP example comes from https://people.sc.fsu.edu/~jburkardt/cpp_src/dijkstra_openmp/dijkstra_openmp.html


    ***************** BEGIN *****************
    14 October 2015 07:14:56 AM
    
    DIJKSTRA_OPENMP
      C++ version
      Use Dijkstra's algorithm to determine the minimum
      distance from node 0 to each node in a graph,
      given the distances between each pair of nodes.
    
      Although a very small example is considered, we
      demonstrate the use of OpenMP directives for
      parallel execution.
    
      Distance matrix:
    
        0   40   15  Inf  Inf  Inf
       40    0   20   10   25    6
       15   20    0  100  Inf  Inf
      Inf   10  100    0  Inf  Inf
      Inf   25  Inf  Inf    0    8
      Inf    6  Inf  Inf    8    0
    
      P2: Parallel region begins with 4 threads.
    
      P2:  First=  P3  P0  Last=:  First=1:  First=0  Last=10  Last=
    2
    3
      P3:  First=4  Last=5
      P2: Connecting node 2
      P2: Connecting node 1
      P2: Connecting node 5
      P0: Connecting node 3
      P3: Connecting node 4
    
      P1: Exiting parallel region.
    
      Minimum distances from node 0:
    
       0   0
       1  35
       2  15
       3  45
       4  49
       5  41
    
    DIJKSTRA_OPENMP
      Normal end of execution.
    
    14 October 2015 07:14:56 AM
    ***************** END *****************


#### Running
    

    # check the site.json file
    cmake .
    make 
    ./runOpenMP.sh




