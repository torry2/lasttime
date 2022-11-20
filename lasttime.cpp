#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <sstream>
#include <cstdlib> 
#include <cstring>
#include <stdlib.h>

using namespace std;

int argi;
int foot;
char **args;
string home;
string dotfile;
vector<string> history;


int help() {
	char read[] = "INFO: lt <command> (<index>)";
	cout << read << endl;
	return 0;
}

int env() {
	char* shell;
	shell = getenv ("SHELL");
	home = getenv("HOME");

	if ( strcmp(shell, "/bin/bash") == 0 ) {
		dotfile = ".bash_history";
	} else if ( strcmp(shell, "/bin/zsh") == 0 ) {
		dotfile = ".zsh_history";
	} else {
		cout << "ERROR: Unsupported Shell!" << endl;
		return 0;
	}
	
	return 0;
}

int read() {
	env();	
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

int last() {
	read();
	
	if (argi == 3 && (!isdigit(args[2][0]))) {
		cout << "ERROR: Index Not Integer!" << endl;
		return 0;
	} else if (argi == 3) {
		stringstream args2;
		args2 << args[2];
		foot = stoi(args2.str());
		
	} else foot = 1;
	
	int c = 0;
	
	for(int i = 0; i<history.size(); i++) {
		if (history[i].rfind(args[1], 0) != string::npos) {
			cout << history[i] << endl;
	
			c += 1;
			
		} else if (foot >= 1 && c == foot) {
			return 0;	
			
		}
	}
	if ( c == 0 ) {
		cout << "INFO: Command Not in History!" << endl;
	}
	return 0;
} 
	
int main( int argc, char* argv[] ) {
	if ( argc >= 2 && argc < 4) {
		::argi = argc;
		::args = argv;
		last();
	} else if ( argc >= 4 ) {
		cout << "ERROR: Too Many Arguments!" << endl;
		help();
	} else {
		help();
	}
	
	return 0;
}
