/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_name
*/

/// \file objects/name/include/object_name.h

#ifndef OBJECT_NAME_H_
    #define OBJECT_NAME_H_

    #include <stddef.h>

    ///
    /// \brief Max size of a name object
    ///
    #define NAME_SIZE 32

    ///
    /// \brief Error inside a name object
    ///
    #define NAME_ERROR NULL

    ///
    /// \brief Name error message for bad size
    ///
    #define NAME_INVALID_SIZE "Invalid content size"

///
/// \brief Name object equivalent of a string
///
///
typedef char *name_t;

///
/// \brief Init a name object
///
/// \param name_content Content of the new name object
/// \return name_t The newly created name object
/// If the name_content is too long compared to NAME_SIZE, return NAME_ERROR
///
name_t name_init(char *name_content);

///
/// \brief Destroy a Name object
/// If the name_to_destroy is NAME_ERROR, do nothing
///
/// \param name_to_destroy Name object to destroy
///
void name_destroy(name_t name_to_destroy);

#endif /* !OBJECT_NAME_H_ */
