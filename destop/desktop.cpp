//
// Created by king on 2022/7/6.
//
#include <iostream>
#include <unistd.h>
#include "SimpleIni.h"

using namespace std;

int main(int argc, char *argv[]) {
    int opt;
    char const *args = "d:nie:";
    string run_arg;
    string file_path;
    bool get_name, get_icon, run = false;
    while ((opt = getopt(argc, argv, args)) != -1) {
        switch (opt) {
            case 'd':
                file_path = optarg;
                break;
            case 'n':
                get_name = true;
                break;
            case 'i':
                get_icon = true;
                break;
            case 'e':
                run = true;
                if (optarg != nullptr) {
                    run_arg = optarg;
                }
                break;
        }
    }

//    string validate = "desktop-file-validate " + file_path;
//
//    if (system(validate.c_str()) != 0) {
//        cout << "validate desktop file failed!" << endl;
//        return -1;
//    }

    CSimpleIniA ini;
    ini.SetUnicode();
    SI_Error rc = ini.LoadFile(file_path.c_str());
    if (rc < 0) {
        cout << "error" << endl;
    }

    if (get_name) {
        string value = ini.GetValue("Desktop Entry", "Name");
        cout << value << endl;
    }
    if (get_icon) {
        string icon = ini.GetValue("Desktop Entry", "Icon");
        cout << icon << endl;
    }

    if (run) {
        string command = ini.GetValue("Desktop Entry", "Exec");
        command = command + " " + run_arg;
        system(command.c_str());
    }

    return 0;
}
