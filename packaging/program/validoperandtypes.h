#ifndef VALIDOPERANDTYPES_H
#define VALIDOPERANDTYPES_H

class ValidOperandTypes {
public:
    ValidOperandTypes();
    bool isLabelOperandValid();
    bool isLiteralIntOperandValid();
    bool isLiteralStringOperandValid();
    bool isIntegerOperandValid();
    void setLiteralIntOperandValidity(bool);
    void setLiteralStringOperandValidity(bool);
    void setIntegerOperandValidity(bool);
    void validateLabelOperand();
    void validateValueOperand();
    void validateVariableOperand();
    void validateIntegerOperand();


private:
    bool labelOperand;
    bool literalIntOperand;
    bool literalStringOperand;
    bool integerOperand;
    void invalidateAll();
};

#endif // VALIDOPERANDTYPES_H
