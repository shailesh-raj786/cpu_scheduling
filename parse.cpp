// #ifndef PARSING
// #define PARSING

#include <bits/stdc++.h>

using namespace std;

/** This file handles parsing the data we are going to work with **/
/** It also holds all the global variables we parse into         **/


string operation;
int last_instant, process_count;
vector<pair<char, int>> algorithms;
vector<tuple<string,int,int>> processes;
vector<vector<char>>timeline;
//unordered_map<string,int>processToIndex;


//Results

vector<int>finishTime;
vector<int>turnAroundTime;
//vector<float>normTurn;


// void parse_algorithms(string algorithm_chunk){
//     stringstream stream(algorithm_chunk);
//     while (stream.good()){
//         string temp_str;
//         getline(stream, temp_str, ',');
//         stringstream ss(temp_str);
//         getline(ss, temp_str, '-');
//         char algorithm_id = temp_str[0];
//         getline(ss, temp_str, '-');
//         int quantum = temp_str.size() >= 1 ? stoi(temp_str) : -1;
//         algorithms.push_back( make_pair(algorithm_id, quantum) );
//     }
// }


void parse_algorithms(string algorithm_chunk){
     char algorithm_id = algorithm_chunk[0];
     int quantum=-1;
     if(algorithm_chunk.size() > 1){
     	string temp = algorithm_chunk.substr(2,algorithm_chunk.size()-1);
     	quantum = stoi(temp); 	
	}
	algorithms.push_back( make_pair(algorithm_id, quantum) );
}

// void parse_processes(){
//     string process_chunk, process_name;
//     int process_arrival_time, process_service_time;
//     for(int i=0; i<process_count; i++){
//         cin >> process_chunk;
//         stringstream stream(process_chunk);
//         string temp_str;
//         getline(stream, temp_str, ',');
//         process_name = temp_str;
//         getline(stream, temp_str, ',');
//         process_arrival_time = stoi(temp_str);
//         getline(stream, temp_str, ',');
//         process_service_time = stoi(temp_str);
//         processes.push_back( make_tuple(process_name, process_arrival_time, process_service_time) );
//         processToIndex[process_name] = i;
//     }
// }


void parse_processes(){
    string process_chunk, process_name;
    int process_arrival_time, process_service_time;
    string temp;
	cout<<"Enter the processes: "<<endl;
    for(int i=0; i<process_count; i++){
        cin >> process_chunk;
        int n = process_chunk.size();
        int j=0;
        while(j<n){
       	    process_name = process_chunk[0];
            temp = process_chunk[2];
            process_arrival_time = stoi(temp);
            temp = process_chunk[4];
            process_service_time = stoi(temp);
            j++;
	    }
        processes.push_back( make_tuple(process_name, process_arrival_time, process_service_time) );
        //   processToIndex[process_name] = i;
    }
}

void parse(){
	string algorithm_chunk;
	cout<<"Enter the operation to be performed: ";
	cin >> operation;
	cout<<"Enter the algorithm id and Quantum if(algo == RR): ";
	cin >> algorithm_chunk;
	cout<<"Enter the last instant: ";
	cin >> last_instant;
	cout<<"Enter the process count: ";
	cin >> process_count;
	parse_algorithms(algorithm_chunk);
	parse_processes();
	finishTime.resize(process_count);
	turnAroundTime.resize(process_count);
	//normTurn.resize(process_count);
	timeline.resize(last_instant);
    for(int i=0; i<last_instant; i++){
        for(int j=0; j<process_count; j++){
        	timeline[i].push_back(' ');
	    }
    }      
}
// input: 
//trace
//1
//20
//5
//A,0,3
//B,2,6
//C,4,4
//D,6,5
//E,8,2


//#endif // PARSER_H_INCLUDED

// Here are some of the benefits of using header files in C++:
// Modularity:
// Header files allow you to break your program down into smaller, more manageable pieces. This makes your code easier to read, write, and maintain.
// Reusability:
// Header files allow you to reuse code between different programs. This can save you time and effort.
// Efficiency:
// Header files can help to improve the efficiency of your code by allowing the compiler to precompile the declarations in the header files.
// Overall, header files are a powerful tool that can help you to write better C++ code.
