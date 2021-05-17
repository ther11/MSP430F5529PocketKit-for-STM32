# MSP430F5529PocketKit-for-STM32
将MSP430F5529PocketKit移植到了STM32上面
## 说明
这里把MSP430F5529PocketKit的例程移植到STM32f103c8t6上，所有的驱动都经过测试，包括DAC7571，DRV8837，Eink电子墨水屏，INA210，TMP421
由于个人习惯问题，将i2c分别写在各自的驱动里，DAC的i2c函数名字前面加了个a，不然报错重复定义，有需要自行修改。
所有测试主函数均在temp目录下，主目录下的是临时文件，改名字替换主目录下的main即可
