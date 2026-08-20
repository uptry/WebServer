#ifndef LOCKER_H
#define LOCKER_H

#include <exception>
#include <pthread.h>
#include <semaphore.h>

//信号量
class sem{
public:
    sem(){
<<<<<<< HEAD
        if(sem_init(&m_sem,0,0) != 0)
=======
        if(sem_init(&m_sem,0,0) ! = 0)
>>>>>>> be9da2acf650beedc3a9b9446c829a5442710b6c
            throw std::exception();
    }
    sem(int num){
        if (sem_init(&m_sem,0,num)  != 0)
            throw std::exception();
    }
    ~sem(){
        sem_destroy(&m_sem);
    }//析构自动销毁
    bool wait(){
        return sem_wait(&m_sem) == 0;
    }//P操作：减一，为0则堵塞
    bool post(){
        return sem_post(&m_sem) == 0;
    }//V操作：加一，唤醒等待的线程
private:
    sem_t  m_sem;
};
//互斥锁
class locker{
    public:
        locker(){
<<<<<<< HEAD
            if (pthread_mutex_init(&m_mutex,NULL) != 0)
=======
            if (pthread_mutex_init(&m_murex,NULL) ! = 0)
>>>>>>> be9da2acf650beedc3a9b9446c829a5442710b6c
                throw std::exception();
        }
        ~locker(){
            pthread_mutex_destroy(&m_mutex);
        }
        bool lock(){
            return pthread_mutex_lock(&m_mutex) == 0;
        }
        bool unlock(){
            return pthread_mutex_unlock(&m_mutex) == 0;
        }
        pthread_mutex_t *get(){
            return &m_mutex;
        }
        private:
            pthread_mutex_t m_mutex;
};
//条件变量
class cond{
    public:
        cond(){
            if (pthread_cond_init(&m_cond,NULL) != 0){
                throw std::exception();
            }
<<<<<<< HEAD
        }
        ~cond(){
                pthread_cond_destroy(&m_cond);
            }//等待
        bool timewait(pthread_mutex_t *m_mutex,struct timespec t){
            return pthread_cond_timedwait(&m_cond,m_mutex,&t) == 0;
=======
            ~cond(){
                pthread_cond_destroy(&m_cond);
            }//等待
        }
        bool timewait(pthread_mutex_t *m_mutex,struct timespec t){
            return pthread_cond_timewait(&m_cond,m_mutex,&t) == 0;
>>>>>>> be9da2acf650beedc3a9b9446c829a5442710b6c
        }
        bool signal(){
            return pthread_cond_signal(&m_cond) == 0;
        }//唤醒一个等待线程
        bool broadcast(){
            return pthread_cond_broadcast(&m_cond) == 0;
        }//唤醒所有等待线程
        private:
            pthread_cond_t m_cond;
};
#endif
