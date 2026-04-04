#pragma once
#include <string>
using namespace std;
// TCP port; client and server must match (was split: 8888 vs 9050).
static constexpr int PORT = 9050;
extern const string ENCODING;
extern const string ENDLINE;
string formatMessage(const std::string& username, const std::string& message);
