#include<iostream>
#include<vector>

//If you write all classes in a single file use:
#include "allClasses.h"

//If you write each class in a seperate file use:
//#include "user.h"
//#include "server.h"
//#include "log.h"
//#include "string_log.h"

using namespace std;


template <class T1>
void test(T1 test, T1 target, std::string msg){
    std::string equal = test==target ? "Success: " : "Failed:  ";
    std::cout << equal << msg << "\t " << test << "    " << target << std::endl;
}

void testEps(double test, double target, std::string msg, double eps=1e-5){
    std::string equal = (target-test)*(target-test) < eps*eps ? "Success: " : "Failed:  ";
    std::cout << equal << msg << "\t " << test << " " << target << std::endl;
}

void testStringLog(StringLog& sl, int logLevel){
    bool success = true;
    std::string feedback;
    std::vector<std::string> correctMsgs;
    if(logLevel == 0){
        correctMsgs = {};
    }
    if(logLevel == 1){
        correctMsgs = {"[WARNING] Password too short",
                       "[WARNING] Log in failed"};
    } else if(logLevel == 2){
        correctMsgs = {"[INFO] Adding user clawdeen95...",
                       "[WARNING] Password too short",
                       "[INFO] Adding user draculaura88...",
                       "[INFO] User added",
                       "[INFO] Logging in - draculaura88...",
                       "[INFO] Logged in",
                       "[INFO] Logging in - johndoe...",
                       "[WARNING] Log in failed"};
    }
    if(sl.getMsgs().size() != correctMsgs.size()){
        success = false;
        feedback = "Failed: Incorrect number of messages. Expected "
                + std::to_string(correctMsgs.size())
                + " but got "
                + std::to_string(sl.getMsgs().size())
                + " (logLevel==" + std::to_string(logLevel) + ")";
    }
    for(int i=0; i<correctMsgs.size(); i++){
        if(correctMsgs[i] != sl.getMsgs()[i]){
            success = false;
            feedback = "Failed: Incorrect message. Expected: '"
                    + correctMsgs[i]
                    + "' but got '"
                    + sl.getMsgs()[i] + "'"
                    + " (logLevel==" + std::to_string(logLevel) + ")";
        }
    }
    if(success == true){
        feedback = "Success: StringLog messages are correct (logLevel=="
                + std::to_string(logLevel) + ")";
    }
    std::cout << feedback << std::endl;
}

void runConnection(Log &log){
    Server s;
    User claw("clawdeen95","1234");
    User drac("draculaura88", "hamstermaster");
    User john("johndoe", "bladerunner");
    s.addLog(log);
    s.addUser(claw);
    s.addUser(drac);
    s.login(&drac);
    s.login(&john);
}

int main(){
    /* Testing User */
    std::cout << "--- TESTING: User ---" << std::endl;
    User bat("batman","darkNedgy");
    test<std::string>(bat.name,"batman","Username");
    test<std::string>(bat.password,"darkNedgy","Password");
    std::cout << std::endl;

    /* Testing StringLog */
    std::cout << "--- TESTING: StringLog ---" << std::endl;
    StringLog log_b(2);
    runConnection(log_b);
    testStringLog(log_b,2);

    log_b.clearLog();
    log_b.setLogLevel(1);
    runConnection(log_b);
    testStringLog(log_b,1);

    log_b.clearLog();
    log_b.setLogLevel(0);
    runConnection(log_b);
    testStringLog(log_b,0);

    return 0;
}
