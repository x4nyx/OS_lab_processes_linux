#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

void killProcessById(int id) {
    system(("kill" + std::to_string(id)).c_str());
}

void killProcessByName(const char *string) {
    system(("killall " + std::string(string)).c_str());
}

int main(int argc, char *argv[]) {

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--name") == 0) {
            killProcessByName(argv[i + 1]);
        } else if (strcmp(argv[i], "--id") == 0) {
            killProcessById(std::stoi(argv[i + 1]));
        }
    }

    char buff[100];
    if (getenv("PROC_TO_KILL") == nullptr)
        return 0;

    strcpy(buff, getenv("PROC_TO_KILL"));
    std::stringstream ss(buff);
    while (ss.getline(buff, sizeof(buff), ',')) {
        killProcessByName(buff);
    }
    return 0;
}