/*===============================================
# Author: lzjqsdd - lzj7179@163.com
# Last modified: 2017-06-02 22:56
# Filename: item18.cpp
# Description: 分期瘫痪期望的计算(over-eager evaluation)过度热情计算法
================================================*/

//举个例子，在一个容器中求最大最小值max,min
//(1)如果lazy evaluation的话，直到请求max,min的时候才计算
//而over-eager evaluation则是每次容器加入元素都更新max,min。只要有请求直接返回就可以
//如果是频繁的调用max，min，则可以把计算开销分摊在每一步跟踪维护的开销上。
//(2)caching方法，把常访问的cache起来，避免查库的开销
//(3)prefetching预提取
//
//over-evaluation主要用在频繁请求或者计算上，所以才会通过prefetch或者caching方法提前把结果准备好。
