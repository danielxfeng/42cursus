#!/bin/bash
set -e

mkdir -p /run/php
chown -R www-data:www-data /run/php

if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Installing WordPress..."
    
    echo "Waiting for MariaDB to accept connections..."
    until mysql -h "$WORDPRESS_DB_HOST" -P "$WORDPRESS_DB_PORT" -u"$WORDPRESS_DB_USER" -p"$WORDPRESS_DB_PASSWORD" -e "SELECT 1;" >/dev/null 2>&1; do
        echo "MariaDB is unavailable - retrying in 3s..."
        sleep 3
    done
    echo "MariaDB is ready! Proceeding with WordPress setup..."

    rm -rf /var/www/html/*
    
    # Download WordPress
    echo "DEBUG: Downloading WordPress core..."
    wp core download --path=/var/www/html --allow-root
    echo "DEBUG: WordPress downloaded. Checking files..."
    ls -la /var/www/html | head -n 10
    
    # Create wp-config.php
    wp config create \
        --dbname="$WORDPRESS_DB_NAME" \
        --dbuser="$WORDPRESS_DB_USER" \
        --dbpass="$WORDPRESS_DB_PASSWORD" \
        --dbhost="$WORDPRESS_DB_HOST" \
        --allow-root
    wp db check --allow-root
    
    # Install WordPress
    wp core install \
        --url="$WORDPRESS_URL" \
        --title="$WORDPRESS_TITLE" \
        --admin_user="$WORDPRESS_ADMIN_USER" \
        --admin_password="$WORDPRESS_ADMIN_PASSWORD" \
        --admin_email="$WORDPRESS_ADMIN_EMAIL" \
        --skip-email \
        --allow-root
    wp core is-installed --allow-root && echo "WordPress is installed successfully!"
    
    # Create additional user (as required - 2 users total)
    wp user create "$WORDPRESS_USER" "$WORDPRESS_USER_EMAIL" \
        --role=editor \
        --user_pass="$WORDPRESS_USER_PASSWORD" \
        --allow-root
    wp user list --allow-root
    
    chown -R www-data:www-data /var/www/html
    echo "WordPress installation completed!"
fi

echo "Starting PHP-FPM..."
exec php-fpm7.4 -F