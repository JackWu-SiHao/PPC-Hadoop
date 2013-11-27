CC = g++
HADOOP_INSTALL = /opt/hadoop
PLATFORM = Linux-amd64-64
CPPFLAGS = -I $(HADOOP_INSTALL)/c++/$(PLATFORM)/include

wordcount: wordcount.cpp
	$(CC) $(CPPFLAGS) $< -L $(HADOOP_INSTALL)/c++/$(PLATFORM)/lib -lnsl -lhadooppipes -lhadooputils -lpthread -g -O2 -o $@
