/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:51:47 by Xifeng            #+#    #+#             */
/*   Updated: 2025/01/29 19:34:27 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

// @brief The constructor of a fixed length message queue.
//
// @param capacity: capacity of the mq. Note for a fixed length mq,
// the data will be overwrited when the mq is full.
// @return the pointer to the message queue. will return NULL on error.
t_mq	*create_mq(int capacity)
{
	t_mq	*mq;

	mq = malloc(sizeof(t_mq));
	if (!mq)
		return (NULL);
	if (pthread_mutex_init(&(mq->lock), NULL))
		return (close_mq(&mq, false));
	mq->capacity = capacity;
	mq->write = 0;
	mq->read = 0;
	mq->is_closed = false;
	mq->ts = malloc(capacity * sizeof(long long));
	if (!mq->ts)
		return (close_mq(&mq, true));
	mq->events = malloc(capacity * sizeof(int));
	if (!mq->events)
		return (close_mq(&mq, true));
	mq->ids = malloc(capacity * sizeof(int));
	if (!mq->ids)
		return (close_mq(&mq, true));
	return (mq);
}

// @brief Returns the size of a message queue.
// Caution: Be sure you have a valid mq, and hold the lock before call it.
//
// @param mq: the pointer of message queue, should not be NULL.
static int	size_of_mq(t_mq *mq)
{
	int	diff;

	diff = mq->write - mq->read;
	if (diff >= 0)
		return (diff);
	return (mq->capacity + diff);
}

// @brief Send a message to message queue (thread safe).
//
// @param mq: the pointer to message queue.
// @param ts: the timestamp of a message.
// @param id: the philo's id of a message.
// @param event: the event of a message.
// @return false on error or mq is closed, otherwise returns true.
bool	send_message(t_mq *mq, long long ts, int id, int event)
{
	if (!mq || pthread_mutex_lock(&(mq->lock)) != 0)
		return (false);
	if (mq->is_closed)
	{
		pthread_mutex_unlock(&(mq->lock));
		return (false);
	}
	mq->ts[mq->write] = ts;
	mq->events[mq->write] = event;
	mq->ids[mq->write] = id;
	mq->write = (mq->write + 1) % mq->capacity;
	pthread_mutex_unlock(&(mq->lock));
	return (true);
}

// @brief A helper function for print_message.
// Please Note the caller should hold a lock.
//
// @param mq: the pointer to mq.
// @return: false if there is a "Dead" philo, otherwise returns true.
static bool	print_message_helper(t_mq *mq)
{
	int	i;
	int	id;

	i = 0;
	while (i < size_of_mq(mq))
	{
		id = (i + mq->read) % mq->capacity;
		if (mq->events[id] == GET_FORK)
			printf("%lld %d %s\n", mq->ts[id], mq->ids[id] + 1,
				"has taken a fork");
		else if (mq->events[id] == EATING)
			printf("%lld %d %s\n", mq->ts[id], mq->ids[id] + 1, "is eating");
		else if (mq->events[id] == SLEEPING)
			printf("%lld %d %s\n", mq->ts[id], mq->ids[id] + 1, "is sleeping");
		else if (mq->events[id] == THINKING)
			printf("%lld %d %s\n", mq->ts[id], mq->ids[id] + 1, "is thinking");
		else if (mq->events[id] == DEAD)
		{
			printf("%lld %d %s\n", mq->ts[id], mq->ids[id] + 1, "is died");
			mq->is_closed = true;
			return (false);
		}
        ++i;
	}
	return (true);
}

// @brief Print the messages from message queue (thread safe).
//
// @param mq: the pointer to message queue.
// @return false on error or mq is closed, otherwise returns true.
bool	print_message(t_mq *mq)
{
	if (!mq || pthread_mutex_lock(&(mq->lock)) != 0)
		return (false);
	if (mq->is_closed || !print_message_helper(mq))
	{
		pthread_mutex_unlock(&(mq->lock));
		return (false);
	}
	mq->read = (size_of_mq(mq) + mq->read) % mq->capacity;
	pthread_mutex_unlock(&(mq->lock));
	return (true);
}
