/*
** EPITECH PROJECT, 2022
** Project
** File description:
** upper_component_adding
*/

/// \file objects/wrapper/include/upper_component_adding.h

#ifndef UPPER_COMPONENT_ADDING_H_
    #define UPPER_COMPONENT_ADDING_H_

    #include "object_wrapper.h"
    #include <stdlib.h>

    /// \brief Return when a component adding failed
    #define COMPONENT_ERROR false
    /// \brief Return when a component adding success
    #define COMPONENT_SUCCESS true

/// \brief Create and add a new User object to Wrapper
/// \param wrapper Wrapper instance
/// \param content Content of the new User
/// \return true Operation Sucess
/// \return false Operation Failed
bool wrapper_adding_user(object_wrapper_t *wrapper, user_creation_t content);

/// \brief Create and add a new Team object to Wrapper
/// \param wrapper Wrapper instance
/// \param content Content of the new Team
/// \return true Operation Sucess
/// \return false Operation Failed
bool wrapper_adding_team(object_wrapper_t *wrapper, team_creation_t content);

/// \brief Create and add a new Conversation object to Wrapper
/// \param wrapper Wrapper instance
/// \param content Content of the new Conversation
/// \return true Operation Sucess
/// \return false Operation Failed
bool wrapper_adding_conversation(object_wrapper_t *wrapper,
conversation_creation_t content);

/// \brief Create and add a new Thread object to Wrapper
/// \param wrapper Wrapper instance
/// \param content Content of the new Thread
/// \return true Operation Sucess
/// \return false Operation Failed
bool wrapper_adding_thread(object_wrapper_t *wrapper,
thread_creation_t content);

/// \brief Create and add a new Channel object to Wrapper
/// \param wrapper Wrapper instance
/// \param content Content of the new Channel
/// \return true Operation Sucess
/// \return false Operation Failed
bool wrapper_adding_channel(object_wrapper_t *wrapper,
channel_creation_t content);

#endif /* !UPPER_COMPONENT_ADDING_H_ */
