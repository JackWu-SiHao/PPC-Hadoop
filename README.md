Hadoop
======

Hadoop for PPC course


### How to run Example Code(WordCount)

	// compile
    cd  ~/java/20HadoopWordCount/
    ant jar

    //input file Format: hadoop fs -put <source from local> <destination to hdfs>
	hadoop fs -put input input

	//run
    hadoop jar ~/java/20HadoopWordCount/build/jar/WordCount-1.0.jar input/input.txt output

### Run locally on Single Node using Pipes

- Install Hadoo

1. http://trac.nchc.org.tw/cloud/wiki/Hadoop_Lab1
2. http://blog.changyy.org/2009/10/linux-hadoop-0201-single-node-cluster.html

- compile


    	g++ -I /opt/hadoop/c++/Linux-amd64-64/include -c wordcount.cpp
    	g++ wordcount.o -o wordcount -L /opt/hadoop/c++/Linux-amd64-64/lib -lnsl -lpthread -lhadooppipes -lhadooputils
    	cp wordcount.xml /opt/hadoop
    	bin/hadoop fs -put wordcount examples/bin

- run


    	bin/hadoop pipes -conf wordcount.xml -input examples/input -output examples/output
    	

### Run locally on Single Node using Streaming
	
	
	hadoop jar /opt/hadoop/contrib/streaming/hadoop-0.20.2-streaming.jar -input shakespeare_poem.txt -output output -mapper mapper -reducer reducer -file ./mapper -file ./reducer
	


