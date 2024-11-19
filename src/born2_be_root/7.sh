ssh <user>@localhost -p 4242
shasum machinename.vdi

sudo crontab -e
sudo systemctl stop cron.service
sudo systemctl disable cron.service
sudo systemctl enable cron.service