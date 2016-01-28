call "%VS100COMNTOOLS%..\..\VC\vcvarsall.bat" x86

cl /FA circular-templates.cpp
cl /FA circular-templates-fixed.cpp

pause