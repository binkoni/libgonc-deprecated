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

#ifndef _GONC_SINGLY_LINKED_NODE_H
#define _GONC_SINGLY_LINKED_NODE_H

/**
* @file gonc_singly_linked_node.h
* @author Byeonggon Lee
* @brief This file contains struct gonc_singly_linked_node.
*/

/**
* @brief A singly linked node.
* A singly linked node which has only next pointer.
* This struct is used by gonc_queue.
*/

struct gonc_singly_linked_node
{
    void* data; /**< pointer of data. */
    struct gonc_singly_linked_node* next; /**< pointer of next node. */
};

#endif
