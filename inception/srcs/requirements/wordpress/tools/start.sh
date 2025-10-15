#!/bin/bash
set -e

mkdir -p /run/php
chown -R www-data:www-data /run/php

if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Installing WordPress..."
    
    # Wait for MariaDB to be ready
    until wp db check --allow-root 2>/dev/null; do
        echo "Waiting for MariaDB to be ready..."
        sleep 3
    done
    
    # Download WordPress
    wp core download --path=/var/www/html --allow-root
    
    # Create wp-config.php
    wp config create \
        --dbname="$WORDPRESS_DB_NAME" \
        --dbuser="$WORDPRESS_DB_USER" \
        --dbpass="$WORDPRESS_DB_PASSWORD" \
        --dbhost="$WORDPRESS_DB_HOST" \
        --allow-root
    
    # Install WordPress
    wp core install \
        --url="$WORDPRESS_URL" \
        --title="$WORDPRESS_TITLE" \
        --admin_user="$WORDPRESS_ADMIN_USER" \
        --admin_password="$WORDPRESS_ADMIN_PASSWORD" \
        --admin_email="$WORDPRESS_ADMIN_EMAIL" \
        --skip-email \
        --allow-root
    
    # Create additional user (as required - 2 users total)
    wp user create "$WORDPRESS_USER" "$WORDPRESS_USER_EMAIL" \
        --role=editor \
        --user_pass="$WORDPRESS_USER_PASSWORD" \
        --allow-root
    
    chown -R www-data:www-data /var/www/html
    echo "WordPress installation completed!"
fi

echo "Starting PHP-FPM..."
exec php-fpm7.4 -F