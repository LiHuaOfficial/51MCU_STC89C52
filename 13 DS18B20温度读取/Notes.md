## 1-wire单总线协议
+ ROM指令
  + 适用于接有多个设备的情形 
  + 每个设备有唯一识别码，可以通过读rom指令或者搜索rom指令查找之
  并提供匹配rom指令找到对应设备并执行功能指令（开发版上只有一个从机所以直接使用跳过rom指令
+ 时序图
  +  ![image](https://user-images.githubusercontent.com/120998712/215387480-895c9a4e-79ad-47c6-b2e8-e42bd4601256.png)
  +  ![image](https://user-images.githubusercontent.com/120998712/215387511-2993c230-4108-433c-95dd-14a2d09c1710.png)

## DS18B20
+ 功能指令
  + >![image](https://user-images.githubusercontent.com/120998712/215388095-cf704763-a4f9-437d-a364-fb904241fc3c.png)
  + 读数据时前两个为温度
  + ![DS18B20温度格式](https://user-images.githubusercontent.com/120998712/215388328-2a369b5a-666a-450b-b2fe-dd1c02c928d1.png)
