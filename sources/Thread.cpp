/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Thread
*/

#include "Thread.hpp"
#include <iostream>

Thread::Thread()
{

}

Thread::~Thread()
{

}

void Thread::launchThread()
{
	if (pthread_create(&this->thread, NULL, Thread::execute, (void *)this)) {
		std::cout << "thread create failed" << std::endl;
	}
}

void Thread::stopThread()
{
	if (pthread_cancel(this->thread) != 0) {
		std::cout << "thread destroy failed" << std::endl;
    }
}

void *Thread::execute(void *object)
{
	IThread *self = reinterpret_cast<IThread *>(object);
	self->run();
	return (NULL);
}