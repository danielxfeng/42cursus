FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y \
        php7.4-fpm \
        php7.4-mysql \
        php7.4-zip \
        php7.4-gd \
        php7.4-mbstring \
        php7.4-curl \
        php7.4-xml \
        curl \
        wget \
        mariadb-client \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

RUN chown -R www-data:www-data /var/www/html

RUN sed -i "s|listen = /run/php/php7.4-fpm.sock|listen = 9000|" /etc/php/7.4/fpm/pool.d/www.conf

COPY tools/start.sh /usr/local/bin/start.sh
RUN chmod +x /usr/local/bin/start.sh

EXPOSE 9000

ENTRYPOINT ["start.sh"]