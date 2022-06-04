/*
** EPITECH PROJECT, 2022
** Project
** File description:
** lower_component_adding
*/

/// \file objects/wrapper/include/lower_component_adding.h

#ifndef LOWER_COMPONENT_ADDING_H_
    #define LOWER_COMPONENT_ADDING_H_

    #include "object_wrapper.h"
    #include <stdlib.h>

    /// \brief Return when a component adding failed
    #define COMPONENT_ERROR false
    /// \brief Return when a component adding success
    #define COMPONENT_SUCCESS true

/// \brief Create and add a new Message object to Wrapper
/// \param wrapper Wrapper instance
/// \param content Content of the new Message
/// \return true Operation Sucess
/// \return false Operation Failed
bool wrapper_adding_message(object_wrapper_t *wrapper,
message_creation_t content);

/// \brief Create and add a new Comment object to Wrapper
/// \param wrapper Wrapper instance
/// \param content Content of the new Comment
/// \return true Operation Sucess
/// \return false Operation Failed
bool wrapper_adding_comment(object_wrapper_t *wrapper,
comment_creation_t content);

#endif /* !LOWER_COMPONENT_ADDING_H_ */
