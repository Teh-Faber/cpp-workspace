#pragma once

#include<iostream>
#include<vector>


class Log{
    int _logLevel;
public:
    Log(int logLevel): _logLevel(logLevel) {}

    void setLogLevel(int logLevel){
        _logLevel = logLevel;
    }

    int getLogLevel(){
        return _logLevel;
    }

    virtual void info(std::string s) = 0;

    virtual void warning(std::string s) = 0;

};

class StringLog : public Log{
    std::vector<std::string> _msg;
public:
    StringLog(int logLevel) : Log(logLevel) {}

    void addMsg(std::string s){
        _msg.push_back(s);
    }

    std::vector<std::string> getMsgs(){
        return _msg;
    }

    void clearLog(){
        _msg.clear();
    }

    void info(std::string s) override{
        if(getLogLevel() == 2)
        addMsg("[INFO] "+s);
    }

    void warning(std::string s) override{
        if(getLogLevel() >= 1)
        addMsg("[WARNING] "+s);
    }
};


class User{
public:
    std::string name;
    std::string password;
    User(std::string name, std::string password):name(name),password(password){}
};

class Server{
private:
    std::vector<User> _users;
    Log *_log;
public:
    void addUser(User user){
        _log->info("Adding user " + user.name + "...");
        if(user.password.size()<8){
                _log->warning("Password too short");
                return;
        }
        _users.push_back(user);
        _log->info("User added");
    }

    void login(User * user){
        _log->info("Logging in - " + user->name + "...");
        for(User u : _users){
            if(u.name == user->name && u.password == user->password){
               _log->info("Logged in");
               return;
            }
        }
        _log->warning("Log in failed");
    }

    void addLog(Log &log){
        _log = &log;
    }
};
