FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y mariadb-server && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

RUN sed -i "s|^bind-address.*|bind-address = 0.0.0.0|" /etc/mysql/mariadb.conf.d/50-server.cnf && \
    sed -i "s|^#port.*|port = 3306|" /etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/start.sh /usr/local/bin/start.sh
RUN chmod +x /usr/local/bin/start.sh

EXPOSE 3306

ENTRYPOINT ["start.sh"]

CMD ["mysqld"]
