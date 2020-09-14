#ifndef USERDISPLAYPROMPT_H
#define USERDISPLAYPROMPT_H

#include <QString>

class UserDisplayPrompt {
public:
    virtual ~UserDisplayPrompt() = default;
    virtual void printToDisplay(QString) = 0;
    virtual void displaySuccessfullCompileMsg(QString) = 0;
    virtual void displayRuntimeError(QString) = 0;
    virtual void displayCompileError(QString) = 0;
    virtual int displayInputPrompt(int&) = 0;

};

#endif // DISPLAYERRORPROMPT_H
