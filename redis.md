# Redis

## 数据类型

* string 

  ```
  > SET lushaohao "handsome"
  ```

* Hash

  ```
  > HMSET lushaohao tel "15521268375" sex "male"
  ```

* List

  ```
  > lpush lushaohao tencent
  > lpush lushaohao alibaba
  ```

* set

  ```
  > sadd lushaohao tencent
  > (integer) 0 
  > sadd lushaohao tencent
  > (integer) 1
  ```

  



## 缓存穿透，缓存击穿，缓存雪崩

* 缓存穿透
  * 查询一个不存在的数据，由于缓存是不命中时被动写的，多次查询不存在缓存的数据会导致缓存穿透。
  * 解决方法：布隆过滤器。将所有可能存在的数据哈希到一个足够大的bitmap中，一个一定不存在的数据会被这个bitmap拦截掉。
* 缓存雪崩
  * 缓存雪崩：设置缓存时采用相同的过期时间，导致缓存在某一时刻同时失效，请求全部转发到DB，DB瞬时压力过重雪崩。
  * 解决方法：在失效时间基础上增加一个随机值。
* 缓存击穿
  * 缓存在某个时间点过期，恰好这个时间点有大量并发请求过来。
  * 解决方法：互斥锁