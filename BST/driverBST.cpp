#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <sstream>
#include <istream>

#include "BST.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) { return 0; }

    ifstream inFile;
    inFile.open(argv[1]);

    if (inFile.fail()) {  //ensure file opens before starting

        cout << "Failed to open input file" << endl;

    } else {

        string line, newV;
        istringstream line_stream;
        int testData[40000];
        int newPoint, index = 0;

        getline(inFile, line);
        line_stream.str(line);

        while (getline(line_stream, newV, ',')) { //fill testData array with stringstream
            testData[index] = stoi(newV);
            index++;
        }
        
        float insert[400];
        float search[400];
        int searchIndecies[100];
        int inputTime, searchTime, max, min;
        double avgInsertTime, avgSearchTime;

        BST myTree;
        
        for (int i = 0; i < 400; i++) {
            using namespace chrono;

            max = ((i+1)*100) - 1;      //set new ranges for indecies after every set
            min = i * 100;

            high_resolution_clock::time_point start = high_resolution_clock::now(); //start clock for insert

            for (int k = min; k <= max; k++) {    //insert 100 values at a time 
                myTree.addNode(testData[k]);
            }

            high_resolution_clock::time_point end = high_resolution_clock::now(); //end clock

            duration<double> execTime = duration_cast<nanoseconds>(end-start); //total time for inserting 100
            avgInsertTime = (execTime.count() / 100);               //take avg time

            insert[i] = avgInsertTime;
            
            for (int j = 0; j < 100; j++) {                     //generate random indecies from 0 to max range
                searchIndecies[j] = rand()%max;
            }
            
             high_resolution_clock::time_point start2 = high_resolution_clock::now(); //start clock for search

            for (int l = 0; l < 100; l++) {
                myTree.findNode(testData[searchIndecies[l]]);
            }

            high_resolution_clock::time_point end2 = high_resolution_clock::now(); //end clock

            duration<double> execTime2 = duration_cast<nanoseconds>(end2-start2); //total time for inserting 100
            avgSearchTime = (execTime2.count() / 100);           //take avg time

            search[i] = avgSearchTime;
        }
        cout << myTree.findNode(52746);
        ofstream outFile;
        outFile.open(argv[2]);
        outFile << "Insert Times,Search Times" << endl;
        for (int i = 0; i < 400; i++) {
            outFile << insert[i] << "," << search[i] << endl;
        }
        /*
        cout << "Avg insert time, first iteration: " << insert[0] << endl;
        cout << "Avg insert time, last iteration: " << insert[399] << endl;
        cout << "Avg search time, first iteration: " << search[0] << endl;
        cout << "Avg search time, last iteration: " << search[399] << endl;
        */

        return 0;
    }
}