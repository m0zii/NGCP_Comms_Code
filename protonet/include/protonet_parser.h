#ifndef PROTONET_PARSER_H_
#define PROTONET_PARSER_H_

/*System Includes */
#include <stdint.h>

/* User Includes */
#include <protonet_message.h>

/* Keep track of the bytes we are parsing */
typedef enum parse_state_e{
	WAIT_SYNC_C = 0, /* CPP\0 is the sync byte */
	WAIT_SYNC_P1,
	WAIT_SYNC_P2,
	WAIT_SYNC_NULL,
	WAIT_MESSAGE_HEADER,
	WAIT_MESSAGE_DATA,
	WAIT_MESSAGE_CHECKSUM
} parse_state_t;

/* Variable to keep track of length to help parse multibyte sections */
typedef uint16_t parse_count_t;

/* Sum of each byte as a uint8_t to calculate two's complement to verify message*/
typedef checksum_t parse_sum_t;

/* State data for the parser, simple Skolem machine */
typedef struct parse_data
{
	parse_state_t parse_state;
	parse_count_t parse_count;
	parse_sum_t parse_sum;
}parse_data_t;


/* Ensure that the parser starts out uninitialized */
int32_t parse_init(parse_data_t* parse_data);

/* 
Extracts sections of a protonet message from each byte
Returns 1 if a valid protonet message has been received
*/
int32_t parse_message(
		uint8_t rx_byte, /*in*/
		parse_data_t* parse_data, /*in*/
		proto_msg_t* rx_msg); /*out*/

uint32_t print_parse_state(parse_state_t parse_state);

#endif 
