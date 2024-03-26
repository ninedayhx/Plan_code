# 判断点A在离散曲线的哪边
- step1 找到离目标点最近的离散曲线的点的下标index
- step2 扩散alpha个步长，选取下标为index+alpha的作为点p1，选取下表为index-alpha的点作为p2
- step3 计算向量A->p1 = vec1, 计算向量 p2->p1 = vec2
- step3 若 vec2×vec1 > 0 点在右边 < 0在左边 =0在曲线上

>注意，如果离散曲线的步长太大，即精度较低，则需要对曲线进行拟合
