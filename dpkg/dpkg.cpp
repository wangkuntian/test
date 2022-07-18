//
// Created by king on 2022/7/17.
//


#include <iostream>
#include <cstring>
#include "sys/stat.h"
#include "unistd.h"

using namespace std;

int main(int argc, char **argv) {
    string command = "dpkg -L ";

    if (argc == 2) {
        command += argv[1];
    } else if (argc > 2) {
        cout << "To many packages. " << endl;
        return -1;
    } else {
        cout << "Expect one package" << endl;
        return -1;
    }

    FILE *fstream = nullptr;
    char buffer[1024];
    struct stat file_stat{};
    if (nullptr == (fstream = popen(command.c_str(), "r"))) {
        return -1;
    }

    while (nullptr != fgets(buffer, sizeof(buffer), fstream)) {
        buffer[strlen(buffer) - 1] = 0;
        if (access(buffer, F_OK) == 0) {
            if (strncmp(buffer, "/usr/", 5) == 0) {
                stat(buffer, &file_stat);
                if (file_stat.st_uid == 0) {
                    continue;
                }
            } else {
                continue;
            }
        }
        printf("%s\n", buffer);
    }
    return 0;
}