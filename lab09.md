# Lab09-“自顶向下”编程方法接受及洗衣机案例

### [“自顶向下”编程方法介绍](#1)
### [ 洗衣机算法设计](#2)

<h2 id="1">“自顶向下，逐步求精”的编程方法</h2>

![](https://img-blog.csdn.net/20171128165340567?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbGFhZ3l6eg==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

* **“自顶向下”**<br>
是将复杂、大的问题划分为小问题，找出问题的关键、重点所在，然后用精确的思维定性、定量地去描述问题。<br>
>具体方法:<br>
自顶向下的方法使问题结构化和简易化。把问题分解成子问题、模块直到整个问题简化到足够容易解决。其中形成了一种分层结构表示问题和子问题之间的关系，这种结构也称树形结构。<br>
设计算法时，写下主要步骤，定为主要模块，然后进一步开发第一层模块中的细节，如果这一层还是太复杂棘手，可以继续开发下一个模块，把每个任务扩展成最小的细节。被扩展的步骤是抽象步骤（abstract step），无需扩展的步骤便是具体步骤（concrete step）。<br>
<br>
简单例子<br>
–在编程时，如果要重复使用有某种功能的代码，那么一个很好的方法便是将其写成 一个函数，以便调用（前提是能用函数编写）。这个函数便是一个模块。
–对于编程中会出现的选择，循环结构，它们也是一个模块。

*自顶向下的方法可以总结为以下四个主要步骤：<br> 分析问题 编写主要模块 编写其余模块 根据需要进行重组和改写*<br>

* **“逐步求精”** <br>
是将现实世界的问题经抽象转化为逻辑空间或求解空间的问题。复杂问题经抽象化处理变为相对比较简单的问题。经若干步抽象（精化）处理，最后到求解域中只是比较简单的编程问题。

![](http://aliyunzixunbucket.oss-cn-beijing.aliyuncs.com/csdn/c48907e9-3ffd-4ba0-9087-aab092157881)


<h2 id="2">洗衣机案例</h2>

![](https://images-cn.ssl-images-amazon.com/images/I/51G06AGF6lL._AA200_.jpg)

将洗衣机的功能不断分解，进行以下分析：<br>
假设洗衣机可执行的基本操作如下：
water_in_switch(open_close) //open打开上水开关，close关闭<br>
water_out_switch(open_close) //open打开排水开关，close关闭<br>
get_water_volume() //返回洗衣机内部水的高度<br>
motor_run(direction) //点击转动。left左转，right右转，stop停<br>
timer_counter() //返回当前时间计数，以秒为单位<br>
halt(returncode) //停机，success成功failure失败
<br><br>

用伪代码分解“正常洗衣”程序的大步骤:<br>
>注水 -> 浸泡-> 转动洗衣-> 转动脱水-> 排水<br>
>>1）注水：洗衣机注入相应水量。 <br>
2）浸泡：衣物在水中浸泡一段时间。 <br>
3）洗涤：通过底部转盘旋转，直筒摇动使衣物与筒壁摩擦以达到洗涤的目的。 <br>
4）转动脱水(同时排水)：滚筒高速旋转，通过离心作用将衣物中残留水分甩出。<br>

<br>
water_in_switch(open）<br>
get_water_volume()<br>
water_in_switch(close)<br>
<br>
motorrun(left)<br>
motorrun(right)<br>
motorrun(stop)<br>
<br>
water_out_switch(open）<br>
motorrun(left)<br>
motorrun(right)<br>
motorrun(stop)<br>
<br>
get_water_volume()<br>
water_out_switch(close)<br>


进一步用伪代码描述基本的控制程序设计:<br>
>READ(water,timer)<br>
WHILE get_water_volume() < water<br>
  water_in_switch(open)<br>
ENDWHILE<br>
water_in_switch(close)<br>
<br>
WHILE nowtime <= timer<br>
	motorrun(left)<br>
	motorrun(right)<br>
	motorrun(stop)<br>
    IF get_water_volume() > 0 <br>
	    water_out_switch(open）<br>
        motorrun(left)<br>
        motorrun(right)<br>
        motorrun(stop)<br>
        IF get_water_volume() == 0<br>
            water_out_switch(close)<br>
        ENDIF<br>
    ENDIF<br>
