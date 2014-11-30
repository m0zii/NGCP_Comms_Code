#ifndef SERIAL_H_
#define SERIAL_H_

/* System Includes */
#include <stdint.h>
#include <stdio.h>
#include <string.h>


/* User Includes */
#include <config.h>
#include <datalink.h>


/* Define a cross platform serial handle */
#ifdef __unix__
typedef int32_t serial_fd_t;
#endif

#ifdef _WIN32
typedef HANDLE serial_fd_t;
#endif

/* Configuration struct to store in the datalink class & methods */
typedef struct serial_config_s
{
	uint32_t baud_rate;
	char device_path[64];
}serial_config_t;

/* Store serial port configuration data, handle and connected node_id */
typedef struct serial_info_s
{
	serial_fd_t fd;
	serial_config_t config;
	uint8_t node_id;
}serial_info_t;

int32_t serial_open(serial_fd_t* fd, serial_config_t* config);

int32_t serial_close(serial_fd_t* fd);

int32_t serial_config(serial_fd_t* fd, serial_config_t* config);

int32_t serial_read(
	serial_fd_t* fd,
	uint8_t* buf,
	int32_t* rx_len);

int32_t serial_send(
	serial_fd_t* fd,
	uint8_t* buf,
	int32_t tx_len);

using namespace protonet;
/* 
Datalink class is inherited to provide abstraction from transport layers 
The serial port is as a one-to-one connection with a specified node.
*/
class Serial : public datalink
{
public: 
	Serial();
	~Serial();

	/* 
	Implement the generic open/close/send/recv functions from the inherited 
	datalink interface. open is harder to wrap, so ignore.
	*/
	int32_t open(uint32_t baud_rate, char device_path[50]);
	int32_t close();
	int32_t send(
		uint8_t node_id, 
		uint8_t* tx_data, 
		int32_t tx_len);

	int32_t recv(uint8_t* rx_data, int32_t* rx_len);
	/*
	Serial is one-to-one, so each serial datalink is mapped to
	a single node ID
	*/
	int32_t establish(uint8_t node_id);
	
	using datalink::set_link_id;
	using datalink::get_link_id;
	using datalink::get_datalink_type;
	using datalink::is_connected;
private:
	using datalink::connected;
	using datalink::link_id;
	using datalink::rx_buf;
	using datalink::datalink_type;
	
	serial_fd_t fd;
	serial_config_t config;
	serial_info_t info;
	uint8_t rx_node;
};

#endif /* SERIAL_H_ */
