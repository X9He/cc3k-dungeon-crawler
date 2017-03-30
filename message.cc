#include "message.h"


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
