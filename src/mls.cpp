
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

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
    if (argCount && argValues == nullptr) return;
    for (int i = 0; i < argCount; ++i) {
      arguments.push_back({argValues[i]});
    }
  }

public:
  MLs(int argCount, char **argValues) {
    _readArguments(argCount, argValues);
  }

public:
  int run() const;
};

int main(int argCount, char *argValues[])
{
  MLs mLs {argCount, argValues};
  return mLs.run();
}


int MLs::run() const {
  int execResult {0};
  return execResult;
}
