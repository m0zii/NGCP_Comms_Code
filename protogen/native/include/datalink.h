#ifndef DATALINK_H
#define DATALINK_H

/* System Includes */
#include <stdint.h>

/* User Includes */
#include <config.h>
#include <queue.h>
#include <thread.h>

/* Legacy C interface, needs TLC */
#ifndef __cplusplus
#include <udp.h>
#include <serial.h>
typedef enum datalink_status_e
{
	NOT_CONFIGURED = 0,
	DISCONNECTED,
	CONNECTED
} datalink_status_t;

typedef enum datalink_type_e
{
	UDP,
	SERIAL
} datalink_type_t;


typedef union datalink_info
{
	char name[20];
	udp_info_t udp_info;
	serial_info_t serial_info;
}datalink_info_t;

typedef union datalink_config_u{
    udp_config_t udp;
    serial_config_t serial;
}datalink_config_t;


typedef struct datalink_s
{
	datalink_status_t status;
	datalink_type_t type;
	int32_t (*open)(datalink_info_t* datalink_info);
	int32_t (*transmit)(datalink_info_t* datalink_info, uint8_t* tx_buf, int16_t tx_len, uint8_t node_id);
	int32_t (*receive)(datalink_info_t* datalink_info, uint8_t* rx_buf, int16_t* rx_len);
	int32_t (*establish)(datalink_info_t* datalink_info, uint8_t node_id);
} datalink_t;


int32_t datalink_init(
		datalink_t* datalink,
		datalink_info_t* datalink_info,
		datalink_type_t datalink_type,
		datalink_config_t* datalink_config);


#endif
#ifdef __cplusplus


namespace protonet
{
	/* Allows datalink to keep track of storage/inheritance */
	typedef enum datalink_type_e
	{
		UDP_TYPE,
		SERIAL_TYPE,
		XBEE_TYPE,
		UNINIT_TYPE
	} datalink_type_t;

	/* Generic transport layer independent datalink, used for abstraction */
	class datalink
	{
	public:
		datalink();
		~datalink();
		void set_link_id(int8_t link_id);
		/*
		Set pointer to the queue used by the 
		event handler.
		*/
		void set_queue(proto_msg_queue* queue);
		int8_t get_link_id();
		datalink_type_t get_datalink_type();
		int32_t is_connected();
		/* 
		Virtual functions meant for specific "drivers" to override 
		Please profile for possibility of vtable optimizations
		*/
		virtual int32_t run();
		virtual int32_t open();
		virtual int32_t close();
		virtual int32_t send(uint8_t node_id, uint8_t* tx_data, int32_t tx_len);
		virtual int32_t recv(uint8_t* rx_data, int32_t* rx_len);
		virtual int32_t establish(uint8_t node_id);
		/*
		Thread function that initializes the datalink, parses a message,
		and puts an inbound proto_msg_t in the queue for unpacking.
		This is the heart of the receive side for any datalink type.
		*/
		void* datalink_handler();
		/*
		Helper function to convert between C++ and C function signatures
		due to casting as a class member being incompatible with C style
		thread creation APIs. Static linkage helps with that.
		*/
		static void *thread_helper(void* context);
	protected:
		/* Thread handle */
		thread_t datalink_thread;
		datalink_type_t datalink_type;
		int32_t connected;
		int8_t link_id;
		proto_msg_queue* queue;
		uint8_t rx_buf[1024];

	};
}
#endif
#endif