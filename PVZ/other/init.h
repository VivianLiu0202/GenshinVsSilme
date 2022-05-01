#ifndef INIT_H
#define INIT_H

//初始化工作

//产生僵尸的数量（也可以稍微修改一下定义战斗轮次）
#define SLIME_GEN_TIMES 50

//产生一个僵尸需要一个变量从0累加到这个值（100就很快）
#define GEN_ONE_TIME 100

//初始化阳光值
#define INIT_SUN_NUM 10000

//初始化卡片冷却时间
#define cooltime_Qiqi  200
#define cooltime_Venti 227
#define cooltime_Xiangling 606
#define cooltime_Zhongli    606
#define cooltime_Tartaglia 606
#define cooltime_Ganyu    227
#define cooltime_Klee   227//双发射手的冷却时间由227改为10


//植物的生命值和攻击力
#define hp_Zhongli 4000
#define hp_NormalYuanshen 300

#define atk_Xiangling 1800
#define atk_Tartaglia 1800

#define atk_Venti 25
#define atk_Klee 50
#define atk_Ganyu 25


//僵尸的生命值，攻击力，行走速度
#define hp_BasicZombie  270
#define hp_ConeZombie  640
#define hp_ScreenZombie  1370
#define hp_BucketZombie  1370
#define hp_FootballZombie  1670

#define atk_Zombie  (100 * 33 / 1000)

#define speed_zombie_1  (80.0 * 33 / 1000 / 4.7)
#define speed_zombie_2  (80.0 * 33 / 1000 / 2.5)

#endif // INIT_H
