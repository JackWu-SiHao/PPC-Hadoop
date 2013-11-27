#include "algorithm"
#include "limits"
#include "string"

#include  "stdint.h"  // <--- to prevent uint64_t errors!

#include "hadoop/Pipes.hh"
#include "hadoop/TemplateFactory.hh"
#include "hadoop/StringUtils.hh"

using namespace std;
const string groupName[2] = {"GroupA", "GroupB"};

class MyCluster : public HadoopPipes::Mapper {
public:
  // constructor: does nothing
  MyCluster( HadoopPipes::TaskContext& context ) {
  }
  // map function: receives a line, outputs (word,"1")
  // to reducer.
  void map( HadoopPipes::MapContext& context ) {

    //--- get line of text ---
    string line = context.getInputValue();

    //--- split it into words ---
    vector< string > datas =
      HadoopUtils::splitString( line, "," );

    vector<string> data_row0 = HadoopUtils::splitString( datas[0], " " );

    char ch = 'A';
    string ch_str, value;
    string A_str("A");
    //--- emit each word tuple (word, "1" ) ---
    for ( unsigned int i=1; i < data_row0.size(); i++ ) {
      value.clear();
      value.append(data_row0[i]);
      ch_str.assign(1, ch+i-1);
      if ( !(A_str.compare(data_row0[0])) )
      {
        value.append(":A");
      }
      else
        value.append(":B");

      context.emit(ch_str, value);
    }
  }
};

class MyClusterReducer : public HadoopPipes::Reducer {
public:
  // constructor: does nothing
  MyClusterReducer(HadoopPipes::TaskContext& context) {
  }

  // reduce function
  void reduce( HadoopPipes::ReduceContext& context ) {
    int minimum = 100000;
    string group;
    string A_str("A");
    group.assign(groupName[0]);

    while ( context.nextValue() )
    {
      string value = context.getInputValue();
      vector<string> value_split =
        HadoopUtils::splitString(value, ":");
      if(HadoopUtils::toInt(value_split[0]) < minimum) {
        if( !(A_str.compare(value_split[1])) ) //to A's distance
          group.assign(groupName[0]);
        else
          group.assign(groupName[1]);
        minimum = HadoopUtils::toInt(value_split[0]);
      }
    }
    context.emit(context.getInputKey(), group);
  }
};

int main(int argc, char *argv[]) {
  return HadoopPipes::runTask(HadoopPipes::TemplateFactory<
                                                      MyCluster,
                              MyClusterReducer >() );
}
