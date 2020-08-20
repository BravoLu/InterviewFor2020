* OHEM

![pic](OHEM.jpg)

1. 两个ROI网络，上面那个ROI网络用来计算HARD EXAMPLE， 每次更新下面的ROI网络然后将权重赋给上面的。
2. 难样计算方法：计算ROI损失，用NMS去掉重复的，然后排序，去前N个。

* Anchor Free

* SPPNet



* Faster RCNN

1. anchor的positives设置：1. 与GT值IoU最大的anchor 2. IoU值>0.7的anchor

![pic](rpn_loss.jpg)

2. ![pic](参数.jpg)

3. bounding box回归perform在不同大小的ROI上。

4. 训练时，忽视超出边界的框（20000->6000）。测试时，Crop超出边oU界的框

5. yolo输出的参数是SXSX(B*(4+1)+C)即每个格子预测一个为同一个类，用5个boundingbox来回归，每个boundingbox类相同。

   yolov3输出的参数是SXSX(3*(C+4+1)) 每个格子预测3个boundingbox, 每个boundingbox类不同。（跟SSD相似，只是SSD为SXSX(Bx((C+1)+4))将背景也当成一个类，而yolov3则是会输出一个置信度，置信度=类别概率XIoU， gt值就是IoU.

6. yolo后面的两个fc层是用1x1conv实现的。