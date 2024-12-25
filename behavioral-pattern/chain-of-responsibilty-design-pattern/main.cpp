#include <iostream>
#include "logProcessor.cpp"
using namespace std;

int main()
{
    InfoLogger *infoLogger = new InfoLogger();
    WarningLogger *warningLogger = new WarningLogger();
    ErrorLogger *errorLogger = new ErrorLogger();

    infoLogger->SetNextLogProcessor(warningLogger);
    warningLogger->SetNextLogProcessor(errorLogger);

    infoLogger->LogMessage(INFO, "This is an info messgae");
    infoLogger->LogMessage(WARNING, "This is a warning messgae");
    infoLogger->LogMessage(ERROR, "This is an error messgae");
}