#ifndef VALIDOPERANDTYPES_H
#define VALIDOPERANDTYPES_H

class ValidOperandTypes {
public:
    ValidOperandTypes();
    bool isLabelOperandValid();
    bool isLiteralIntOperandValid();
    bool isLiteralStringOperandValid();
    bool isVariableOperandValid();
    bool isArrayOperandValid();
    void setLiteralIntOperandValidity(bool);
    void setLiteralStringOperandValidity(bool);
    void setVariableOperandValidity(bool);
    void setArrayOperandValidity(bool);
    void validateLabelOperand();
    void validateValueOperand();
    void validateVariableOperand();
    void validateVariableDeclarationOperand();
    void validateIntegerOperand();
    void validateArrayOperand();


private:
    bool labelOperand;
    bool literalIntOperand;
    bool literalStringOperand;
    bool variableOperand;
    bool arrayOperand;
    void invalidateAll();
};

#endif // VALIDOPERANDTYPES_H
