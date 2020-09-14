#-------------------------------------------------
#
# Project created by QtCreator 2019-11-11T03:05:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scapes
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    controller/compileprogcontrol.cpp \
    controller/loadfilecontrol.cpp \
    controller/manageprogcontrol.cpp \
    controller/runprogcontrol.cpp \
    controller/savefilecontrol.cpp \
    main_ui.cpp \
    program/addinstruction.cpp \
    program/arrayindexoutofboundsexception.cpp \
    program/basicoperandfactory.cpp \
    program/arrayoperand.cpp \
    program/arrayvariable.cpp \
    program/compareinstruction.cpp \
    program/declarearrayinstruction.cpp \
    program/declareintegerinstruction.cpp \
    program/endinstruction.cpp \
    program/identifier.cpp \
    program/identifierfactory.cpp \
    program/identifierinuseexception.cpp \
    program/instruction.cpp \
    program/instructionfactory.cpp \
    program/integervariable.cpp \
    program/invalidlineexception.cpp \
    program/invalidnumoperandsexception.cpp \
    program/jumpequalinstruction.cpp \
    program/jumpinstruction.cpp \
    program/jumplessinstruction.cpp \
    program/jumpmoreinstruction.cpp \
    program/label.cpp \
    program/labeloperand.cpp \
    program/literalintegeroperand.cpp \
    program/literalstringoperand.cpp \
    program/moveinstruction.cpp \
    program/operand.cpp \
    program/operandfactory.cpp \
    program/parsedline.cpp \
    program/parser.cpp \
    program/printinstruction.cpp \
    program/program.cpp \
    program/programcontext.cpp \
    program/programdeserializer.cpp \
    program/readintegerinstruction.cpp \
    program/redeclaredvariableexception.cpp \
    program/runtimeexception.cpp \
    program/scapescompiler.cpp \
    program/syntaxexception.cpp \
    program/undeclaredvariableexception.cpp \
    program/undefinedvariableexception.cpp \
    program/unsupportedoperandexception.cpp \
    program/unsupportedoperationexception.cpp \
    program/unsupportinstructionexception.cpp \
    program/validoperandtypes.cpp \
    program/valueoperand.cpp \
    program/variable.cpp \
    program/variableoperand.cpp \
    storage/storagecontrol.cpp \
    storage/storagemanager.cpp \
    ui/mainwindow.cpp

HEADERS += \
    controller/compileprogcontrol.h \
    controller/loadfilecontrol.h \
    controller/manageprogcontrol.h \
    controller/runprogcontrol.h \
    controller/savefilecontrol.h \
    controller/userdisplayprompt.h \
    program/addinstruction.h \
    program/arrayindexoutofboundsexception.h \
    program/basicoperandfactory.h \
    program/arrayoperand.h \
    program/arrayvariable.h \
    program/compareinstruction.h \
    program/compiler.h \
    program/declarearrayinstruction.h \
    program/declareintegerinstruction.h \
    program/endinstruction.h \
    program/identifier.h \
    program/identifierfactory.h \
    program/identifierinuseexception.h \
    program/instruction.h \
    program/instructionfactory.h \
    program/integervariable.h \
    program/invalidlineexception.h \
    program/invalidnumoperandsexception.h \
    program/jumpequalinstruction.h \
    program/jumpinstruction.h \
    program/jumplessinstruction.h \
    program/jumpmoreinstruction.h \
    program/label.h \
    program/labeloperand.h \
    program/literalintegeroperand.h \
    program/literalstringoperand.h \
    program/moveinstruction.h \
    program/operand.h \
    program/operandfactory.h \
    program/parsedline.h \
    program/parser.h \
    program/printinstruction.h \
    program/program.h \
    program/programcontext.h \
    program/programdeserializer.h \
    program/readintegerinstruction.h \
    program/redeclaredvariableexception.h \
    program/runtimeexception.h \
    program/scapescompiler.h \
    program/syntaxexception.h \
    program/undeclaredvariableexception.h \
    program/undefinedvariableexception.h \
    program/unsupportedoperandexception.h \
    program/unsupportedoperationexception.h \
    program/unsupportinstructionexception.h \
    program/validoperandtypes.h \
    program/valueoperand.h \
    program/variable.h \
    program/variableoperand.h \
    storage/storagecontrol.h \
    storage/storagemanager.h \
    ui/mainwindow.h

FORMS += \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
