/*
** EPITECH PROJECT, 2022
** mon_FTP
** File description:
** fd_set_manage
*/

#include "net_utils.h"

void restore_fd_sets(fd_set *read_fds, fd_set *write_fds,
    fd_set *read_save, fd_set *write_save)
{
    FD_ZERO(read_fds);
    FD_ZERO(write_fds);
    *read_fds = *read_save;
    *write_fds = *write_save;
}