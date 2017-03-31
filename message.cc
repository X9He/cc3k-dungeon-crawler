#include "message.h"
using namespace std;


Message::Message(): action{""} {}

Message::~Message() {}

void Message::clearMessage() {
  action = "";
}

void Message::addMessage(string act) {
  action += act;
}

void Message::getMessage() {
  cout << action << endl;
}
