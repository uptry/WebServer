#ifndef EPOLL_UTIL_H
#define EPOLL_UTIL_H

#include <sys/epoll.h>
#include <fcntl.h>
#include <unistd.h>

//将文件描述符设置为非阻塞
inline int setnonblocking(int fd){
    int old_flags = fcntl(fd,F_GETFL);
    if (old_flags == -1){
        return -1;
    }
    if (fcntl(fd,F_SETFL,old_flags | O_NONBLOCK) == -1){
        return -1;
    }
    return old_flags;
}
//将fd添加到epoll
//one_shot:是否启用EPOLLONESHOT
//trig_mode:1表示ET，0表示LT
inline void addfd(int epollfd,int fd,bool one_shot,int trig_mode){
    epoll_event event{};
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLRDHUP;

    if(trig_mode == 1){
        event.events |= EPOLLET;
    }
    if(one_shot){
        event.events |= EPOLLONESHOT;
    }

    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
    setnonblocking(fd);
}
//从epoll 中删除并关闭fd
inline void removefd(int epollfd,int fd){
    epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,nullptr);
    close(fd);
}
//修改fd监听的事件
//使用EPOLLONESHOT后，处理完事件需要重新注册
inline void modfd(int epollfd,int fd,int events,int trig_mode){
    epoll_event event{};
    event.data.fd = fd;
    event.events = events | EPOLLONESHOT | EPOLLRDHUP;

    if(trig_mode== 1){
        event.events|= EPOLLET;
    }
    epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&event);
}

#endif