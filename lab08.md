# lab08-“方块世界”游戏设计

*注：由于作者使用mbp的不便，本文使用construct3做演示，其操作基本相同*<br>
*本文章同时发布在[CSDN平台](https://blog.csdn.net/sinat_41918479/article/details/82891077)* ，欢迎支持。

## 游戏展示
![bad guy died. ](https://img-blog.csdn.net/2018092821302384?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxOTE4NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
![player died. ](https://img-blog.csdn.net/2018092821303825?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxOTE4NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)<br>
*注：由于construct3免费版只能创建两层layout，所以未能实现结束标志及记分等功能，不过简单了解完construct2后，这些操作都变得简单了，大家可以自己探索。*

## 游戏策划
 **游戏背景**：<br>
 在矩形世界中，所有的生物都以矩形快乐地生存着。然而有一天，一群圆形的异端邪恶势力侵入了矩形世界。矩形生物们大惊失色四处逃窜。然而这时，能够拯救矩形世界的特殊存在出现了！他由矩形构成，却在脑后有着一圈弧形白色光环，他能够通过发射矩形子弹使圆形邪恶势力消失！战争，一触即发！
 <br>

**人设与道具**：<br>
* Player（救世主）：拥有三点血，可发射子弹攻击敌人，每颗子弹可造成1点伤害，每被敌人接触一次掉一点血，血量小于等于0即死亡同时游戏结束；
* Enemy：拥有六点血，接触会对player造成1点伤害，player发射的子弹可对其造成1点伤害，血量小于等于0即死亡。

## 游戏设计&制作
### 下载安装游戏

> [Construct](https://www.construct.net/cn) 点击进入官网进行下载安装，或使用construct3网页版。

### 创建项目
![newproject](https://img-blog.csdn.net/2018092821480562?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxOTE4NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)<br>

创建好后进入游戏制作界面如下：
![mainpage](https://img-blog.csdn.net/20180928215415440?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxOTE4NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
_注意图中左栏的viewport size，即中间部分虚线框的大小_
### 布局、背景及人物图层等的创建
界面的大小及操作部分的大小由游戏制作者视情况而定，游戏背景的大小在右栏中选择layout后再在左栏进行改动。作者在这里将所有的大小设置成一样的，使游戏效果为游戏过程可视部分即为游戏地图的全部大小。如下图：
![layout](https://img-blog.csdn.net/20180928220234262?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxOTE4NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)<br>

接下来就要开始制作游戏啦！<br>
首先创建背景及出场角色 _(player、bad guy、bullet、boom)_，作者选择了自己绘制，当然也可以在网上下载素材包导入，不过要注意版权问题喔！具体绘制／导入方法为，双击背景，insert Tiled Background或Sprite（背景或角色）；然后进入角色创建界面，进行绘制或在上方功能栏插入图片，创建好后 关闭即可。
![newcharacters](https://img-blog.csdn.net/20180928220645227?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxOTE4NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)<br>

然后将创建好的背景及角色分别命名以便后续操作，之后拖动背景并调整其大小布局。创建完背景后，**记得在右边栏中创建新的图层，并分别命名，锁定背景图层，选中main图层后进行后续操作**，如下图：
![layout](https://img-blog.csdn.net/2018092822133942?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxOTE4NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)<br>

<strong>Tips：角色创建不用clone多个角色，按住ctrl键（MacOS为command）拖动角色即可。</strong>
### 人物属性行为等
右键角色可以看到角色有很多属性可以选择，读者可自己探索其功能。这里简单介绍作者所使用的几个属性特征。本游戏对player主要使用了instance variables以及behaviors。在左侧可对其细节进行修改，如速度等。
![player](https://img-blog.csdn.net/20180928222050221?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxOTE4NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)<br>

8Direction即为角色可通过键盘操作朝八个方向移动，BoundToLayout即为限制player在设置好的背景范围内移动。
在instance variables中作者对player设置了数值为3的hp（血量）。
![player](https://img-blog.csdn.net/20180928222059334?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxOTE4NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
_游戏中作者还使用了bullet等行为。_<br>
其他功能读者可自己探索，建议每添加一个功能便预览一次以减少错误。
### 创建事件
游戏的主要功能实现是通过events的。在中间栏上方点击Event sheet即可进行事件操作。如图所示，是本游戏所使用的全部events。读者可以先自己尝试理解并操作一下。
![new events](https://img-blog.csdn.net/20180928223041192?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxOTE4NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)<br>
events的操作简单介绍如下：<br>
首先add event，选中操作对象（system或游戏角色等），接下来根据指引选择条件（condition），即event触发的条件。创建完成后创建action，类似的操作，选择action对应的角色以及行为。construct2提供了很多功能，读者们都可以尝试一下。而我所使用的几种，也可以很简单的从字面理解，就不多做解释了。
<br>
用CRC（Class-Responsibility-Collaboration）卡片方法简单整理以上内容如下例所示：
<br>

|Object|bullet  |
|:--|:--|
| Attributes | 图片、位置 |
| Collaborator| bad guy（敌人） |
| Events & Actions |碰撞伤害敌人－1hp |


|Object|player（玩家） |
|:--|:--|
| Attributes | 图片、hp（血量）、位置 |
| Collaborator| bad guy（敌人） |
| Events & Actions |碰撞使自己收到伤害－1hp|


|Object|bad guy（敌人）  |
|:--|:--|
| Attributes | 图片、hp（血量）、位置 |
| Collaborator| player（玩家操控的角色） |
| Events & Actions |碰撞伤害玩家－1hp |


## 总结
Construct2/3是一个功能强大、无需编程的简单游戏制作软件，通过大致了解后用户即可上手制作小游戏。不过其功能颇多，还需要大家不断探索，制作更精良的游戏。
<br><br><br><br><br>





注：*由于在之前已经将游戏制作实验完成，并将博客与第一次游戏制作的博客合并，因此本次lab就将其copy过来*