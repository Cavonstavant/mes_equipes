/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** server_accept_new_client
*/

#include "net_utils.h"

static peer_t *accept_client(tcp_server_t *srv)
{
    peer_t *new_client = NULL;
    int client_fd = 0;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);

    client_fd = accept(srv->sock_fd,
        (struct sockaddr *)&client_addr,
        &client_addr_size);
    if (client_fd < 0)
        HANDLE_ERROR("accept");
    new_client = new_peer(client_fd, client_addr);
    if (new_client == NULL)
        HANDLE_ERROR("peer_create");
    FD_SET(client_fd, &srv->read_fds);
    new_client->data = fill_client_data(srv->arbitrary_data);
    return (new_client);
}

static bool manage_new_conn(tcp_server_t *srv, fd_set *read_fs, peer_t *new)
{
    new = accept_client(srv);
    if (new == NULL){
        TEAMS_LOG("Internal Error: could not accept new client.\n");
        return (false);
    }
    CIRCLEQ_INSERT_HEAD(&srv->peers_head, new, peers);
    return (true);
}

bool server_accept_new_client(tcp_server_t *srv)
{
    peer_t *new = NULL;

    return (manage_new_conn(srv, &srv->read_fds, new));
}
