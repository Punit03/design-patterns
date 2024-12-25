#include <iostream>
#include <string>

using namespace std;

enum LogLevel
{
    INFO,
    WARNING,
    ERROR
};

class LogProcessor
{
public:
    virtual void SetNextLogProcessor(LogProcessor *nextLogProcessor) = 0;
    virtual void LogMessage(LogLevel log, string message) = 0;
};

class AbstractLogProcessor : public LogProcessor
{
private:
    LogProcessor *nextLogProcessor;

protected:
    LogLevel level;

public:
    AbstractLogProcessor(LogLevel level) : level(level), nextLogProcessor(NULL){};
    void SetNextLogProcessor(LogProcessor *nextLogProcessor)
    {
        this->nextLogProcessor = nextLogProcessor;
    }

    void LogMessage(LogLevel log, string message)
    {
        if (log > level)
        {
            nextLogProcessor->LogMessage(log, message);
        }
        else
        {
            handleLogMessage(log, message);
        }
    }
    virtual void handleLogMessage(LogLevel log, string message) = 0;
};

class InfoLogger : public AbstractLogProcessor
{
public:
    InfoLogger() : AbstractLogProcessor(INFO){};
    void handleLogMessage(LogLevel log, string message)
    {
        cout << "[Info:] " << message << "\n";
    }
};

class WarningLogger : public AbstractLogProcessor
{
public:
    WarningLogger() : AbstractLogProcessor(WARNING){};
    void handleLogMessage(LogLevel log, string message)
    {
        cout << "[Warning:] " << message << "\n";
    }
};

class ErrorLogger : public AbstractLogProcessor
{
public:
    ErrorLogger() : AbstractLogProcessor(ERROR){};
    void handleLogMessage(LogLevel log, string message)
    {
        cout << "[Error:] " << message << "\n";
    }
};