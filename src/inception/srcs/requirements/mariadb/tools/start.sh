#!/bin/bash
set -e

chown -R mysql:mysql /var/lib/mysql

if [ ! -d /var/lib/mysql/mysql ]; then
    echo "MariaDB initializing database..."
    mysql_install_db --user=mysql --ldata=/var/lib/mysql > /dev/null

    echo "Running bootstrap SQL via mysqld --bootstrap"

    cat <<EOF | mysqld --bootstrap --user=mysql --skip-grant-tables=OFF
USE mysql;
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    echo "MariaDB bootstrap complete."
fi

echo "Starting MariaDB..."
exec "$@"