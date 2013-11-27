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

