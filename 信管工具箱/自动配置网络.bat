@echo off
echo ----来自GarfieldJiang的专栏的自动获取IP地址批处理文件---
echo -----http://hi.csdn.net/jiangzhanchang------------------
echo --------------------------------------------------------
echo 正在设置自动获得IP地址，请稍等......
netsh interface ipv4 set address name="本地连接" source=dhcp
:	以上代码设置IP地址自动获取
netsh interface ipv4 set dns name="本地连接" source=dhcp
:   以上代码设置DNS自动获取
:   以上几行代码中的“本地连接”可根据需要修改为其他的，比如“无线网络连接”
if %errorlevel%==0 (
    netsh interface ipv4  show ip   
    echo ----配置成功！----
    pause
    echo ----------按回车键打开继续-------------------
    start /d "E:" sogou_pinyin_105a.exe     :通过这个打开其他应用
    EXIT   spa
) 
: start /d "D:\software\redis"  redis-server.exe
else (
    echo ---------------------出现错误！-----------------
    echo 错误代码：%ERRORLEVEL%&echo 请点右键选择“使用管理员运行”
    echo ---------------------------------------------------
    pause
)


