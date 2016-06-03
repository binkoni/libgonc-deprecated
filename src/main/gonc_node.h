/*
* Copyright (C) 2016  Byeonggon Lee <gonny952@gmail.com>
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Library General Public
* License as published by the Free Software Foundation; either
* version 3 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Library General Public License for more details.
*
* You should have received a copy of the GNU Library General Public
* License along with this library. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _GONC_NODE_H
#define _GONC_NODE_H

/**
* @file gonc_node.h
* @author Byeonggon Lee
* @brief This file contains struct gonc_node.
*/

/**
* @brief A doubly linked node.
* A doubly linked node which has previous and next pointer.
* This struct is used by gonc_stack and gonc_linked_list.
*/

struct gonc_node
{
    void* data; /**< pointer of data. */
    struct gonc_node* previous; /**< pointer of previous node. */
    struct gonc_node* next; /**< pointer of next node. */
};

#endif
