
###
 # @Author: ChengKeyi
 # @Date: 2024-03-15 10:58:38
 # @LastEditors: ChengKeyi
 # @LastEditTime: 2024-03-15 11:25:35
 # @FilePath: /Desktop/monitor/docker/scripts/mysql_run.sh
 # @Description: 
### 

#创建自定义网络
docker network create monitor

docker run -d \
 --name mysql \
 -p 3307:3306 \
 -e TZ=Asia/Shanghai \
 -e MYSQL_ROOT_PASSWORD=123456 \
 -v /home/ubuntu/Desktop/sqldata/sqlset/mysql/data:/var/lib/mysql \
 -v /home/ubuntu/Desktop/sqldata/sqlset/mysql/conf:/etc/mysql/conf.d \
 -v /home/ubuntu/Desktop/sqldata/sqlset/mysql/init:/docker-entrypoint-initdb.d \
 -v /home/ubuntu/Desktop/sqldata:/work\
 --network monitor \
 mysql