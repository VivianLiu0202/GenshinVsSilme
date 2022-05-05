#ifndef INIT_H
#define INIT_H

//初始化工作

//产生史莱姆的数量（也可以稍微修改一下定义战斗轮次）
#define SLIME_GEN_TIMES 30

//产生一个史莱姆需要一个变量从0累加到这个值（100就很快）
#define GEN_ONE_TIME 200

//初始化阳光值
#define INIT_SUN_NUM 500

//初始化卡片冷却时间
#define cooltime_Qiqi  150
#define cooltime_Venti 227
#define cooltime_Xiangling 606
#define cooltime_Zhongli    606
#define cooltime_Tartaglia 227
#define cooltime_Ganyu    227
#define cooltime_Klee   227//双发射手的冷却时间由227改为10


//植物的生命值和攻击力
#define hp_Zhongli 4000
#define hp_NormalYuanshen 300

#define atk_Xiangling 1800

#define atk_Venti 200
#define atk_Tartaglia 175
#define atk_Klee 200
#define atk_Ganyu 150


//史莱姆的生命值，攻击力，行走速度
#define hp_Anemo  640
#define hp_Cyro  600
#define hp_Eletro  700
#define hp_Grass  1000
#define hp_Pyro  700

#define atk_Slime  (100 * 33 / 1000)

#define speed_slime_1  (80.0 * 33 / 1000 / 4.7)
#define speed_slime_2  (80.0 * 33 / 1000 / 2.5)

#endif // INIT_H
