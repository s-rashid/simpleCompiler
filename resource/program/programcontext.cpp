#include "programcontext.h"

ProgramContext::ProgramContext() {

}

Identifier* ProgramContext::getIdentifier(const QString& key) {
    return variables.value(key, nullptr);
}

QHash<QString, Identifier*> ProgramContext::getIdentifiers() {
    return variables;
}

bool ProgramContext::addIdentifier(const QString key, Identifier* value) {
    if (variables.contains(key)) {
        return false;
    }
    variables.insert(key, value);
    return true;
}
