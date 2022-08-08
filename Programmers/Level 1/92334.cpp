#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

#include <iostream>

using namespace std;

vector<string> splitString(string input);
int stringIDToArrayNumber(vector<string> id_list, string id);

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    vector<vector<string>> id_reportList;
    vector<int> id_reportedCounter;
    // Init
    for(string id : id_list) {
        id_reportList.push_back(vector<string>());
        id_reportedCounter.push_back(0);
    }
    for(string content : report) {
        vector<string> parsed = splitString(content);
        string from = parsed[0];
        string to = parsed[1];
        int from_int = stringIDToArrayNumber(id_list, parsed[0]);
        int to_int = stringIDToArrayNumber(id_list, parsed[1]);
        if(find(id_reportList[from_int].begin(), id_reportList[from_int].end(), to) == id_reportList[from_int].end()) {
            id_reportList[from_int].push_back(to);
            id_reportedCounter[to_int]++;
        } else {
            // 중복
        }
    }
    
    vector<string> bannedList;
    for(int i = 0; i < id_reportedCounter.size(); i++) {
        if(id_reportedCounter[i] >= k) {
            bannedList.push_back(id_list[i]);
        }
    }
    
    vector<int> answer;
    for(int i = 0; i < id_list.size(); i++) {
        answer.push_back(0);
    }
    
    for(string bannedUser : bannedList) {
        for(int i = 0; i < id_reportList.size(); i++) {
            vector<string> personal = id_reportList[i];
            if(find(personal.begin(), personal.end(), bannedUser) == personal.end()) {
                // 못 찾음
            } else {
                answer[i]++;
            }
        }
    }
    
    return answer;
}

int stringIDToArrayNumber(vector<string> id_list, string id) {
    for(int i = 0; i < id_list.size(); i++) {
        if(id_list[i] == id) {
            return i;
        }
    }
    return -1;
}

vector<string> splitString(string input) {
    vector<string> ret;
    istringstream ss(input);
    string temp;
    while(getline(ss, temp, ' ')) {
        ret.push_back(temp);
    }
    return ret;
}