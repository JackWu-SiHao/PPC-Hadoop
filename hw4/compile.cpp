$ g++ -I YOUR_HADOOP_HOME_DIR/c++/Linux-amd64-64/include -c wordcount.cpp
	(choose Linux-i386-32 if you are using 32-bit Version OS)}
$ g++ wordcount.o -o wordcount -L YOUR_HADOOP_HOME_DIR/c++/Linux-amd64-64
	/lib -lnsl -lpthread -lhadooppipes -lhadooputils
$ bin/hadoop fs -put wordcount DESTINATION_PATH_OF_YOUR_FILE
