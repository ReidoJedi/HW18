#include <iostream>
#include <fstream>
#include <string>
#include <io.h>

using namespace std;

class User {
    string _name;
    string _login;
    string _pass;

public:
    void readFromFile(string filename) {
        ifstream infile(filename);
        infile >> _name >> _login >> _pass;
        infile.close();
    }

    void writeToFile(string filename) {
        ofstream outfile(filename);
        outfile << _name << " " << _login << " " << _pass;
        outfile.close();
    }
};

class Message {
    string _text;
    string _sender;
    string _receiver;

public:
    void readFromFile(string filename) {
        ifstream infile(filename);
        infile >> _text >> _sender >> _receiver;
        infile.close();
    }

    void writeToFile(string filename) {
        ofstream outfile(filename);
        outfile << _text << " " << _sender << " " << _receiver;
        outfile.close();
    }
};

int main() {
    User user;
    user.readFromFile("user.txt");
    // ...
    user.writeToFile("user.txt");
    _chmod("user.txt", _S_IREAD | _S_IWRITE);

    Message message;
    message.readFromFile("message.txt");
    // ...
    message.writeToFile("message.txt");
    _chmod("message.txt", _S_IREAD | _S_IWRITE);

    return 0;
}
