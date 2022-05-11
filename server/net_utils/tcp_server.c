/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** tcp_server
*/

#include "net_utils.h"

static void bind_and_listen_on_socket(tcp_server_t *srv, long port)
{
    srv->sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (srv->sock_fd < 0)
        HANDLE_ERROR("socket");
    bzero(&srv->self, sizeof(srv->self));
    srv->self.sin_family = AF_INET;
    srv->self.sin_port = htons(port);
    srv->self.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(srv->sock_fd, (struct sockaddr *) &srv->self,
        sizeof(struct sockaddr)) < 0)
        HANDLE_ERROR("bind");
    if (listen(srv->sock_fd, LISTEN_BACKLOG) < 0)
        HANDLE_ERROR("listen");
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
        HANDLE_ERROR("malloc");
    server->port = htons(port);
    bind_and_listen_on_socket(server, port);
    FD_ZERO(&server->read_fds);
    FD_ZERO(&server->write_fds);
    FD_SET(server->sock_fd, &server->read_fds);
    FD_SET(server->sock_fd, &server->write_fds);
    CIRCLEQ_INIT(&server->peers_head);
    CIRCLEQ_INIT(&server->users_head);
    memset(server->sockets_to_be_removed, 0,
        sizeof(server->sockets_to_be_removed));
    server->state = true;
    return (server);
}
