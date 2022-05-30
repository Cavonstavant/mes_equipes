/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** tcp_server
*/

/// \file server/net_utils/tcp_server.c

#include "net_utils.h"

/// \brief just as the function name says
static bool bind_and_listen_on_socket(tcp_server_t *srv, long port)
{
    srv->sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (srv->sock_fd < 0){
        TEAMS_LOG("socket");
        return false;
    }
    memset(&srv->self, 0, sizeof(srv->self));
    srv->self.sin_family = AF_INET;
    srv->self.sin_port = htons(port);
    srv->self.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(srv->sock_fd, (struct sockaddr *) &srv->self,
        sizeof(struct sockaddr)) < 0){
        TEAMS_LOG("bind");
        return false;
    }
    if (listen(srv->sock_fd, LISTEN_BACKLOG) < 0) {
        TEAMS_LOG("listen");
        return false;
    }
    return true;
}

bool add_user_to_server(tcp_server_t *srv, char *username, char *password)
{
    user_t *new_user = NULL;

    new_user = create_user(username, password);
    if (new_user == NULL)
        return (false);
    CIRCLEQ_INSERT_HEAD(&srv->users_head, new_user, users);
    return (true);
}

tcp_server_t *create_tcp_server(long port)
{
    tcp_server_t *server = malloc(sizeof(tcp_server_t));

    if (!server)
        TEAMS_LOG("malloc");
    server->port = htons(port);
    if (!bind_and_listen_on_socket(server, port)) {
        free(server);
        return (NULL);
    }
    FD_ZERO(&server->read_fds);
    FD_ZERO(&server->write_fds);
    FD_ZERO(&server->err_fds);
    FD_SET(server->sock_fd, &server->read_fds);
    FD_SET(server->sock_fd, &server->write_fds);
    CIRCLEQ_INIT(&server->peers_head);
    CIRCLEQ_INIT(&server->users_head);
    server->state = true;
    return (server);
}
