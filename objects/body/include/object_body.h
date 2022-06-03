/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_body
*/

/// \file objects/body/include/object_body.h

#ifndef OBJECT_BODY_H_
    #define OBJECT_BODY_H_

    #include <stddef.h>

    /// \brief Max size of a body object
    #define BODY_SIZE 512

    /// \brief Error inside a body object
    #define BODY_ERROR NULL

    /// \brief Body error message for bad size
    #define BODY_INVALID_SIZE "Invalid content size."

/// \brief Body object equivalent of a string
typedef char *body_t;

/// \brief Init a Body object
/// \param body_content Content of the new body object
/// \return body_t The newly created body object
/// If the body_content is too long compared to BODY_SIZE, return BODY_ERROR
body_t body_init(char *body_content);

/// \brief Destroy a Body object
/// If the body_to_destroy is BODY_ERROR, do nothing
/// \param body_to_destroy Body object to destroy
void body_destroy(body_t body_to_destroy);

/// \brief Dump a body object
/// \param body Body object to print
void body_dump(body_t body);

/// \brief Edit the content of a body object
/// \param body Body object to edit
/// \param body_content Content to replace into body object
void body_edit_content(body_t body, char *body_content);

#endif /* !OBJECT_BODY_H_ */
