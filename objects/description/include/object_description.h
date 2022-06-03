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

    /// \brief Error inside a Description object
    #define DESCRIPTION_ERROR NULL

    /// \brief Max description size
    #define DESCRIPTION_SIZE 255

    /// \brief Description error message for a bad size
    #define DESCRIPTION_INVALID_SIZE "Invalid Description size."

/// \brief Description object equivalent of a string
typedef char *description_t;

/// \brief Init the description object
/// \param description_content Content of the new Description object
/// \return description_t Newly created Description object
/// If the description_content is too long compared to description_size
/// return DESCRIPTION_ERROR
description_t description_init(char *description_content);

/// \brief Destroy the description object
/// If the description_to_destroy is equivalent to DESCRIPTION_ERROR do nothing
/// \param description_to_destroy Description object to destroy
void description_destroy(description_t description_to_destroy);

/// \brief Dump a description object
/// \param desc Description object to dump
void description_dump(description_t desc);

/// \brief Edit the content of a description object
/// \param desc Description object to edit
/// \param content Content to edit into the Description object
void description_edit_content(description_t desc, char *content);

#endif /* !OBJECT_DESCRIPTION_H_ */
