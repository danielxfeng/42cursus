all: up

up:
	mkdir -p /home/xifeng/data/mariadb
	mkdir -p /home/xifeng/data/wordpress
	docker compose -f srcs/docker-compose.yml up -d --build

down:
	docker compose -f srcs/docker-compose.yml down

stop:
	docker compose -f srcs/docker-compose.yml stop

start:
	docker compose -f srcs/docker-compose.yml start

clean: down
	docker system prune -af
	sudo rm -rf /home/xifeng/data/mariadb/*
	sudo rm -rf /home/xifeng/data/wordpress/*

re: clean all
	docker compose -f srcs/docker-compose.yml rm -f
.PHONY: all up down stop start clean re
