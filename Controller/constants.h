#ifndef __CONSTANTS_INC__
#define __CONSTANTS_INC__

/* 
 *  This file containts all the packet types, commands
 *  and status constants
 *  
 */

// Packet types
typedef enum
{
  PACKET_TYPE_COMMAND = 0,
  PACKET_TYPE_RESPONSE = 1,
  PACKET_TYPE_ERROR = 2,
  PACKET_TYPE_MESSAGE = 3,
  PACKET_TYPE_HELLO = 4
} TPacketType;

// Response types. This goes into the command field
typedef enum
{
  RESP_OK = 0,
  RESP_STATUS=1,
  RESP_BAD_PACKET = 2,
  RESP_BAD_CHECKSUM = 3,
  RESP_BAD_COMMAND = 4,
  RESP_BAD_RESPONSE = 5,
  RESP_COLOR = 6,
} TResponseType;


// Commands
// For direction commands, param[0] = distance in cm to move
// param[1] = speed
typedef enum
{
  COMMAND_GET_STATS = 5,
  COMMAND_CLEAR_STATS = 6,
  COMMAND_TRIGGER_SERVO = 7,
  COMMAND_RESET_SERVO = 8,
  COMMAND_WASD_W = 9,
  COMMAND_WASD_A = 10,
  COMMAND_WASD_D = 11,
  COMMAND_WASD_X = 12,
  COMMAND_GET_COLOR_INFORMATION = 13,
  COMMAND_DROP_MEDPACK = 14,
  COMMAND_RESET_MEDPACK = 15,
} TCommandType;
#endif

