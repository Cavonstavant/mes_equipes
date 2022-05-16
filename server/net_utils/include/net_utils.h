/*
** EPITECH PROJECT, 2022
** mon_FTP
** File description:
** net_utils
*/

/// \file server/net_utils/include/net_utils.h

#ifndef NET_UTILS_H
    #define NET_UTILS_H

    #include <sys/socket.h>
    #include <sys/select.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/queue.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <errno.h>
    #include "net_utils/auth/user.h"

    /// Defines the maximum connections allowed at the same time on a server
    #define LISTEN_BACKLOG 50

    /// Defines the maximum size of a message
    #define MAX_MSG 55555

    /// Defines the server status
    #define STOPPED false
    #define RUNNING true

/// \brief Represents a client connection
typedef struct peer_s {
    /// A file descriptor for the socket
    int sock_fd;

    /// The address of the client
    struct sockaddr_in peer_addr;

    // A pointer to a generic data type.
    void *data;

    /// Represents the state of an incoming message
    /// true if the transaction as been started but not finished
    /// false if the transaction has been finished or not started
    /// defaulted to false
    bool pending_command;

    /// Represents the state of an outcoming message
    /// true if the transaction as been started but not finished
    /// false if the transaction has been finished or not started
    /// defaulted to false
    bool pending_write;

    /// A pointer to the next/prev peer
    CIRCLEQ_ENTRY(peer_s) peers;
} peer_t;

/// \brief Initializes a circular queue of peers
CIRCLEQ_HEAD(peers_head, peer_s);

/// \brief Represents a basic tcp server
typedef struct tcp_server_s {
    /// The file descriptor of the server socket
    int sock_fd;

    /// The port of the server
    uint16_t port;

    /// The address representation of the server
    struct sockaddr_in self;

    /// The collection of clients (network side)
    struct peers_head peers_head;

    /// The collection of users (application side)
    struct users_head users_head;

    /// The collection of file descriptor set that are ready to be read
    fd_set read_fds;

    /// The collection of file descriptor set that are ready to be written
    fd_set write_fds;

    /// The collection of errored file descriptor set
    fd_set err_fds;

    /// Sockets to be removed after read failed
    /// sockets_to_be_removed[i] == true if the socket at index <b>i</b> is
    ///to be removed
    int sockets_to_be_removed[FD_SETSIZE];

    /// The state of the server
    /// true == running / false == stopped
    bool state;

    /// Arbitrary data to be stored inside the server
    void *arbitrary_data;
} tcp_server_t;


/// \brief DO NOT USE THIS FUNCTION, USE THE `TEAMS_LOG` MACRO INSTEAD
static inline void log_error(int line,
    const char *file,
    const char *func,
    const char *msg)
{
    printf("%s:%d:%s():\n%s: %s\n", file, line, func, msg, strerror(errno));
}

    /// \brief Simple macro used to log a message
    #define TEAMS_LOG(msg) \
        do {log_error(__LINE__, __FILE__, __func__, msg);} while (0)

/// \brief Creates a new client
/// \param sock_fd The client file descriptor
/// \param peer_addr The client address informations
peer_t *new_peer(int fd, struct sockaddr_in addr);

/// \brief remove a peer from the collection of peers
/// \param peers the head of the collection of peers created with CIRCLEQ_INIT
/// \param tbr to be removed peers with <b>tbr[peer->sock_fd] == 1</b>
void remove_unused_sockets(struct peers_head *peers, int tbr[FD_SETSIZE]);


/// \brief Util function to display currently connected clients
void display_clients(struct peers_head *peers_head);

/// \brief Create a TCP server
/// \param port Port to listen on
tcp_server_t *create_tcp_server(long port);

/// \brief Add a user to the server.
/// \param srv The server to add the user to.
/// \param username The username of the user to add.
/// \param password The password of the user to add.
/// \warning The password is inserted 'as is' inside the server
bool add_user_to_server(tcp_server_t *srv, char *username, char *password);

/// \brief Update the read and write fd sets according to
/// peer_t::pending_command of every peers connected
/// \param srv The tcp server containing the peers and the w/r/err fd sets
void server_fill_fd_sets(tcp_server_t *srv);

/// \brief Wait for a client update
/// \note This function is a wrapper around select()
/// \param src The tcp server containing the peers and the w/r/err fd sets
int server_wait(tcp_server_t *srv);

/// \brief Handle a client update
/// \param srv The tcp server containing the peers and the w/r/err fd sets
void server_manage_fd_update(tcp_server_t *srv);

#endif //NET_UTILS_H
