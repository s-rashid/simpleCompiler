#ifndef DISPLAYERRORPROMPT_H
#define DISPLAYERRORPROMPT_H

#include <QString>

class DisplayErrorPrompt {
public:
    virtual ~DisplayErrorPrompt() = default;
    virtual void displayError(QString) = 0;
};

#endif // DISPLAYERRORPROMPT_H
