
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>

using namespace std;

class MLs
{
private:
  struct MLSArg {
    string origArgStr;
  };

private:
  vector<MLSArg> arguments;

private:
  void _readArguments(int argCount, char **argValues) {
  }

public:
  MLs(int argCount, char **argValues) {
    _readArguments(argCount, argValues);
  }

public:
  int execute() const {
    int execResult  {0};
    return execResult;
  }
};

int main(int argCount, char *argValues[])
{
  MLs mLs {argCount, argValues};
  return mLs.execute();
}

