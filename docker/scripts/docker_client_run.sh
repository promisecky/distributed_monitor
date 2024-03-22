#!/usr/bin/env bash
###
 # @Author: ChengKeyi
 # @Date: 2024-03-10 23:36:50
 # @LastEditors: ChengKeyi
 # @LastEditTime: 2024-03-22 10:42:52
 # @FilePath: /Desktop/monitor/docker/scripts/docker_client_run.sh
 # @Description: 
### 

MONITOR_HOME_DIR="$(cd "$(dirname ${BASH_SOURCE[0]})/../.." && pwd)"

local_host="$(hostname)"
user="${USER}"
uid="$(id -u)"
group="$(id -g -n)"
gid="$(id -g)"
HOST_IP=$(ip addr show ens33 | grep 'inet ' | awk '{print $2}' | cut -f1 -d'/')
HOST_MAC=$(ip link show ens33 | awk '/ether/ {print $2}')


echo "stop and rm docker" 
docker stop learn_monitor > /dev/null
docker rm -v -f learn_monitor > /dev/null

echo "start docker"
# docker run -it -d \
docker run -it -d \
--name client_monitor \
-e DISPLAY=$display \
-p 50001:50001 \
--privileged=true \
-e DOCKER_USER="${user}" \
-e USER="${user}" \
-e DOCKER_USER_ID="${uid}" \
-e DOCKER_GRP="${group}" \
-e DOCKER_GRP_ID="${gid}" \
-e XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR \
-e HOST_IP="${HOST_IP}" \
-e HOST_MAC="${HOST_MAC}" \
-v ${MONITOR_HOME_DIR}:/work \
-v ${XDG_RUNTIME_DIR}:${XDG_RUNTIME_DIR} \
--net=network1 \
learn_monitor:latest