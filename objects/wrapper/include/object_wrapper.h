/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_wrapper
*/

/// \file objects/wrapper/include/object_wrapper.h

#ifndef OBJECT_WRAPPER_H_
    #define OBJECT_WRAPPER_H_

    #include "object_channel.h"
    #include "object_comment.h"
    #include "object_conversation.h"
    #include "object_description.h"
    #include "object_message.h"
    #include "object_team.h"
    #include "object_thread.h"
    #include "object_user.h"
    #include <stddef.h>

    ///
    /// \brief Error inside a Wrapper object
    ///
    #define WRAPPER_ERROR NULL

    ///
    /// \brief Return value when no matching object is find
    ///
    #define OBJECT_NOT_FOUND NULL

    ///
    /// \brief Return value when the operation succeed
    ///
    #define OPERATION_SUCCEED true

    ///
    /// \brief Return value when the operation failed
    ///
    #define OPERATION_FAILED false

///
/// \brief Wrapper object, containing all Objects instance
///
typedef struct object_wrapper_s {
    /// List of all the channel
    channel_t **channels;
    /// Number of channels
    int channel_n;
    /// List of all the comment
    comment_t **comments;
    /// Number of comments
    int comment_n;
    /// List of all the conversation
    conversation_t **conversations;
    /// Number of conversations
    int conversation_n;
    /// List of all the message
    message_t **messages;
    /// Number of messages
    int message_n;
    /// List of all the team
    team_t **teams;
    /// Number of teams
    int team_n;
    /// List of all the thread
    thread_t **threads;
    /// Number of threads
    int thread_n;
    /// List of all the user
    user_t **users;
    /// Number of users
    int user_n;
} object_wrapper_t;

///
/// \brief Child list object containing all informations about a child list
///
typedef struct child_list_s {
    /// List of uuid_t
    my_uuid_t **list;
    /// Size of the list 
    int size;
} child_list_t;

///
/// \brief Create a new wrapper object
/// Init all the object lists
///
/// \return object_wrapper_t* Newly created wrapper
///
object_wrapper_t *wrapper_init(void);

///
/// \brief Destroy a wrapper object
/// If the wrapper object is WRAPPER_ERROR, do nothing
///
/// \param wrapper Wrapper object to destroy
///
void wrapper_destroy(object_wrapper_t *wrapper);

///
/// \brief Dump all object in the wrapper
///
/// \param wrapper Wraper object to print
///
void wrapper_dump(object_wrapper_t *wrapper);

///
/// \brief Cross all the channels list and try to find a matching channel
///
/// \param wrapper Wrapper object
/// \param find Uuid to match in the list
/// \return channel_t* Return an instance of the matching object
/// Return OBJECT_TO_FIND when no matching object is find
///
channel_t *wrapper_find_channel(object_wrapper_t *wrapper, my_uuid_t *find);

///
/// \brief Cross all the users list and try to find a matching user
///
/// \param wrapper Wrapper object
/// \param find Uuid to match in the list
/// \return user_t* Return an instance of the matching object
/// Return OBJECT_TO_FIND when no matching object is find
///
user_t *wrapper_find_user(object_wrapper_t *wrapper, my_uuid_t *find);

///
/// \brief Cross all the teams list and try to find a matching team
///
/// \param wrapper Wrapper object
/// \param find Uuid to match in the list
/// \return team_t* Return an instance of the matching object
/// Return OBJECT_TO_FIND when no matching object is find
///
team_t *wrapper_find_team(object_wrapper_t *wrapper, my_uuid_t *find);

///
/// \brief Cross all the conversations list and try to find
/// a matching conversation
///
/// \param wrapper Wrapper object
/// \param find Uuid to match in the list
/// \return conversation_t* Return an instance of the matching object
/// Return OBJECT_TO_FIND when no matching object is find
///
conversation_t *wrapper_find_conversation(object_wrapper_t *wrapper,
my_uuid_t *find);

///
/// \brief Cross all the threads list and try to find a matching thread
///
/// \param wrapper Wrapper object
/// \param find Uuid to match in the list
/// \return thread_t* Return an instance of the matching object
/// Return OBJECT_TO_FIND when no matching object is find
///
thread_t *wrapper_find_thread(object_wrapper_t *wrapper, my_uuid_t *find);

///
/// \brief Cross all the messages list and try to find a matching message
///
/// \param wrapper Wrapper object
/// \param find Uuid to match in the list
/// \return message_t* Return an instance of the matching object
/// Return OBJECT_TO_FIND when no matching object is find
///
message_t *wrapper_find_message(object_wrapper_t *wrapper, my_uuid_t *find);

///
/// \brief Cross all the comments list and try to find a matching comment
///
/// \param wrapper Wrapper object
/// \param find Uuid to match in the list
/// \return comment_t* Return an instance of the matching object
/// Return OBJECT_TO_FIND when no matching object is find
///
comment_t *wrapper_find_comment(object_wrapper_t *wrapper, my_uuid_t *find);

///
/// \brief Create a new comment object and link it with an existing thread
///
/// \param wrapper Wrapper object
/// \param content Comment content 
/// \param thread_uuid Uuid thread to link
/// \return true Operation succeed
/// \return false Operation failed
///
bool wrapper_new_comment_to_thread(object_wrapper_t *wrapper,
comment_creation_t content, my_uuid_t *thread_uuid);

///
/// \brief Create a new thread object and link it with an existing channel
///
/// \param wrapper Wrapper object
/// \param content Thread content 
/// \param channel_uuid Uuid channel to link
/// \return true Operation succeed
/// \return false Operation failed
///
bool wrapper_new_thread_to_channel(object_wrapper_t *wrapper,
thread_creation_t content, my_uuid_t *channel_uuid);

