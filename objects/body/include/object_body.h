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

    #define BODY_SIZE 512
    #define BODY_ERROR NULL
    #define BODY_INVALID_SIZE "Invalid content size."

///
/// \brief Body object equivalent of a string
///
///
typedef char *body_t;

///
/// \brief Init the Body object
/// If the body_content is too long compared to BODY_SIZE, return BODY_ERROR
///
/// \param body_content Content of the new body object
/// \return body_t The newly created body object
///
body_t body_init(char *body_content);

#endif /* !OBJECT_BODY_H_ */
