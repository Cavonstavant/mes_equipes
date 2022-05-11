/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_description
*/

/// \file objects/description/include/object_description.h

#ifndef OBJECT_DESCRIPTION_H_
    #define OBJECT_DESCRIPTION_H_

    #include <stddef.h>

    ///
    /// \brief Error inside a Description object
    ///
    #define DESCRIPTION_ERROR NULL

    ///
    /// \brief Max description size
    ///
    #define DESCRIPTION_SIZE 255

    ///
    /// \brief Description error message for a bad size
    ///
    #define DESCRIPTION_INVALID_SIZE "Invalid Description size."

///
/// \brief Description object equivalent of a string
///
///
typedef char *description_t;

///
/// \brief Init the description object
/// If the description_content is too long compared to description_size
/// return DESCRIPTION_ERROR
///
/// \param description_content Content of the new Description object
/// \return description_t Newly created Description object
///
description_t description_init(char *description_content);

#endif /* !OBJECT_DESCRIPTION_H_ */
