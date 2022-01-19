## boost-cmake-learn
boost学习记录

## 开发环境搭建 
[boost官网](https://www.boost.org/) 推荐版本1.58.0   
[protobuf官网](https://developers.google.com/protocol-buffers)  推荐版本3.4.1  


### macos
```
brew install boost protobuf@3.6
```

安装完成之后，需要把protobuf添加到环境变量中
If you need to have protobuf@3.6 first in your PATH, run:
echo 'export PATH="/usr/local/opt/protobuf@3.6/bin:$PATH"' >> ~/.zshrc

> 下载不同的protobuf版本，需要重新生成proto文件`addressbook.pb.cc和addressbook.pb.h`  
> `protoc --cpp_out=.  addressbook.proto `  
> [官方说明](https://developers.google.com/protocol-buffers/docs/cpptutorial)  

### linux


## 模块说明

