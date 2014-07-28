%module sphero

%include "std_string.i"
%include "inttypes.i"

%{
#include "libSphero.h"
%}

// Map the command message types
%rename(PING_Command_Message) LibSphero::Command::MessageType::PING;
%rename(VERSIONING_Command_Message) LibSphero::Command::MessageType::VERSIONING;
%rename(SET_BLUETOOTH_NAME_Command_Message) LibSphero::Command::MessageType::SET_BLUETOOTH_NAME;
%rename(GET_BLUETOOTH_NAME_Command_Message) LibSphero::Command::MessageType::GET_BLUETOOTH_NAME;
%rename(GO_TO_SLEEP_Command_Message) LibSphero::Command::MessageType::GO_TO_SLEEP;
%rename(JUMP_TO_BOOTLOADER_Command_Message) LibSphero::Command::MessageType::JUMP_TO_BOOTLOADER;
%rename(LEVEL_1_DIAGNOSTICS_Command_Message) LibSphero::Command::MessageType::LEVEL_1_DIAGNOSTICS;
%rename(JUMP_TO_MAIN_Command_Message) LibSphero::Command::MessageType::JUMP_TO_MAIN;
%rename(CALIBRATE_Command_Message) LibSphero::Command::MessageType::CALIBRATE;
%rename(STABILIZATION_Command_Message) LibSphero::Command::MessageType::STABILIZATION;
%rename(ROTATION_RATE_Command_Message) LibSphero::Command::MessageType::ROTATION_RATE;
%rename(RGB_LED_OUTPUT_Command_Message) LibSphero::Command::MessageType::RGB_LED_OUTPUT;
%rename(FRONT_LED_OUTPUT_Command_Message) LibSphero::Command::MessageType::FRONT_LED_OUTPUT;
%rename(ROLL_Command_Message) LibSphero::Command::MessageType::ROLL;
%rename(BOOST_Command_Message) LibSphero::Command::MessageType::BOOST;
%rename(RAW_MOTOR_Command_Message) LibSphero::Command::MessageType::RAW_MOTOR;
%rename(GET_CONFIGURATION_BLOCK_Command_Message) LibSphero::Command::MessageType::GET_CONFIGURATION_BLOCK;
%rename(RUN_MACRO_Command_Message) LibSphero::Command::MessageType::RUN_MACRO;
%rename(MACRO_Command_Message) LibSphero::Command::MessageType::MACRO;
%rename(SAVE_MACRO_Command_Message) LibSphero::Command::MessageType::SAVE_MACRO;
%rename(ABORT_MACRO_Command_Message) LibSphero::Command::MessageType::ABORT_MACRO;
%rename(SET_DATA_STREAMING_Command_Message) LibSphero::Command::MessageType::SET_DATA_STREAMING;
%rename(SPIN_LEFT_Command_Message) LibSphero::Command::MessageType::SPIN_LEFT;
%rename(SPIN_RIGHT_Command_Message) LibSphero::Command::MessageType::SPIN_RIGHT;
%rename(CUSTOM_PING_Command_Message) LibSphero::Command::MessageType::CUSTOM_PING;
%rename(INVALID_Command_Message) LibSphero::Command::MessageType::INVALID;
%ignore LibSphero::Command::operator<<;
%rename(Command_Message) LibSphero::Command::Message;
%include "libSphero/Command.h"

%{
#include "libSphero/Response.h"
%}

// Map the error messages
%rename(RESPONSE_CODE) LibSphero::Response::Code;
%rename(OK_RESPONSE) LibSphero::Response::Code::OK;
%rename(GENERAL_ERROR) LibSphero::Response::Code::ERROR_GENERAL;
%rename(CHECKSUM_ERROR) LibSphero::Response::Code::ERROR_CHECKSUM;
%rename(FRAGMENT_ERROR) LibSphero::Response::Code::ERROR_FRAGMENT;
%rename(BAD_COMMAND_ERROR) LibSphero::Response::Code::ERROR_BAD_COMMAND;
%rename(UNSUPPORTED_ERROR) LibSphero::Response::Code::ERROR_UNSUPPORTED;
%rename(BAD_MESSAGE_ERROR) LibSphero::Response::Code::ERROR_BAD_MESSAGE;
%rename(PARAMETER_ERROR) LibSphero::Response::Code::ERROR_PARAMETER;
%rename(EXECUTE_ERROR) LibSphero::Response::Code::ERROR_EXECUTE;
%rename(MAIN_APP_CORRUPT_ERROR) LibSphero::Response::Code::ERROR_MAIN_APP_CORRUPT;
%rename(TIME_OUT_ERROR) LibSphero::Response::Code::ERROR_TIME_OUT;
%rename(UNKNOWN_ERROR) LibSphero::Response::Code::ERROR_UNKNOWN;
%rename(UNKNOWN_RESPONSE) LibSphero::Response::Code::UNKNOWN_RESPONSE;
%rename(INVALID_ERROR) LibSphero::Response::Code::INVALID;
%ignore LibSphero::Response::operator<<;

// Map the information codes
%rename(EMIT_InformationCode) LibSphero::Response::InformationCode::EMIT;
%rename(DATA_InformationCode) LibSphero::Response::InformationCode::DATA;
%rename(INVALID_InformationCode) LibSphero::Response::InformationCode::INVALID;

// Rename command and response messages
%rename(Response_Message) LibSphero::Response::Message;
%include "libSphero/Response.h"

%{
#include "libSphero/Robot.h"
#include "libSphero/Macro.h"
%}

%include "libSphero/Robot.h"
%include "libSphero/Macro.h"
