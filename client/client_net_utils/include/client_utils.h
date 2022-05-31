/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** include_utils
*/

/// \file client/client_net_utils/include/client_utils.h

#ifndef INCLUDE_UTILS_H
    #define INCLUDE_UTILS_H

    #include <sys/socket.h>
    #include <sys/select.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/queue.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>

    /// Defines the maximum size of a message
    #define MAX_MSG 55555

/// \brief Represents a distant server to connect to
typedef struct server_s {

    /// The address of the client
    int sock_fd;

    /// The address of the server
    struct sockaddr_in srv_addr;

    /// Status of the server (true: connected, false: disconnected)
    bool connected;

    /// Indicates to the wrapper that the server has received a message
    bool pending_read;

    /// Indicates to the wrapper that the client is currently sending a message
    bool pending_write;

    /// The buffer to read from the server
    char input_buffer[MAX_MSG];

    /// The buffer to write to the server
    char output_buffer[MAX_MSG];

    /// The fd set containing the sock fd of the mes_équipe server
    fd_set read_fds;

    /// The fd set containing the sock fd of the mes_équipe server
    fd_set write_fds;

    /// The fd set containing the sock fd of the mes_équipe server
    fd_set err_fds;

    /// Runs a connected client by sending and
    /// receiving messages to the associated server
    int (*run)(struct server_s *);

    /// Stop a connected client and destroy all associated ressources
    void (*stop)(struct server_s *);
} client_net_server_t;

static inline void __log_error(int line,
    const char *file,
    const char *func,
    const char *msg)
{
    printf("%s:%d:%s():\n\t%s: %s\n", file, line, func, msg, strerror(errno));
}

    /// \brief Simple macro used to log a message
    #define TEAMS_LOG(msg) \
        do {__log_error(__LINE__, \
strrchr(__FILE__, '/') + 1, __func__, msg);} while (0)

/// \brief Create a new mes_équipes TM. server object to connect to
/// \param ip The dotted, null terminated string repr. of the server ip
/// \param port The port to connect the mes_équipes client to
/// \return A pointer to the mes_équipes TM. server object or
/// NULL if the instanciation as failed
client_net_server_t *create_net_server(const char *ip, long port);

/// \brief Send a message to the mes_équipes server conforming to RFC
/// \param server The server to the message to
/// \param msg the null terminated, RFC conformed message
/// \return true if the message was sent, false otherwise
bool send_message(client_net_server_t *server, const char *msg);

/// \brief Retrieve the last message recieved from the server
char *fetch_message(client_net_server_t *server);

/// \brief Update the mes_équipes client by sending and receiving messages
void update_client(client_net_server_t *server);

#endif /* INCLUDE_UTILS_H */
