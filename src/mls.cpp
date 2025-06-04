
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

const char MLsVersion[] = "0.1";

const char MLsBuildDate[] = __DATE__;
const char MLsbuildTime[] = __TIME__;

using namespace std;

enum MLsMsgID {
  M_R_SUCCEEDED,
  M_R_E_ERROR,
  M_I_VERSION,
  M_I_CREATED,
  M_END
};

struct MLsMsg {
  MLsMsgID id;
  char desc[256];
};

const MLsMsg MLsMsgs[MLsMsgID::M_END] {
  {M_R_SUCCEEDED,      "Ok"},
  {M_R_E_ERROR,        "E : {}"},
  {M_I_VERSION,        "Version : {}"},
  {M_I_CREATED,        "Created : {}"}
};

class MLs
{
private:
  struct MLsArg {
    string argStr;
    int argFlags;
  };

private:
  struct MLsPrintItem {
    int prtFlags;
  };

private:
  vector<MLsArg> arguments;

private:
  int determineFlags(const char* paramValue) {
    if (paramValue == nullptr)
      return 0;
    return 0;
  }
  
private:
  void _readArguments(int argCount, char **argValues) {
    if (argCount && argValues == nullptr) return;
    for (int i = 0; i < argCount; ++i) {
      arguments.push_back({argValues[i], determineFlags(argValues[i])});
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
  
  int execResult {MLsMsgID::M_R_SUCCEEDED};

  for(auto& dirItem: fs::directory_iterator("."))
    cout << dirItem.path() << '\n';

  return execResult;
}
