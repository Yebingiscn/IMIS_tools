@echo off
echo ----����GarfieldJiang��ר�����Զ���ȡIP��ַ�������ļ�---
echo -----http://hi.csdn.net/jiangzhanchang------------------
echo --------------------------------------------------------
echo ���������Զ����IP��ַ�����Ե�......
netsh interface ipv4 set address name="��������" source=dhcp
:	���ϴ�������IP��ַ�Զ���ȡ
netsh interface ipv4 set dns name="��������" source=dhcp
:   ���ϴ�������DNS�Զ���ȡ
:   ���ϼ��д����еġ��������ӡ��ɸ�����Ҫ�޸�Ϊ�����ģ����硰�����������ӡ�
if %errorlevel%==0 (
    netsh interface ipv4  show ip   
    echo ----���óɹ���----
    pause
    echo ----------���س����򿪼���-------------------
    start /d "E:" sogou_pinyin_105a.exe     :ͨ�����������Ӧ��
    EXIT   spa
) 
: start /d "D:\software\redis"  redis-server.exe
else (
    echo ---------------------���ִ���-----------------
    echo ������룺%ERRORLEVEL%&echo ����Ҽ�ѡ��ʹ�ù���Ա���С�
    echo ---------------------------------------------------
    pause
)


