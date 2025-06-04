
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

const char MLsVersion[] = "0.1";

const char MLsBuildDate[] = __DATE__;
const char MLsbuildTime[] = __TIME__;

using namespace std;

enum MLsMsgID {
  M_I_SUCCEEDED,
  M_END
};

struct MLsMsg {
  MLsMsgID id;
  char desc[256];
};

const MLsMsg MLsMsgs[MLsMsgID::M_END] {
  {MLsMsgID::M_I_SUCCEEDED, "Ok"}
};

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

int main(int argCount, char **argValues)
{
  MLs mLs {argCount, argValues};
  return mLs.run();
}

int MLs::run() const {
  using namespace std;
  namespace fs = filesystem;
  
  int execResult {MLsMsgID::M_I_SUCCEEDED};

  for(auto& dirItem: fs::directory_iterator("."))
    cout << dirItem.path() << '\n';

  return execResult;
}
