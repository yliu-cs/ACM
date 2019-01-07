#include <bits/stdc++.h>

const int maxn = "Edit";

// Sum:线段树信息(此模板为求和)，Lazy:惰性标记
int Sum[maxn << 2], Lazy[maxn << 2];

// 更新节点信息，这里是求和
void PushUp(int Root) {
    Sum[Root] = Sum[Root << 1] + Sum[Root << 1 | 1];
}

// 下推标记函数，LeftNum，RightNum:分别为左右子树的数字数量
void PushDown(int Root, int LeftNum, int RightNum) {
    if (Lazy[Root]) {
        // 下推标记
        Lazy[Root << 1] += Lazy[Root];
        Lazy[Root << 1 | 1] += Lazy[Root];
        // 根据惰性标修改子节点的值
        Sum[Root << 1] += Lazy[Root] * LeftNum;
        Sum[Root << 1 | 1] += Lazy[Root] * RightNum;
        // 清除本节点惰性标记
        Lazy[Root] = 0;
    }
}

// 建树，Left、Right:当前节点区间，Root:当前节点编号
void Build(int Left, int Right, int Root) {
    Lazy[Root] = 0;
    // 到达叶子节点
    if (Left == Right) {
        scanf("%d", &Sum[Root]);
        return;
    }
    int Mid = (Left + Right) >> 1;
    // 左子树
    Build(Left, Mid, Root << 1);
    // 右子树
    Build(Mid + 1, Right, Root << 1 | 1);
    // 更新信息
    PushUp(Root);
}

// 单点修改，Pos:修改点位置，Value:修改值，Left、Right:当前区间，Root:当前节点编号
void PointUpdate(int Pos, int Value, int Left, int Right, int Root) {
    // 修改叶子节点
    if (Left == Right) {
        Sum[Root] += Value;
        return;
    }
    int Mid = (Left + Right) >> 1;
    // 根据条件判断调用左子树还是右子树
    if (Pos <= Mid) {
        PointUpdate(Pos, Value, Left, Mid, Root << 1);
    }
    else {
        PointUpdate(Pos, Value, Mid + 1, Right, Root << 1 | 1);
    }
    // 子节点更新后更新此节点
    PushUp(Root);
}

// 区间修改，OperateLeft、OperateRight:操作区间，Left、Right:当前区间，Root:当前节点编号
void IntervalUpdate(int OperateLeft, int OperateRight, int Value, int Left, int Right, int Root) {
    // 若本区间完全在操作区间内
    if (OperateLeft <= Left && OperateRight >= Right) {
        Sum[Root] += Value * (Right - Left + 1);
        // 增加惰性标记，表示本区间Sum正确，但子区间仍需要根据惰性标记调整更新
        Lazy[Root] += Value;
        return;
    }
    int Mid = (Left + Right) >> 1;
    // 下推标记
    PushDown(Root, Mid - Left + 1, Right - Mid);
    // 根据条件判断调用左子树还是右子树
    if (OperateLeft <= Mid) {
        IntervalUpdate(OperateLeft, OperateRight, Value, Left, Mid, Root << 1);
    }
    if (OperateRight > Mid) {
        IntervalUpdate(OperateLeft, OperateRight, Value, Mid + 1, Right, Root << 1 | 1);
    }
    // 更新当前节点信息
    PushUp(Root);
}

// 区间查询，OperateLeft、OperateRight:操作区间，Left、Right:当前区间，Root:当前节点编号
int Query(int OperateLeft, int OperateRight, int Left, int Right, int Root) {
    // 区间内直接返回
    if (OperateLeft <= Left && OperateRight >= Right) {
        return Sum[Root];
    }
    int Mid = (Left + Right) >> 1;
    // 下推标记
    PushDown(Root, Mid - Left + 1, Right - Mid);
    // 叠加结果
    int Ans = 0;
    if (OperateLeft <= Mid) {
        Ans += Query(OperateLeft, OperateRight, Left, Mid, Root << 1);
    }
    if (OperateRight > Mid) {
        Ans += Query(OperateLeft, OperateRight, Mid + 1, Right, Root << 1 | 1);
    }
    // 返回结果
    return Ans;
}
