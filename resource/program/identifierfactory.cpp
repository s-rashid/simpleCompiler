#include "identifierfactory.h"

Identifier* IdentifierFactory::createIdentifier(QString type){
    if(type == "Label") {
        return new Label("");
    }
    else if(type == "IntegerVariable"){
        return new IntegerVariable("");
    }
    else if(type == "ArrayVariable"){
        return new ArrayVariable("");
    }
    return nullptr;
}
