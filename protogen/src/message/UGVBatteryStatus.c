/* This file was autogenerated. All changes will be undone. */

/* Message: UGV_Battery_Status, ID: 5001*/

#include <marshal.h>
#include <message.h>
#include <message/UGVBatteryStatus.h>

msg_offset pack_UGV_battery_status(
   UGV_battery_status_t* UGV_battery_status,
   msg_offset offset)
{
   offset = pack_float64_t(UGV_battery_status->timestamp,offset);
   offset = pack_float64_t(UGV_battery_status->3_3V_voltage,offset);
   offset = pack_float64_t(UGV_battery_status->5V_voltage,offset);
   offset = pack_float64_t(UGV_battery_status->12V_voltage,offset);
   offset = pack_float64_t(UGV_battery_status->3_3V_current,offset);
   offset = pack_float64_t(UGV_battery_status->5V_current,offset);
   offset = pack_float64_t(UGV_battery_status->12V_current,offset);
   return offset;
}

msg_offset unpack_UGV_battery_status(
   msg_offset offset,
   UGV_battery_status_t* out_ptr)
{
   offset = unpack_float64_t(offset, &out_ptr->timestamp);
   offset = unpack_float64_t(offset, &out_ptr->3_3V_voltage);
   offset = unpack_float64_t(offset, &out_ptr->5V_voltage);
   offset = unpack_float64_t(offset, &out_ptr->12V_voltage);
   offset = unpack_float64_t(offset, &out_ptr->3_3V_current);
   offset = unpack_float64_t(offset, &out_ptr->5V_current);
   offset = unpack_float64_t(offset, &out_ptr->12V_current);
   return offset;
}

void encode_UGV_battery_status(
   uint8_t src_id,
   uint8_t dest_id,
   uint8_t msg_ttl,
   uint8_t seq_number,
   UGV_battery_status_t* tx_msg,
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
   msg->header.message_length = 56;
   msg->header.message_type = Proto_UGV_Battery_Status;
   offset = pack_sync(offset);
   offset = pack_header(&msg->header, offset);
   offset = pack_UGV_battery_status(tx_msg, offset);
   offset = pack_checksum(start_offset, offset);
   msg->tx_len = offset-start_offset;
}