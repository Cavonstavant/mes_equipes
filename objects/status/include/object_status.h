/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_status
*/

/// \file objects/status/include/object_status.h

#ifndef OBJECT_STATUS_H_
    #define OBJECT_STATUS_H_

    #include <stdbool.h>

    ///
    /// \brief possible value of the status object
    ///
    #define ONLINE true

    ///
    /// \brief possible value of the status object
    ///
    #define OFFLINE false

///
/// \brief Status object equivalent of a bool
///
///
typedef bool status_t;

///
/// \brief Init a status object
/// Default value is set to OFFLINE
///
/// \return status_t The newly created status object
///
status_t status_init(void);

#endif /* !OBJECT_STATUS_H_ */
