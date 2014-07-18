%module sphero

%{
#include "../../libSphero.h"
%}

%rename(INVALID_Command_Message) LibSphero::Command::MessageType::INVALID;
%rename(INVALID_Response_Code) LibSphero::Response::Code::INVALID;
%rename(INVALID_Response_InformationCode) LibSphero::Response::InformationCode::INVALID;
%rename(Command_Message) LibSphero::Command::Message;
%rename(Response_Message) LibSphero::Response::Message;
%ignore LibSphero::Command::operator<<;
%ignore LibSphero::Response::operator<<;

%include "../libSphero.h"
