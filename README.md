# TinyWebServer
本项目在 Linux 下从零实现一个轻量级、高并发的 Web 服务器:基于 epoll(ET) 事件驱动 + 线程池的 Reactor 模型,用状态机解析 HTTP 请求,支持返回静态页面、用户注册/登录,并具备定时器、连接池、异步日志等生产级组件。目标是彻底吃透高并发服务器背后的网络、操作系统与并发原理。
## 🙏 致谢

本项目在设计思路上参考了 [TinyWebServer](https://github.com/qinguoyi/TinyWebServer) 与 [markparticle/WebServer](https://github.com/markparticle/WebServer),定时器、日志等模块为自己的实现。感谢开源社区。

## 📄 License

[MIT](./LICENSE) © 2026 <你的名字>
