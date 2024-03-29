/* This file was autogenerated. All changes will be undone. */

/* Message: Vehicle_Inertial_State, ID: 2001*/

#include <protonet_marshal.h>
#include <protonet_message.h>
#include <message/VehicleInertialState.h>

msg_offset pack_vehicle_inertial_state(
   vehicle_inertial_state_t* vehicle_inertial_state,
   msg_offset offset)
{
   offset = pack_float64_t(vehicle_inertial_state->timestamp,offset);
   offset = pack_uint16_t(vehicle_inertial_state->vehicle_ID,offset);
   offset = pack_float64_t(vehicle_inertial_state->latitude,offset);
   offset = pack_float64_t(vehicle_inertial_state->longitude,offset);
   offset = pack_float32_t(vehicle_inertial_state->altitude,offset);
   offset = pack_float32_t(vehicle_inertial_state->roll,offset);
   offset = pack_float32_t(vehicle_inertial_state->pitch,offset);
   offset = pack_float32_t(vehicle_inertial_state->heading,offset);
   offset = pack_float32_t(vehicle_inertial_state->north_speed,offset);
   offset = pack_float32_t(vehicle_inertial_state->east_speed,offset);
   offset = pack_float32_t(vehicle_inertial_state->vertical_speed,offset);
   offset = pack_float32_t(vehicle_inertial_state->roll_rate,offset);
   offset = pack_float32_t(vehicle_inertial_state->pitch_rate,offset);
   offset = pack_float32_t(vehicle_inertial_state->yaw_rate,offset);
   offset = pack_float32_t(vehicle_inertial_state->north_accel,offset);
   offset = pack_float32_t(vehicle_inertial_state->east_accel,offset);
   offset = pack_float32_t(vehicle_inertial_state->vertical_accel,offset);
   return offset;
}

msg_offset unpack_vehicle_inertial_state(
   msg_offset offset,
   vehicle_inertial_state_t* out_ptr)
{
   offset = unpack_float64_t(offset, &out_ptr->timestamp);
   offset = unpack_uint16_t(offset, &out_ptr->vehicle_ID);
   offset = unpack_float64_t(offset, &out_ptr->latitude);
   offset = unpack_float64_t(offset, &out_ptr->longitude);
   offset = unpack_float32_t(offset, &out_ptr->altitude);
   offset = unpack_float32_t(offset, &out_ptr->roll);
   offset = unpack_float32_t(offset, &out_ptr->pitch);
   offset = unpack_float32_t(offset, &out_ptr->heading);
   offset = unpack_float32_t(offset, &out_ptr->north_speed);
   offset = unpack_float32_t(offset, &out_ptr->east_speed);
   offset = unpack_float32_t(offset, &out_ptr->vertical_speed);
   offset = unpack_float32_t(offset, &out_ptr->roll_rate);
   offset = unpack_float32_t(offset, &out_ptr->pitch_rate);
   offset = unpack_float32_t(offset, &out_ptr->yaw_rate);
   offset = unpack_float32_t(offset, &out_ptr->north_accel);
   offset = unpack_float32_t(offset, &out_ptr->east_accel);
   offset = unpack_float32_t(offset, &out_ptr->vertical_accel);
   return offset;
}

void encode_vehicle_inertial_state(
   uint8_t src_id,
   uint8_t dest_id,
   uint8_t msg_ttl,
   uint8_t seq_number,
   vehicle_inertial_state_t* tx_msg,
   proto_msg_t* msg)
{
   msg_offset start_offset, offset;
   msg->direction = Proto_Out;
   start_offset = msg->data;
   offset = msg->data;
   msg->header.node_src_id = src_id;
   msg->header.node_dest_id = dest_id;
   msg->header.message_ttl = msg_ttl;
   msg->header.sequence_number = seq_number;
   msg->header.message_length = 78;
   msg->header.message_type = Proto_Vehicle_Inertial_State;
   offset = pack_sync(offset);
   offset = pack_header(&msg->header, offset);
   offset = pack_vehicle_inertial_state(tx_msg, offset);
   offset = pack_checksum(start_offset, offset);
   msg->tx_len = offset-start_offset;
}