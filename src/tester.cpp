/*
 * tester.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: cjdolan
 */

#include "tester.h"
#include <vector>
#include <thread>
#include <iostream>
#include "print_ts.h"

using namespace std;

/*
 * starts cancelable threads
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 */

vector<thread> threads;
bool Cancel = false;

void doThread(std::string s, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {
	int numTimesPrinted = 0;
	while(numTimesPrinted < numTimesToPrint && !Cancel) {
		switch(wp) {
		case P1: PRINT1(s);
			break;
		case P2: PRINT2(s, s);
			break;
		case P3: PRINT3(s, s, s);
			break;
		case P4: PRINT4(s, s, s, s);
			break;
		case P5: PRINT5(s, s, s, s, s);
			break;
		}
		numTimesPrinted++;
		this_thread::sleep_for(chrono::milliseconds(millisecond_delay));
	}
	if(Cancel) {
		cout << USER_CHOSE_TO_CANCEL << endl;
	}
}

void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {
	for(int i = 0 ; i < numThreads ; i++) {
		threads.push_back(thread(doThread, s, wp, numTimesToPrint, millisecond_delay));
	}
}

/*
 * if bCanceled== true then causes all running threads to print USER_CHOSE_TO_CANCEL and then exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel) {
	Cancel = true;
}

/*
 * waits for all threads to complete
 */
void joinThreads() {
	for(auto& t : threads){
		t.join();
	}
}

int main() {
	startThreads("Hello", 2, P5, 10000, 10);
	setCancelThreads(Cancel);
	joinThreads();
}
