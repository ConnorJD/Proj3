/*
 * tester.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: cjdolan
 */

#include "tester.h"
#include "printts.h"
#include <vector>
#include <thread>

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

void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {
	for(int i = 0 ; i < numThreads ; i++) {
		switch(wp) {
		case P1:
			break;
		case P2:
			break;
		case P3:
			break;
		case P4:
			break;
		case P5:
			break;
		}
	}
}

/*
 * if bCanceled== true then causes all running threads to print USER_CHOSE_TO_CANCEL and then exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel) {

}

/*
 * waits for all threads to complete
 */
void joinThreads() {

}
