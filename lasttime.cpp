#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <cstring>
#include <stdlib.h>

using namespace std;

int argi;
char **args;
string dotfile;
vector<string> history;

int help() {
	char read[] = "INFO: Enter a command as an argument! \n   e.g \"lasttime ping\" \n(more information on the github repo @torry2) \n";
	cout << read;
	return 0;
}

int getenviroment() {
	char* shell;
	shell = getenv ("SHELL");

	if ( strcmp(shell, "/bin/bash") == 0 ) {
		dotfile = ".bash_history";
	} else if ( strcmp(shell, "/bin/zsh") == 0 ) {
		dotfile = ".zsh_history";
	} else {
		cout << "ERROR: Unsupported Shell!" << endl;
	}
	
	return 0;
}

int readhistory() {
	getenviroment();
	string home = getenv("HOME");
	string command;
	ifstream historyfile (home + "/" + dotfile);
	if (historyfile.is_open()) {
		while ( getline (historyfile,command) )
		{
			history.push_back(command);
		}
		historyfile.close();
	}
	else cout << "ERROR: Could Not Open History File!" << endl;
	
	return 0;
}

int lasttime() {
	readhistory();

	if (argi == 2) {
		int c = 0;
		for(int i = 0; i<history.size(); i++) {
			if (history[i].rfind(args[1], 0) != string::npos) {
				cout << history[i] << endl;
				c += 1;
			}
		}
		if ( c == 0 ) {
			cout << "INFO: Command Not in History!" << endl;
		}
	} 
	
	return 0;
}

int main( int argc, char* argv[] ) {
	if ( argc >= 2 && argc < 3) {
		::argi = argc;
		::args = argv;
		lasttime();
	} else if ( argc >= 3 ) {
		cout << "ERROR: Too Many Arguments!" << endl;
		help();
	} else {
		help();
	}
}
