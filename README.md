# mr4c-testing
Some Simple C++ Test Libraries to show various areas of Mr4c (http://github.com/google/mr4c)

* Mr4cProperties - Showcase the properties found within the Mr4c environment

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

* Mr4cMessaging - Showcase the Messaging Capabilities within the Mr4c Environment

