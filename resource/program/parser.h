#ifndef PARSER_H
#define PARSER_H

#include "parsedline.h"
class Parser
{
public:
    void parse(QString, QList<ParsedLine*>&, QList<QString>&);

};

#endif // PARSER_H
