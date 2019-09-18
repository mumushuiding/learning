# vscode 配置 C++ 运行环境

## 安装 C/C++ for Visual Studio Code 扩展

打开 vscode 搜索扩展并安装 

## 安装 Mingw-w64
  * 1) 下载 http://mingw-w64.org/doku.php/download/mingw-builds
  * 2) 建议安装在 C:\mingw-w64 目录下
  * 3) 将mingw-w64的bin目录添加至环境变量

## 创建 workspace

$ mkdir workspace
$ cd workspace
$ mkdir helloworld
$ cd helloworld
$ code .

## 创建编译路径 

1. 按下 Ctrl + Shift + P 搜索 C, 选择 Edit Configurations (UI)

<img src="./img/vscode 配置编译路径.png">

2. 找到 Compiler path 配置项，修改成 C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe

3. 设置 IntelliSense mode 为 gcc-x64

4. 当 header 文件不在你的 workspace 和 标准库时，可以设置 Include path 

至此，基本能用了。编写一个helloworld测试一下

```
#include<iostream>
int main()
{
  std::cout<<"hello world!";
}
```

编译 $ g++ hello.cpp
执行 $ *.exe

## 创建一个 build task

接下来，创建一个 tasks.json 文件告诉 vscode 如何将程序编译成可执行文件。

1. 打开 View > Command Palete, 并选择 Configure Default Build Task,在下拉框中选择 Others. VS Code 创建了一个最小的 tasks.json.
2. 使用以下内容替代 tasks.json 中的内容

```
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build hello world",
      "type": "shell",
      "command": "g++",
      "args": ["-g", "-o", "helloworld", "helloworld.cpp"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
```

label: 是 VScode Command Palette 中可以看到的。
isDefault: 当按下 Ctrl + Shift + B 时 task 会运行。

## 配置 debug 

接下来，我们要配置 VS Code 启动 GCC debugger 选项当你按下 F5 时

1. 打开 View > Command Palete，键入 launch, 选择 Debug: Open launch.json。再选择 GDP/LLDB 环境
2. 对于 program, 使用程序名 helloworld.exe (同tasks.json文件中定义的相匹配)
3. 修改 miDebuggerPath 为 "C:\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\gdb.exe"

按下 F5 测试
