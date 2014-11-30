/* This file was autogenerated. All changes will be undone. */

#include <protonet_protocol.h>

const uint8_t msg_data_offset = 12;

void unpack_proto_msg_t(
   proto_msg_t* msg,
   proto_msg_buf_t* buf)
{
   uint8_t* unpack_offset = msg->data+msg_data_offset;
   switch(msg->header.message_type)
   {
   case Proto_Enter:
      unpack_enter(unpack_offset, &buf->enter);
      break;
   case Proto_Exit:
      unpack_exit(unpack_offset, &buf->exit);
      break;
   case Proto_Ping:
      unpack_ping(unpack_offset, &buf->ping);
      break;
   case Proto_Pong:
      unpack_pong(unpack_offset, &buf->pong);
      break;
   case Proto_Vehicle_Identification:
      unpack_vehicle_identification(unpack_offset, &buf->vehicle_identification);
      break;
   case Proto_Vehicle_Authorization_Request:
      unpack_vehicle_authorization_request(unpack_offset, &buf->vehicle_authorization_request);
      break;
   case Proto_Vehicle_Authorization_Reply:
      unpack_vehicle_authorization_reply(unpack_offset, &buf->vehicle_authorization_reply);
      break;
   case Proto_Vehicle_Mode_Command:
      unpack_vehicle_mode_command(unpack_offset, &buf->vehicle_mode_command);
      break;
   case Proto_Vehicle_Termination_Command:
      unpack_vehicle_termination_command(unpack_offset, &buf->vehicle_termination_command);
      break;
   case Proto_Vehicle_Telemetry_Command:
      unpack_vehicle_telemetry_command(unpack_offset, &buf->vehicle_telemetry_command);
      break;
   case Proto_Vehicle_Waypoint_Command:
      unpack_vehicle_waypoint_command(unpack_offset, &buf->vehicle_waypoint_command);
      break;
   case Proto_Vehicle_System_Status:
      unpack_vehicle_system_status(unpack_offset, &buf->vehicle_system_status);
      break;
   case Proto_Vehicle_Inertial_State:
      unpack_vehicle_inertial_state(unpack_offset, &buf->vehicle_inertial_state);
      break;
   case Proto_Vehicle_Global_Position:
      unpack_vehicle_global_position(unpack_offset, &buf->vehicle_global_position);
      break;
   case Proto_Vehicle_Body_Sensed_State:
      unpack_vehicle_body_sensed_state(unpack_offset, &buf->vehicle_body_sensed_state);
      break;
   case Proto_Vehicle_Attitude:
      unpack_vehicle_attitude(unpack_offset, &buf->vehicle_attitude);
      break;
   case Proto_Vehicle_Ground_Relative_State:
      unpack_vehicle_ground_relative_state(unpack_offset, &buf->vehicle_ground_relative_state);
      break;
   case Proto_Payload_Bay_Command:
      unpack_payload_bay_command(unpack_offset, &buf->payload_bay_command);
      break;
   case Proto_Payload_Bay_Mode_Command:
      unpack_payload_bay_mode_command(unpack_offset, &buf->payload_bay_mode_command);
      break;
   case Proto_Target_Designation_Command:
      unpack_target_designation_command(unpack_offset, &buf->target_designation_command);
      break;
   case Proto_UGV_Joystick:
      unpack_UGV_joystick(unpack_offset, &buf->UGV_joystick);
      break;
   case Proto_UGV_Battery_Status:
      unpack_UGV_battery_status(unpack_offset, &buf->UGV_battery_status);
      break;
   default:
      break;
   }
}

char* proto_typestr(proto_msg_type_t msg_type)
{
   if(msg_type == Proto_Enter)
   {
      return "Enter";
   }
   if(msg_type == Proto_Exit)
   {
      return "Exit";
   }
   if(msg_type == Proto_Ping)
   {
      return "Ping";
   }
   if(msg_type == Proto_Pong)
   {
      return "Pong";
   }
   if(msg_type == Proto_Vehicle_Identification)
   {
      return "Vehicle Identification";
   }
   if(msg_type == Proto_Vehicle_Authorization_Request)
   {
      return "Vehicle Authorization Request";
   }
   if(msg_type == Proto_Vehicle_Authorization_Reply)
   {
      return "Vehicle Authorization Reply";
   }
   if(msg_type == Proto_Vehicle_Mode_Command)
   {
      return "Vehicle Mode Command";
   }
   if(msg_type == Proto_Vehicle_Termination_Command)
   {
      return "Vehicle Termination Command";
   }
   if(msg_type == Proto_Vehicle_Telemetry_Command)
   {
      return "Vehicle Telemetry Command";
   }
   if(msg_type == Proto_Vehicle_Waypoint_Command)
   {
      return "Vehicle Waypoint Command";
   }
   if(msg_type == Proto_Vehicle_System_Status)
   {
      return "Vehicle System Status";
   }
   if(msg_type == Proto_Vehicle_Inertial_State)
   {
      return "Vehicle Inertial State";
   }
   if(msg_type == Proto_Vehicle_Global_Position)
   {
      return "Vehicle Global Position";
   }
   if(msg_type == Proto_Vehicle_Body_Sensed_State)
   {
      return "Vehicle Body Sensed State";
   }
   if(msg_type == Proto_Vehicle_Attitude)
   {
      return "Vehicle Attitude";
   }
   if(msg_type == Proto_Vehicle_Ground_Relative_State)
   {
      return "Vehicle Ground Relative State";
   }
   if(msg_type == Proto_Payload_Bay_Command)
   {
      return "Payload Bay Command";
   }
   if(msg_type == Proto_Payload_Bay_Mode_Command)
   {
      return "Payload Bay Mode Command";
   }
   if(msg_type == Proto_Target_Designation_Command)
   {
      return "Target Designation Command";
   }
   if(msg_type == Proto_UGV_Joystick)
   {
      return "UGV Joystick";
   }
   if(msg_type == Proto_UGV_Battery_Status)
   {
      return "UGV Battery Status";
   }
   return 0;
}