#ifndef UDP_H_
#define UDP_H_

/* User Includes */
#include <config.h>
#include <datalink.h>

#ifdef __unix__
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdint.h>
#include <string.h>
typedef int32_t sock_fd_t;
#endif
/* Define generic socket types */
#ifdef _WIN32
typedef SOCKET sock_fd_t;
#endif

/* Generic storage for a UDP endpoint */
typedef struct udp_address_s
{
	char serv[16];
	uint16_t port;
}udp_address_t;

/* 
Since UDP is addressed, storage is provided
to map UDP addresses to node IDs. This is
unlike the Serial datalink, which is one-to-one.
*/
typedef struct udp_info_s
{
	sock_fd_t fd;
	udp_address_t config;
	udp_address_t last_addr; /* Keeps track of received message */
	udp_address_t node_addr[255];
	uint8_t node_connected[255];
}udp_info_t;

/* Mandatory datalink overrides for functionality */
int32_t udp_open(sock_fd_t* fd, udp_address_t* config);

int32_t udp_config(sock_fd_t* fd, udp_address_t* config);

int32_t udp_read(
	sock_fd_t* fd, 
	uint8_t* buf, 
	int32_t* rx_len,  
	udp_address_t* rx_addr);

int32_t udp_send(
	sock_fd_t* fd, 
	uint8_t* buf, 
	int32_t tx_len, 
	udp_address_t tx_addr);

int32_t udp_close(sock_fd_t* fd);

using namespace protonet;
#ifdef __cplusplus
class UDP : public datalink
{
public:
	/* Binds every available interface at specified port */
	UDP(uint16_t port);

	/* Targets interface at IP address*/
	UDP(uint16_t port, char addr[16]);

	~UDP();
	
	/* 
	Implement the generic open/close/send/recv functions from the inherited 
	datalink interface. open is harder to wrap, so ignore those.
	*/
	int32_t open(uint16_t port);
	int32_t open(uint16_t port, char addr[16]);
	int32_t close() ;
	int32_t send(uint8_t node_id, uint8_t tx_data[1024], int32_t tx_len);
	int32_t recv(uint8_t* rx_data, int32_t* rx_len) ;

	/* Maps a node ID to a specific IP address for internal handling */
	int32_t establish(uint8_t node_id, uint16_t port, char addr[16]) ;

	/* Similar to previous function, allows use of udp_address_t struct */
	int32_t establish(uint8_t node_id, udp_address_t* rx_addr);

	/* Maps a node to the last received address */
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
	sock_fd_t fd;
	udp_address_t config;
	udp_info_t info;
	udp_address_t rx_addr;
};

#endif

#endif /* UDP_H_ */