///
/// \brief Create a new channel object and link it with an existing team
///
/// \param wrapper Wrapper object
/// \param content Channel content 
/// \param team_uuid Uuid team to link
/// \return true Operation succeed
/// \return false Operation failed
///
bool wrapper_new_channel_to_team(object_wrapper_t *wrapper,
channel_creation_t content, my_uuid_t *team_uuid);

///
/// \brief Create a new Conversation object and link it with two existing user
///
/// \param wrapper Wrapper object
/// \param content Conversation content
/// \param first_uuid First uuid user to link
/// \param second_uuid Second uuid user to link
/// \return true Operation succeed
/// \return false Operation failed
///
bool wrapper_new_conversation_to_user(object_wrapper_t *wrapper,
conversation_creation_t content, my_uuid_t *first_uuid,
my_uuid_t *second_uuid);

///
/// \brief Create a new message object and link it with an existing conv
///
/// \param wrapper Wrapper object
/// \param content Message content 
/// \param team_uuid Uuid conv to link
/// \return true Operation succeed
/// \return false Operation failed
///
bool wrapper_new_message_to_conversation(object_wrapper_t *wrapper,
message_creation_t content, my_uuid_t *conv_uuid);

///
/// \brief Add a user into a conversation
///
/// \param wrapper Wrapper object
/// \param user_uuid User uuid
/// \param conversation_uuid Conversation uuid
/// \return true Operation succeed
/// \return false Operation failed
///
bool wrapper_user_join_conversation(object_wrapper_t *wrapper,
my_uuid_t *user_uuid, my_uuid_t *conversation_uuid);

///
/// \brief Add a user into a team
///
/// \param wrapper Wrapper object
/// \param user_uuid User uuid
/// \param team_uuid Team uuid
/// \return true Operation succeed
/// \return false Operation failed
///
bool wrapper_user_join_team(object_wrapper_t *wrapper,
my_uuid_t *user_uuid, my_uuid_t *team_uuid);

///
/// \brief Remove a user from a team
///
/// \param wrapper Wrapper object
/// \param user_uuid User uuid
/// \param team_uuid Team uuid
/// \return true Operation succeed
/// \return false Operation failed
///
bool wrapper_user_leave_team(object_wrapper_t *wrapper,
my_uuid_t *user_uuid, my_uuid_t *team_uuid);

///
/// \brief Find a matching channel by his name inside the wrapper list
///
/// \param wrapper Wrapper object
/// \param name Name to match
/// \return my_uuid_t* Uuid of the founded object, NULL otherwise
///
my_uuid_t *find_channel_by_name(object_wrapper_t *wrapper, char *name);

///
/// \brief Find a matching team by his name inside the wrapper list
///
/// \param wrapper Wrapper object
/// \param name Name to match
/// \return my_uuid_t* Uuid of the founded object, NULL otherwise
///
my_uuid_t *find_team_by_name(object_wrapper_t *wrapper, char *name);

///
/// \brief Find a matching thread by his name inside the wrapper list
///
/// \param wrapper Wrapper object
/// \param name Name to match
/// \return my_uuid_t* Uuid of the founded object, NULL otherwise
///
my_uuid_t *find_thread_by_name(object_wrapper_t *wrapper, char *name);

///
/// \brief Find a matching user by his name inside the wrapper list
///
/// \param wrapper Wrapper object
/// \param name Name to match
/// \return my_uuid_t* Uuid of the founded object, NULL otherwise
///
my_uuid_t *find_user_by_name(object_wrapper_t *wrapper, char *name);

///
/// \brief Get the channel child list
///
/// \param wrapper Wrapper object
/// \param channel_uuid Uuid of the channel
/// \return child_list_t Child_list object
///
child_list_t get_channel_child_list(object_wrapper_t *wrapper,
my_uuid_t *channel_uuid);

///
/// \brief Get the conversation child list
///
/// \param wrapper Wrapper object
/// \param conversation_uuid Uuid of the conversation
/// \return child_list_t Child_list object
///
child_list_t get_conversation_child_list(object_wrapper_t *wrapper,
my_uuid_t *conversation_uuid);

///
/// \brief Get the team child list
///
/// \param wrapper Wrapper object
/// \param team_uuid Uuid of the team
/// \return child_list_t Child_list object
///
child_list_t get_team_child_list(object_wrapper_t *wrapper,
my_uuid_t *team_uuid);

///
/// \brief Get the thread child list
///
/// \param wrapper Wrapper object
/// \param thread_uuid Uuid of the thread
/// \return child_list_t Child_list object
///
child_list_t get_thread_child_list(object_wrapper_t *wrapper,
my_uuid_t *thread_uuid);

///
/// \brief Get the subscribed team of user object
///
/// \param wrapper Wrapper object
/// \param user_uuid Uuid of the user
/// \return child_list_t List of the uuid team and his size
///
child_list_t get_subscribed_team_of_user(object_wrapper_t *wrapper,
my_uuid_t *user_uuid);

///
/// \brief Get the subscribed user of team object
///
/// \param wrapper Wrapper object
/// \param user_uuid Uuid of the team
/// \return child_list_t List of the uuid team and his size
///
child_list_t get_subscribed_user_of_team(object_wrapper_t *wrapper,
my_uuid_t *team_uuid);

///
/// \brief Tell if a user is sub to a team
///
/// \param wrapper Wrapper object
/// \param user_uuid Uuid of the user
/// \param team_uuid Uuid of the team
/// \return true If the user is sub
/// \return false If the user is not sub
///
bool user_is_sub_to_team(object_wrapper_t *wrapper,
my_uuid_t *user_uuid, my_uuid_t *team_uuid);

#endif /* !OBJECT_WRAPPER_H_ */
