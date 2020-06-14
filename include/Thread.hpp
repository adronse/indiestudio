/*
** EPITECH PROJECT, 2020
** OOP_indie_2019
** File description:
** Thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <pthread.h>

class IThread {
    public:
	    virtual ~IThread() {}
	    virtual void run() = 0;
};

class Thread : public IThread{
    public:
        Thread();
        ~Thread();
        virtual void launchThread();
	    virtual void stopThread();
        static void * execute(void *object);
    protected:
    private:
    	pthread_t thread;
};

#endif /* !THREAD_HPP_ */
