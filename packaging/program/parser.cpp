#include "parser.h"
#include "invalidlineexception.h"
#include "../controller/manageprogcontrol.h"

#include <iostream>
#include <QTextStream>

/**
 * Parses a QString of scapl source into its respective parts (label, instruct type, operands)
 * using a ParsedLine object to store this data.
 *
 * @param inctructions, scapl source code
 * @return parsedLines, list of populated parsed line data objects
 * @return labels, list of all label names in the scapl source
 */
void Parser::parse(QString instructions, QList<ParsedLine*>& parsedLines, QList<QString>& labels){

    QRegExp labelRE("^\\s*([^:\\s]+)\\s*:\\s*");
    QRegExp commentRE("^\\s*#([^\n])*");
    //group 0 whole match, group 1 operand, group 2 literal, group 3 token
    QRegExp tokenRE("^\\s*((\"(?:\\\"|[^\"])*\")|([^:\"\\s]+))(?: |$)+");

    std::cout << "Parsing..." << std::endl;
    QStringList lines = instructions.split("\n");
    int lineNumber = 0;

    ParsedLine* pl = nullptr;
    QString label = "";
    foreach (QString line, lines){
        pl = new ParsedLine();

        if (line.isEmpty()) continue;

        //search for comment
        if (commentRE.indexIn(line) > -1) continue;

        //search for label
        if (labelRE.indexIn(line) > -1){
            label = labelRE.cap(1);
            labels.append(label);
            pl->setLabel(label);
            line.remove(labelRE);
        }

        //search for type token
        if (tokenRE.indexIn(line) > -1){
            if (!tokenRE.cap(1).isEmpty()){
                pl->setInstrucType(tokenRE.cap(1));
                line.remove(tokenRE);
            }
        }
        //label for empty line
        else if (label != "") {
            InvalidLineException e = InvalidLineException(label);
            e.setLineNumber(lineNumber);
            e.setLine(lines[lineNumber]);
            throw e;
        }

        //search for next token
        while (!line.isEmpty()){
            if (tokenRE.indexIn(line) > -1){
                if (!tokenRE.cap(2).isEmpty()) {
                    QString literal = tokenRE.cap(2);
                    literal.replace("\\\"", "\"");
                    literal.replace("\\n", "\n");
                    pl->addOperand(literal);
                }
                else{
                    pl->addOperand(tokenRE.cap(1));
                }
                line.remove(tokenRE);
            }
        }
        std::cout << pl->toQString().toStdString() << std::endl;
        parsedLines.append(pl);
    }
}
